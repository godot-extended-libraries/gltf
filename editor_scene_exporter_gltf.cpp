/*************************************************************************/
/*  editor_scene_saver_gltf.cpp                                          */
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

#include "editor_scene_exporter_gltf.h"
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

#ifndef _3D_DISABLED
void SceneExporterGLTF::save_scene(Node *p_node, const String &p_path, const String &p_src_path, uint32_t p_flags, int p_bake_fps, List<String> *r_missing_deps, Error *r_err) {
	Error err = FAILED;
	if (r_err) {
		*r_err = err;
	}
	Vector<CSGShape *> csg_items;
	_find_all_csg_roots(csg_items, p_node, p_node);

	Vector<GridMap *> grid_map_items;
	_find_all_gridmaps(grid_map_items, p_node, p_node);

	Vector<MultiMeshInstance *> multimesh_items;
	_find_all_multimesh_instance(multimesh_items, p_node, p_node);

	Vector<MeshInfo> meshes;

	for (int32_t multimesh_i = 0; multimesh_i < multimesh_items.size(); multimesh_i++) {
		Ref<MultiMesh> mesh = multimesh_items[multimesh_i]->get_multimesh();
		if (mesh.is_null()) {
			continue;
		}
		for (int32_t instance_i = 0; instance_i < mesh->get_instance_count(); instance_i++) {
			MeshInfo mesh_info;
			mesh_info.mesh = mesh->get_mesh();
			if (mesh->get_transform_format() == MultiMesh::TRANSFORM_2D) {
				Transform2D xform_2d = mesh->get_instance_transform_2d(instance_i);
				mesh_info.transform.origin = Vector3(xform_2d.get_origin().x, 0, xform_2d.get_origin().y);
				real_t rotation = xform_2d.get_rotation();
				Quat quat;
				quat.set_axis_angle(Vector3(0, 1, 0), rotation);
				Size2 scale = xform_2d.get_scale();
				mesh_info.transform.basis.set_quat_scale(quat, Vector3(scale.x, 0, scale.y));
				mesh_info.transform = multimesh_items[multimesh_i]->get_transform() * mesh_info.transform;
			} else if (mesh->get_transform_format() == MultiMesh::TRANSFORM_3D) {
				mesh_info.transform = multimesh_items[multimesh_i]->get_transform() * mesh->get_instance_transform(instance_i);
			}
			mesh_info.original_parent = multimesh_items[multimesh_i]->get_parent();
			mesh_info.name = multimesh_items[multimesh_i]->get_name();
			meshes.push_back(mesh_info);
		}
	}

	for (int32_t i = 0; i < csg_items.size(); i++) {
		Array mesh_arr = csg_items[i]->get_meshes();
		if (!mesh_arr.size()) {
			continue;
		}
		Ref<Mesh> mesh = mesh_arr[1];
		MeshInfo mesh_info;
		for (int32_t material_i = 0; material_i < mesh->get_surface_count(); material_i++) {
			mesh_info.materials.push_back(mesh->surface_get_material(material_i));
		}
		if (csg_items[i]->get_material_override().is_valid()) {
			mesh_info.materials.clear();
			for (int32_t material_i = 0; material_i < mesh->get_surface_count(); material_i++) {
				mesh_info.materials.push_back(csg_items[i]->get_material_override());
			}
		}
		mesh_info.transform = csg_items[i]->get_transform();
		mesh_info.mesh = mesh;
		mesh_info.name = csg_items[i]->get_name();
		mesh_info.original_node = csg_items[i];
		meshes.push_back(mesh_info);
	}
	for (int32_t i = 0; i < grid_map_items.size(); i++) {
		Array cells = grid_map_items[i]->get_used_cells();
		for (int32_t k = 0; k < cells.size(); k++) {
			Vector3 cell_location = cells[k];
			int32_t cell = grid_map_items[i]->get_cell_item(cell_location.x, cell_location.y, cell_location.z);
			MeshInfo mesh_info;
			Ref<Mesh> mesh = grid_map_items[i]->get_mesh_library()->get_item_mesh(cell);
			for (int32_t material_i = 0; material_i < mesh->get_surface_count(); material_i++) {
				mesh_info.materials.push_back(mesh->surface_get_material(material_i));
			}
			mesh_info.mesh = mesh;
			Transform cell_xform;
			cell_xform.basis.set_orthogonal_index(grid_map_items[i]->get_cell_item_orientation(cell_location.x, cell_location.y, cell_location.z));
			cell_xform.basis.scale(Vector3(grid_map_items[i]->get_cell_scale(), grid_map_items[i]->get_cell_scale(), grid_map_items[i]->get_cell_scale()));
			cell_xform.set_origin(grid_map_items[i]->map_to_world(cell_location.x, cell_location.y, cell_location.z));
			mesh_info.transform = cell_xform * grid_map_items[i]->get_transform();
			mesh_info.name = grid_map_items[i]->get_mesh_library()->get_item_name(cell);
			mesh_info.original_parent = grid_map_items[i]->get_parent();
			meshes.push_back(mesh_info);
		}
	}

	for (int32_t i = 0; i < meshes.size(); i++) {
		MeshInstance *mi = memnew(MeshInstance);
		mi->set_mesh(meshes[i].mesh);
		for (int32_t j = 0; j < meshes[i].materials.size(); j++) {
			mi->set_surface_material(j, meshes[i].materials[j]);
		}
		mi->set_name(meshes[i].name);
		mi->set_transform(meshes[i].transform);
		if (meshes[i].original_parent) {
			meshes[i].original_parent->add_child(mi);
			mi->set_owner(p_node);
		} else if (meshes[i].original_node) {
			meshes[i].original_node->replace_by(mi);
		} else {
			p_node->add_child(mi);
			mi->set_owner(p_node);
		}
	}

	Ref<GLTFDocument> gltf_document;
	gltf_document.instance();

	GLTFDocument::GLTFState state;
	const GLTFDocument::GLTFNodeIndex scene_root = 0;
	gltf_document->_convert_scene_node(state, p_node, p_node, scene_root, scene_root);
	gltf_document->_convert_mesh_instances(state);
	gltf_document->_convert_skeletons(state);
	state.scene_name = p_node->get_name();
	err = gltf_document->serialize(state, p_path);
	if (r_err) {
		*r_err = err;
	}
}

void SceneExporterGLTF::_find_all_multimesh_instance(Vector<MultiMeshInstance *> &r_items, Node *p_current_node, const Node *p_owner) {
	MultiMeshInstance *multimesh = Object::cast_to<MultiMeshInstance>(p_current_node);
	if (multimesh != NULL) {
		r_items.push_back(multimesh);
	}
	for (int32_t i = 0; i < p_current_node->get_child_count(); i++) {
		_find_all_multimesh_instance(r_items, p_current_node->get_child(i), p_owner);
	}
}

void SceneExporterGLTF::_find_all_gridmaps(Vector<GridMap *> &r_items, Node *p_current_node, const Node *p_owner) {
	GridMap *gridmap = Object::cast_to<GridMap>(p_current_node);
	if (gridmap != NULL) {
		r_items.push_back(gridmap);
	}
	for (int32_t i = 0; i < p_current_node->get_child_count(); i++) {
		_find_all_gridmaps(r_items, p_current_node->get_child(i), p_owner);
	}
}

void SceneExporterGLTF::_find_all_csg_roots(Vector<CSGShape *> &r_items, Node *p_current_node, const Node *p_owner) {
	CSGShape *csg = Object::cast_to<CSGShape>(p_current_node);
	if (csg && csg->is_root_shape()) {
		r_items.push_back(csg);
	}
	for (int32_t i = 0; i < p_current_node->get_child_count(); i++) {
		_find_all_csg_roots(r_items, p_current_node->get_child(i), p_owner);
	}
}
#endif
