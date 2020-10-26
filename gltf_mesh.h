#pragma once
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
	void set_mesh(Ref<Mesh> mesh) {
		this->mesh = mesh;
	}


	Vector<float> get_blend_weights() {
		return this->blend_weights;
	}
	void set_blend_weights(Vector<float> blend_weights) {
		this->blend_weights = blend_weights;
	}

};