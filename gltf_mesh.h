#ifndef GLTF_MESH_H
#define GLTF_MESH_H

#include "core/resource.h"
#include "scene/resources/mesh.h"

class GLTFMesh : public Resource {
	GDCLASS(GLTFMesh, Resource);

protected:
	static void _bind_methods();

public:
	Ref<Mesh> mesh;
	Vector<float> blend_weights;

	Ref<Mesh> get_mesh() {
		return this->mesh;
	}
	void set_mesh(Ref<Mesh> p_mesh) {
		this->mesh = p_mesh;
	}


	Vector<float> get_blend_weights() {
		return this->blend_weights;
	}
	void set_blend_weights(Vector<float> p_blend_weights) {
		this->blend_weights = p_blend_weights;
	}

};
#endif