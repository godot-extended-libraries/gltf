#pragma once
#include "core/resource.h"
#include "core/vector.h"
#include "gltf_accessor.h"
#include "gltf_buffer_view.h"
#include "gltf_document.h"
#include "gltf_mesh.h"
#include "gltf_node.h"
#include "gltf_texture.h"
#include "scene/animation/animation_player.h"
#include "scene/resources/texture.h"
#include "gltf_light.h"
#include "gltf_skeleton.h"
#include "gltf_animation.h"
#include "gltf_skin.h"
#include "gltf_camera.h"

class GLTFState : public Resource {
	GDCLASS(GLTFState, Resource);

public:
	Dictionary json;
	int major_version;
	int minor_version;
	Vector<uint8_t> glb_data;

	bool use_named_skin_binds;

	Vector<GLTFNode *> nodes;
	Vector<Vector<uint8_t> > buffers;
	Vector<GLTFBufferView> buffer_views;
	Vector<GLTFAccessor> accessors;

	Vector<GLTFMesh> meshes; // meshes are loaded directly, no reason not to.

	Vector<AnimationPlayer *> animation_players;
	Map<Ref<Material>, GLTFMaterialIndex> material_cache;
	Vector<Ref<Material> > materials;

	String scene_name;
	Vector<int> root_nodes;

	Vector<GLTFTexture> textures;
	Vector<Ref<Texture2D> > images;

	Vector<GLTFSkin> skins;
	Vector<GLTFCamera> cameras;
	Vector<GLTFLight> lights;

	Set<String> unique_names;

	Vector<Ref<GLTFSkeleton>> skeletons;
	Map<GLTFSkeletonIndex, GLTFNodeIndex> skeleton_to_node;
	Vector<Ref<GLTFAnimation>> animations;

	Map<GLTFNodeIndex, Node *> scene_nodes;
	GLTFState() {
	}
	~GLTFState() {
		for (int i = 0; i < nodes.size(); i++) {
			memdelete(nodes[i]);
		}
	}
};