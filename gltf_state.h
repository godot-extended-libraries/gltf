#pragma once
#include "core/resource.h"
#include "core/vector.h"
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
#include "godot_conversion_operators.h"
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

	Vector<Ref<GLTFNode> > nodes;
	Vector<Vector<uint8_t> > buffers;
	Vector<Ref<GLTFBufferView> > buffer_views;
	Vector<Ref<GLTFAccessor> > accessors;

	Vector<Ref<GLTFMesh> > meshes; // meshes are loaded directly, no reason not to.

	Vector<AnimationPlayer *> animation_players;
	Map<Ref<Material>, GLTFMaterialIndex> material_cache;
	Vector<Ref<Material> > materials;

	String scene_name;
	Vector<int> root_nodes;
	Vector<Ref<GLTFTexture> > textures;
	Vector<Ref<Texture> > images;

	Vector<Ref<GLTFSkin> > skins;
	Vector<Ref<GLTFCamera> > cameras;
	Vector<Ref<GLTFLight> > lights;
	Set<String> unique_names;

	Vector<Ref<GLTFSkeleton> > skeletons;
	Map<GLTFSkeletonIndex, GLTFNodeIndex> skeleton_to_node;
	Vector<Ref<GLTFAnimation> > animations;
	Map<GLTFNodeIndex, Node *> scene_nodes;

	Dictionary get_json() {
		return this->json;
	}
	void set_json(Dictionary json) {
		this->json = json;
	}

	int get_major_version() {
		return this->major_version;
	}
	void set_major_version(int major_version) {
		this->major_version = major_version;
	}

	int get_minor_version() {
		return this->minor_version;
	}
	void set_minor_version(int minor_version) {
		this->minor_version = minor_version;
	}

	Vector<uint8_t> get_glb_data() {
		return this->glb_data;
	}
	void set_glb_data(Vector<uint8_t> glb_data) {
		this->glb_data = glb_data;
	}

	bool get_use_named_skin_binds() {
		return this->use_named_skin_binds;
	}
	void set_use_named_skin_binds(bool use_named_skin_binds) {
		this->use_named_skin_binds = use_named_skin_binds;
	}

	Array get_nodes() {
		return godot_conv::to_array(this->nodes);
	}
	void set_nodes(Array nodes) {
		godot_conv::set_from_array(this->nodes, nodes);
	}

	Array get_buffers() {
		return godot_conv::to_array(this->buffers);
	}
	void set_buffers(Array buffers) {
		godot_conv::set_from_array(this->buffers, buffers);
	}

	Array get_buffer_views() {
		return godot_conv::to_array(this->buffer_views);
	}
	void set_buffer_views(Array buffer_views) {
		godot_conv::set_from_array(this->buffer_views, buffer_views);
	}

	Array get_accessors() {
		return godot_conv::to_array(this->accessors);
	}
	void set_accessors(Array accessors) {
		godot_conv::set_from_array(this->accessors, accessors);
	}

	Array get_meshes() {
		return godot_conv::to_array(this->meshes);
	}
	void set_meshes(Array meshes) {
		godot_conv::set_from_array(this->meshes, meshes);
	}

	Array get_materials() {
		return godot_conv::to_array(this->materials);
	}
	void set_materials(Array materials) {
		godot_conv::set_from_array(this->materials, materials);
	}

	String get_scene_name() {
		return this->scene_name;
	}
	void set_scene_name(String scene_name) {
		this->scene_name = scene_name;
	}

	Array get_root_nodes() {
		return godot_conv::to_array(this->root_nodes);
	}
	void set_root_nodes(Array root_nodes) {
		godot_conv::set_from_array(this->root_nodes, root_nodes);
	}

	Array get_textures() {
		return godot_conv::to_array(this->textures);
	}
	void set_textures(Array textures) {
		godot_conv::set_from_array(this->textures, textures);
	}

	Array get_images() {
		return godot_conv::to_array(this->images);
	}
	void set_images(Array images) {
		godot_conv::set_from_array(this->images, images);
	}

	Array get_skins() {
		return godot_conv::to_array(this->skins);
	}
	void set_skins(Array skins) {
		godot_conv::set_from_array(this->skins, skins);
	}

	Array get_cameras() {
		return godot_conv::to_array(this->cameras);
	}
	void set_cameras(Array cameras) {
		godot_conv::set_from_array(this->cameras, cameras);
	}

	Array get_lights() {
		return godot_conv::to_array(this->lights);
	}
	void set_lights(Array lights) {
		godot_conv::set_from_array(this->lights, lights);
	}

	Array get_unique_names() {
		return godot_conv::to_array(this->unique_names);
	}
	void set_unique_names(Array unique_names) {
		godot_conv::set_from_array(this->unique_names, unique_names);
	}

	Array get_skeletons() {
		return godot_conv::to_array(this->skeletons);
	}
	void set_skeletons(Array skeletons) {
		godot_conv::set_from_array(this->skeletons, skeletons);
	}

	Dictionary get_skeleton_to_node() {
		return godot_conv::to_dict(this->skeleton_to_node);
	}
	void set_skeleton_to_node(Dictionary skeleton_to_node) {
		godot_conv::set_from_dict(this->skeleton_to_node, skeleton_to_node);
	}

	Array get_animations() {
		return godot_conv::to_array(this->animations);
	}
	void set_animations(Array animations) {
		godot_conv::set_from_array(this->animations, animations);
	}

	//Map<GLTFNodeIndex, Node *> get_scene_nodes() {
	//	return this->scene_nodes;
	//}
	//void set_scene_nodes(Map<GLTFNodeIndex, Node *> scene_nodes) {
	//	this->scene_nodes = scene_nodes;
	//}

	//Vector<AnimationPlayer *> get_animation_players() {
	//	return this->animation_players;
	//}
	//void set_animation_players(Vector<AnimationPlayer *> animation_players) {
	//	this->animation_players = animation_players;
	//}

	//Map<Ref<Material>, GLTFMaterialIndex> get_material_cache() {
	//	return this->material_cache;
	//}
	//void set_material_cache(Map<Ref<Material>, GLTFMaterialIndex> material_cache) {
	//	this->material_cache = material_cache;
	//}

	GLTFState() {
	}
	~GLTFState() {
	}
};