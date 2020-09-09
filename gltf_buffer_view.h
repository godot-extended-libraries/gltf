#pragma once
#include "core/resource.h"
#include "gltf_document.h"

class GLTFBufferView : public Resource {
	GDCLASS(GLTFBufferView, Resource);

public:
	GLTFBufferIndex buffer;
	int byte_offset;
	int byte_length;
	int byte_stride;
	bool indices;
	// matrices need to be transformed to this

	GLTFBufferView() :
			buffer(-1), byte_offset(0), byte_length(0), byte_stride(-1), indices(false) {}
};
