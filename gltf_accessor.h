#pragma once
#include "core/resource.h"
#include "gltf_document.h"

struct GLTFAccessor : public Resource {
	GDCLASS(GLTFAccessor, Resource);

public:
	GLTFBufferViewIndex buffer_view;
	int byte_offset;
	int component_type;
	bool normalized;
	int count;
	GLTFDocument::GLTFType type;
	Vector<real_t> min;
	Vector<real_t> max;
	int sparse_count;
	int sparse_indices_buffer_view;
	int sparse_indices_byte_offset;
	int sparse_indices_component_type;
	int sparse_values_buffer_view;
	int sparse_values_byte_offset;

	GLTFAccessor() {
		type = GLTFDocument::TYPE_SCALAR;
		buffer_view = 0;
		byte_offset = 0;
		component_type = 0;
		normalized = false;
		count = 0;
		sparse_count = 0;
		sparse_indices_buffer_view = 0;
		sparse_indices_byte_offset = 0;
		sparse_indices_component_type = 0;
		sparse_values_buffer_view = 0;
		sparse_values_byte_offset = 0;
	}
};


