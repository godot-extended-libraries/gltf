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

Node *EditorSceneImporterGLTF::import_scene(const String &p_path, uint32_t p_flags, int p_bake_fps, List<String> *r_missing_deps, Error *r_err) {

	Ref<SceneImporterGLTF> importer;
	importer.instance();
	return importer->import_scene(p_path, p_flags, p_bake_fps, r_missing_deps, r_err);
}

Ref<Animation> EditorSceneImporterGLTF::import_animation(const String &p_path, uint32_t p_flags, int p_bake_fps) {

	return Ref<Animation>();
}

EditorSceneImporterGLTF::EditorSceneImporterGLTF() {
}

#endif
void SceneImporterGLTF::_bind_methods() {
	ClassDB::bind_method(D_METHOD("import_gltf", "path", "flags", "bake_fps"), &SceneImporterGLTF::import_gltf, DEFVAL(0), DEFVAL(1000.0f));
}

Node *SceneImporterGLTF::import_scene(const String &p_path, uint32_t p_flags, int p_bake_fps, List<String> *r_missing_deps, Error *r_err) {
	GLTFDocument::GLTFState state;
	state.use_named_skin_binds = p_flags & EditorSceneImporter::IMPORT_USE_NAMED_SKIN_BINDS;

	Ref<GLTFDocument> gltf_document;
	Error err = gltf_document->parse(&state, p_path);
	*r_err = err;
	ERR_FAIL_COND_V(err != Error::OK, NULL);

	Spatial *root = memnew(Spatial);

	// scene_name is already unique
	root->set_name(state.scene_name);

	for (int i = 0; i < state.root_nodes.size(); ++i) {
		gltf_document->_generate_scene_node(state, root, root, state.root_nodes[i]);
	}

	gltf_document->_process_mesh_instances(state, root);

	if (state.animations.size()) {
		AnimationPlayer *ap = memnew(AnimationPlayer);
		root->get_child(0)->add_child(ap);
		ap->set_owner(root);

		for (int i = 0; i < state.animations.size(); i++) {
			gltf_document->_import_animation(state, ap, i, p_bake_fps);
		}
	}
	Map<Node *, Node *> reown;
	Node *base = root->get_child(0);
	ERR_FAIL_COND_V(!base, NULL);
	reown[root] = base;
	return Object::cast_to<Spatial>(base->duplicate_and_reown(reown));
}

Node *SceneImporterGLTF::import_gltf(String p_path, int32_t p_flags, real_t p_bake_fps) {
	Error err = FAILED;
	List<String> deps;
	Node *root = import_scene(p_path, p_flags, p_bake_fps, &deps, &err);
	ERR_FAIL_COND_V(err != OK, NULL);
	return root;
}

#endif //_3D_DISABLED