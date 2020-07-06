/*************************************************************************/
/*  editor_scene_importer_gltf.cpp                                       */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "editor_scene_importer_gltf.h"
#include "core/crypto/crypto_core.h"
#include "core/io/json.h"
#include "core/math/disjoint_set.h"
#include "core/math/math_defs.h"
#include "core/os/file_access.h"
#include "core/os/os.h"
#include "editor/import/resource_importer_scene.h"
#include "modules/regex/regex.h"
#include "scene/3d/bone_attachment.h"
#include "scene/3d/camera.h"
#include "scene/3d/mesh_instance.h"
#include "scene/animation/animation_player.h"
#include "scene/resources/packed_scene.h"
#include "scene/resources/surface_tool.h"

#ifndef _3D_DISABLED
#ifdef TOOLS_ENABLED
uint32_t EditorSceneImporterGLTF::get_import_flags() const {

	return IMPORT_SCENE | IMPORT_ANIMATION;
}
void EditorSceneImporterGLTF::get_extensions(List<String> *r_extensions) const {

	r_extensions->push_back("gltf");
	r_extensions->push_back("glb");
}

Node *EditorSceneImporterGLTF::import_scene(const String &p_path,
		uint32_t p_flags, int p_bake_fps,
		List<String> *r_missing_deps,
		Error *r_err) {

	Ref<PackedSceneGLTF> importer;
	importer.instance();
	return importer->import_scene(p_path, p_flags, p_bake_fps, r_missing_deps,
			r_err);
}

Ref<Animation> EditorSceneImporterGLTF::import_animation(const String &p_path,
		uint32_t p_flags,
		int p_bake_fps) {

	return Ref<Animation>();
}

EditorSceneImporterGLTF::EditorSceneImporterGLTF() {}

#endif
void PackedSceneGLTF::_bind_methods() {
	ClassDB::bind_method(
			D_METHOD("export_gltf", "node", "path", "flags", "bake_fps"),
			&PackedSceneGLTF::export_gltf, DEFVAL(0), DEFVAL(1000.0f));
	ClassDB::bind_method(D_METHOD("pack_gltf", "path", "flags", "bake_fps"),
			&PackedSceneGLTF::pack_gltf, DEFVAL(0), DEFVAL(1000.0f));
}

void PackedSceneGLTF::_save_thread_function(void *p_user) {
	Dictionary *user_data = (Dictionary *)p_user;
	Node *node = (*user_data)["scene"];
	List<String> deps;
	Error err;
	String path = (*user_data)["path"];
	int32_t flags = (*user_data)["flags"];
	real_t baked_fps = (*user_data)["bake_fps"];
	Ref<PackedSceneGLTF> exporter;
	exporter.instance();
	exporter->save_scene(node, path, "", flags, baked_fps, &deps, &err);
	(*user_data)["error"] = err;
	Ref<PackedSceneGLTF> self_exporter = (*user_data)["self"];
	self_exporter->save_thread = NULL;
}

Node *PackedSceneGLTF::import_scene(const String &p_path, uint32_t p_flags,
		int p_bake_fps,
		List<String> *r_missing_deps,
		Error *r_err) {
	GLTFDocument::GLTFState state;
	state.use_named_skin_binds =
			p_flags & EditorSceneImporter::IMPORT_USE_NAMED_SKIN_BINDS;

	Ref<GLTFDocument> gltf_document;
	gltf_document.instance();
	Error err = gltf_document->parse(&state, p_path);
	*r_err = err;
	ERR_FAIL_COND_V(err != Error::OK, NULL);

	Spatial *root = memnew(Spatial);

	for (int i = 0; i < state.root_nodes.size(); ++i) {
		gltf_document->_generate_scene_node(state, root, root, state.root_nodes[i]);
	}

	gltf_document->_process_mesh_instances(state, root);
	if (state.animations.size()) {
		AnimationPlayer *ap = memnew(AnimationPlayer);
		Node *new_root = root->get_child(0);
		new_root->add_child(ap);
		ap->set_owner(root);
		for (int i = 0; i < state.animations.size(); i++) {
			gltf_document->_import_animation(state, ap, i, p_bake_fps);
		}
	}

	return Object::cast_to<Spatial>(root);
}

void PackedSceneGLTF::pack_gltf(String p_path, int32_t p_flags,
		real_t p_bake_fps) {
	Error err = FAILED;
	List<String> deps;
	Node *root = import_scene(p_path, p_flags, p_bake_fps, &deps, &err);
	ERR_FAIL_COND(err != OK);
	pack(root);
}

PackedSceneGLTF::PackedSceneGLTF() {}

#endif //_3D_DISABLED

#ifndef _3D_DISABLED
void PackedSceneGLTF::save_scene(Node *p_node, const String &p_path,
		const String &p_src_path, uint32_t p_flags,
		int p_bake_fps, List<String> *r_missing_deps,
		Error *r_err) {
	Error err = FAILED;
	if (r_err) {
		*r_err = err;
	}
	Ref<GLTFDocument> gltf_document;
	gltf_document.instance();
	GLTFDocument::GLTFState state;
	const GLTFDocument::GLTFNodeIndex scene_root = 0;
	gltf_document->_convert_scene_node(state, p_node->get_child(0), p_node,
			scene_root, scene_root);
	gltf_document->_convert_mesh_instances(state);
	gltf_document->_convert_skeletons(state);
	err = gltf_document->serialize(state, p_path);
	if (r_err) {
		*r_err = err;
	}
}

Error PackedSceneGLTF::export_gltf(Node *p_root, String p_path,
		int32_t p_flags /*= 0*/,
		real_t p_bake_fps /*= 1000.0f*/) {
	if (save_thread) {
		return ERR_BUSY;
	}
	ERR_FAIL_COND_V(p_root == NULL, FAILED);
	user_data["scene"] = p_root->duplicate();
	user_data["path"] = p_path;
	user_data["flags"] = p_flags;
	user_data["bake_fps"] = p_bake_fps;
	user_data["error"] = FAILED;
	user_data["self"] = Ref<PackedSceneGLTF>(this);
	Ref<PackedSceneGLTF> exporter;
	exporter.instance();
	save_thread = Thread::create(_save_thread_function, &user_data);
	int32_t error_code = user_data["error"];
	if (error_code != 0) {
		return Error(error_code);
	}
	return OK;
}

#endif
