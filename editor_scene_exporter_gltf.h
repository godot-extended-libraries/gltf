/*************************************************************************/
/*  editor_scene_exporter_gltf.h                                         */
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

#include "core/object.h"
#include "core/project_settings.h"
#include "core/vector.h"
#include "editor/editor_plugin.h"
#include "modules/csg/csg_shape.h"
#include "modules/gridmap/grid_map.h"
#include "scene/3d/mesh_instance.h"
#include "scene/3d/multimesh_instance.h"
#include "scene/gui/check_box.h"
#include "scene/main/node.h"
#include "scene/resources/packed_scene.h"
#include "scene/resources/surface_tool.h"

#ifndef EDITOR_SCENE_EXPORTER_GLTF_H
#define EDITOR_SCENE_EXPORTER_GLTF_H

#ifndef _3D_DISABLED
class SceneExporterGLTF : public Reference {

	GDCLASS(SceneExporterGLTF, Reference);

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

protected:
	static void _bind_methods() {
		ClassDB::bind_method(D_METHOD("export_gltf", "node", "path", "flags", "bake_fps"), &SceneExporterGLTF::export_gltf, DEFVAL(0), DEFVAL(1000.0f));
	}

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
		user_data["self"] = Ref<SceneExporterGLTF>(this);
		Ref<SceneExporterGLTF> exporter;
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
		Ref<SceneExporterGLTF> exporter;
		exporter.instance();
		exporter->save_scene(node, path, "", flags, baked_fps, &deps, &err);
		(*user_data)["error"] = err;
		Ref<SceneExporterGLTF> self_exporter = (*user_data)["self"];
		self_exporter->save_thread = NULL;
	}

	SceneExporterGLTF() {
	}
};

#endif
#endif