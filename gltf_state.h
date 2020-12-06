/*************************************************************************/
/*  gltf_state.h                                                         */
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

#ifndef GLTF_STATE_H
#define GLTF_STATE_H

#include "core/io/resource.h"
#include "core/templates/vector.h"
#include "core/variant/variant_conversion.h"
#include "gltf_accessor.h"
#include "gltf_animation.h"
#include "gltf_buffer_view.h"
#include "gltf_camera.h"
#include "gltf_document.h"
#include "gltf_light.h"
#include "gltf_mesh.h"
#include "gltf_node.h"
#include "gltf_skeleton.h"
#include "gltf_skin.h"
#include "gltf_texture.h"
#include "scene/animation/animation_player.h"
#include "scene/resources/texture.h"

class GLTFState : public Resource {
	GDCLASS(GLTFState, Resource);

protected:
	static void _bind_methods();

public:
	Dictionary json;
	int major_version;
	int minor_version;
	Vector<uint8_t> glb_data;

	bool use_named_skin_binds;

	Vector<Ref<GLTFNode>> nodes;
	Vector<Vector<uint8_t>> buffers;
	Vector<Ref<GLTFBufferView>> buffer_views;
	Vector<Ref<GLTFAccessor>> accessors;

	Vector<Ref<GLTFMesh>> meshes; // meshes are loaded directly, no reason not to.

	Vector<AnimationPlayer *> animation_players;
	Map<Ref<Material>, GLTFMaterialIndex> material_cache;
	Vector<Ref<Material>> materials;

	String scene_name;
	Vector<int> root_nodes;
	Vector<Ref<GLTFTexture>> textures;
	Vector<Ref<Texture2D>> images;

	Vector<Ref<GLTFSkin>> skins;
	Vector<Ref<GLTFCamera>> cameras;
	Vector<Ref<GLTFLight>> lights;
	Set<String> unique_names;

	Vector<Ref<GLTFSkeleton>> skeletons;
	Map<GLTFSkeletonIndex, GLTFNodeIndex> skeleton_to_node;
	Vector<Ref<GLTFAnimation>> animations;
	Map<GLTFNodeIndex, Node *> scene_nodes;

	Dictionary get_json() {
		return this->json;
	}
	void set_json(Dictionary p_json) {
		this->json = p_json;
	}

	int get_major_version() {
		return this->major_version;
	}
	void set_major_version(int p_major_version) {
		this->major_version = p_major_version;
	}

	int get_minor_version() {
		return this->minor_version;
	}
	void set_minor_version(int p_minor_version) {
		this->minor_version = p_minor_version;
	}

	Vector<uint8_t> get_glb_data() {
		return this->glb_data;
	}
	void set_glb_data(Vector<uint8_t> p_glb_data) {
		this->glb_data = p_glb_data;
	}

	bool get_use_named_skin_binds() {
		return this->use_named_skin_binds;
	}
	void set_use_named_skin_binds(bool p_use_named_skin_binds) {
		this->use_named_skin_binds = p_use_named_skin_binds;
	}

	Array get_nodes() {
		return VariantConversion::to_array(this->nodes);
	}
	void set_nodes(Array p_nodes) {
		VariantConversion::set_from_array(this->nodes, p_nodes);
	}

	Array get_buffers() {
		return VariantConversion::to_array(this->buffers);
	}
	void set_buffers(Array p_buffers) {
		VariantConversion::set_from_array(this->buffers, p_buffers);
	}

	Array get_buffer_views() {
		return VariantConversion::to_array(this->buffer_views);
	}
	void set_buffer_views(Array p_buffer_views) {
		VariantConversion::set_from_array(this->buffer_views, p_buffer_views);
	}

	Array get_accessors() {
		return VariantConversion::to_array(this->accessors);
	}
	void set_accessors(Array p_accessors) {
		VariantConversion::set_from_array(this->accessors, p_accessors);
	}

	Array get_meshes() {
		return VariantConversion::to_array(this->meshes);
	}
	void set_meshes(Array p_meshes) {
		VariantConversion::set_from_array(this->meshes, p_meshes);
	}

	Array get_materials() {
		return VariantConversion::to_array(this->materials);
	}
	void set_materials(Array p_materials) {
		VariantConversion::set_from_array(this->materials, p_materials);
	}

	String get_scene_name() {
		return this->scene_name;
	}
	void set_scene_name(String p_scene_name) {
		this->scene_name = p_scene_name;
	}

	Array get_root_nodes() {
		return VariantConversion::to_array(this->root_nodes);
	}
	void set_root_nodes(Array p_root_nodes) {
		VariantConversion::set_from_array(this->root_nodes, p_root_nodes);
	}

	Array get_textures() {
		return VariantConversion::to_array(this->textures);
	}
	void set_textures(Array p_textures) {
		VariantConversion::set_from_array(this->textures, p_textures);
	}

	Array get_images() {
		return VariantConversion::to_array(this->images);
	}
	void set_images(Array p_images) {
		VariantConversion::set_from_array(this->images, p_images);
	}

	Array get_skins() {
		return VariantConversion::to_array(this->skins);
	}
	void set_skins(Array p_skins) {
		VariantConversion::set_from_array(this->skins, p_skins);
	}

	Array get_cameras() {
		return VariantConversion::to_array(this->cameras);
	}
	void set_cameras(Array p_cameras) {
		VariantConversion::set_from_array(this->cameras, p_cameras);
	}

	Array get_lights() {
		return VariantConversion::to_array(this->lights);
	}
	void set_lights(Array p_lights) {
		VariantConversion::set_from_array(this->lights, p_lights);
	}

	Array get_unique_names() {
		return VariantConversion::to_array(this->unique_names);
	}
	void set_unique_names(Array p_unique_names) {
		VariantConversion::set_from_array(this->unique_names, p_unique_names);
	}

	Array get_skeletons() {
		return VariantConversion::to_array(this->skeletons);
	}
	void set_skeletons(Array p_skeletons) {
		VariantConversion::set_from_array(this->skeletons, p_skeletons);
	}

	Dictionary get_skeleton_to_node() {
		return VariantConversion::to_dict(this->skeleton_to_node);
	}
	void set_skeleton_to_node(Dictionary p_skeleton_to_node) {
		VariantConversion::set_from_dict(this->skeleton_to_node, p_skeleton_to_node);
	}

	Array get_animations() {
		return VariantConversion::to_array(this->animations);
	}
	void set_animations(Array p_animations) {
		VariantConversion::set_from_array(this->animations, p_animations);
	}

	Node *get_scene_node(GLTFNodeIndex idx) {
		if (!this->scene_nodes.has(idx)) {
			return nullptr;
		}
		return this->scene_nodes[idx];
	}

	int get_animation_players_count(int idx) {
		return animation_players.size();
	}

	AnimationPlayer *get_animation_player(int idx) {
		ERR_FAIL_INDEX_V(idx, animation_players.size(), nullptr);
		return this->animation_players[idx];
	}

	//void set_scene_nodes(Map<GLTFNodeIndex, Node *> p_scene_nodes) {
	//	this->scene_nodes = p_scene_nodes;
	//}

	//void set_animation_players(Vector<AnimationPlayer *> p_animation_players) {
	//	this->animation_players = p_animation_players;
	//}

	//Map<Ref<Material>, GLTFMaterialIndex> get_material_cache() {
	//	return this->material_cache;
	//}
	//void set_material_cache(Map<Ref<Material>, GLTFMaterialIndex> p_material_cache) {
	//	this->material_cache = p_material_cache;
	//}

	GLTFState() {
	}
	~GLTFState() {
	}
};
#endif
