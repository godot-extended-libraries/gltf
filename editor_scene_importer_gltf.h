/*************************************************************************/
/*  editor_scene_importer_gltf.h                                         */
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

#ifndef EDITOR_SCENE_IMPORTER_GLTF_H
#define EDITOR_SCENE_IMPORTER_GLTF_H

#include "core/io/json.h"
#include "core/object.h"
#include "core/project_settings.h"
#include "core/vector.h"
#include "gltf_document.h"
#include "modules/csg/csg_shape.h"
#include "modules/gridmap/grid_map.h"
#include "scene/3d/mesh_instance.h"
#include "scene/3d/multimesh_instance.h"
#include "scene/animation/animation_player.h"
#include "scene/gui/check_box.h"
#include "scene/main/node.h"
#include "scene/resources/packed_scene.h"
#include "scene/resources/surface_tool.h"
#include "editor/import/resource_importer_scene.h"
#include "gltf_document.h"
#include "scene/3d/skeleton.h"
#include "scene/3d/spatial.h"
#include "scene/resources/packed_scene.h"

#ifndef _3D_DISABLED
class AnimationPlayer;
class BoneAttachment;
class MeshInstance;

#ifdef TOOLS_ENABLED
class EditorSceneImporterGLTF : public EditorSceneImporter {

	GDCLASS(EditorSceneImporterGLTF, EditorSceneImporter);

public:
	virtual uint32_t get_import_flags() const;
	virtual void get_extensions(List<String> *r_extensions) const;
	virtual Node *import_scene(const String &p_path, uint32_t p_flags, int p_bake_fps, List<String> *r_missing_deps = NULL, Error *r_err = NULL);
	virtual Ref<Animation> import_animation(const String &p_path, uint32_t p_flags, int p_bake_fps);

	EditorSceneImporterGLTF();
};
#endif

class PackedSceneGLTF : public PackedScene {

	GDCLASS(PackedSceneGLTF, PackedScene);

protected:
	static void _bind_methods();

private:
	struct MeshInfo {
		Transform transform;
		Ref<Mesh> mesh;
		String name;
		Vector<Ref<Material> > materials;
		Node *original_node = NULL;
		Node *original_parent = NULL;
	};
	void _find_all_multimesh_instance(Vector<MultiMeshInstance *> &r_items, Node *p_current_node, const Node *p_owner);
	void _find_all_gridmaps(Vector<GridMap *> &r_items, Node *p_current_node, const Node *p_owner);
	void _find_all_csg_roots(Vector<CSGShape *> &r_items, Node *p_current_node, const Node *p_owner);
	Thread *save_thread = NULL;
	Dictionary user_data;

public:
	void save_scene(Node *p_node, const String &p_path, const String &p_src_path, uint32_t p_flags, int p_bake_fps, List<String> *r_missing_deps, Error *r_err = NULL);
	Error export_gltf(Node *p_root, String p_path, int32_t p_flags = 0, real_t p_bake_fps = 1000.0f) {
		if (save_thread) {
			return ERR_BUSY;
		}
		Ref<PackedScene> packed_scene;
		packed_scene.instance();
		ERR_FAIL_COND_V(p_root == NULL, FAILED);
		packed_scene->pack(p_root);
		user_data["scene"] = packed_scene;
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

	static void
	_save_thread_function(void *p_user) {
		Dictionary *user_data = (Dictionary *)p_user;
		Ref<PackedScene> scene = (*user_data)["scene"];
		List<String> deps;
		Error err;
		Node *node = scene->instance();
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
	Node *import_scene(const String &p_path, uint32_t p_flags, int p_bake_fps, List<String> *r_missing_deps, Error *r_err);	
	void pack_gltf(String p_path, int32_t p_flags = 0, real_t p_bake_fps = 1000.0f);
	PackedSceneGLTF() {}
};

#endif // _3D_DISABLED
#endif // EDITOR_SCENE_IMPORTER_GLTF_H
