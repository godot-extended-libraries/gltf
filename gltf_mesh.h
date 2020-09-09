#pragma once
#include "core/resource.h"
#include "scene/resources/mesh.h"

class GLTFMesh : public Resource {
	GDCLASS(GLTFMesh, Resource);

public:
	Ref<Mesh> mesh;
	Vector<float> blend_weights;
};