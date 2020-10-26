#pragma once
#include "core/resource.h"
#include "gltf_document.h"

struct GLTFAccessor : public Resource {
	GDCLASS(GLTFAccessor, Resource);

protected:
	static void _bind_methods();

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

	GLTFBufferViewIndex get_buffer_view() {
		return this->buffer_view;
	}
	void set_buffer_view(GLTFBufferViewIndex p_buffer_view) {
		this->buffer_view = p_buffer_view;
	}

	int get_byte_offset() {
		return this->byte_offset;
	}
	void set_byte_offset(int p_byte_offset) {
		this->byte_offset = p_byte_offset;
	}

	int get_component_type() {
		return this->component_type;
	}
	void set_component_type(int p_component_type) {
		this->component_type = p_component_type;
	}

	bool get_normalized() {
		return this->normalized;
	}
	void set_normalized(bool p_normalized) {
		this->normalized = p_normalized;
	}

	int get_count() {
		return this->count;
	}
	void set_count(int p_count) {
		this->count = p_count;
	}

	int get_type() {
		return (int)this->type;
	}
	void set_type(int p_type) {
		this->type = (GLTFDocument::GLTFType)p_type; // TODO: Register enum
	}

	Vector<real_t> get_min() {
		return this->min;
	}
	void set_min(Vector<real_t> p_min) {
		this->min = p_min;
	}

	Vector<real_t> get_max() {
		return this->max;
	}
	void set_max(Vector<real_t> p_max) {
		this->max = p_max;
	}

	int get_sparse_count() {
		return this->sparse_count;
	}
	void set_sparse_count(int p_sparse_count) {
		this->sparse_count = p_sparse_count;
	}

	int get_sparse_indices_buffer_view() {
		return this->sparse_indices_buffer_view;
	}
	void set_sparse_indices_buffer_view(int p_sparse_indices_buffer_view) {
		this->sparse_indices_buffer_view = p_sparse_indices_buffer_view;
	}

	int get_sparse_indices_byte_offset() {
		return this->sparse_indices_byte_offset;
	}
	void set_sparse_indices_byte_offset(int p_sparse_indices_byte_offset) {
		this->sparse_indices_byte_offset = p_sparse_indices_byte_offset;
	}

	int get_sparse_indices_component_type() {
		return this->sparse_indices_component_type;
	}
	void set_sparse_indices_component_type(int p_sparse_indices_component_type) {
		this->sparse_indices_component_type = p_sparse_indices_component_type;
	}

	int get_sparse_values_buffer_view() {
		return this->sparse_values_buffer_view;
	}
	void set_sparse_values_buffer_view(int p_sparse_values_buffer_view) {
		this->sparse_values_buffer_view = p_sparse_values_buffer_view;
	}

	int get_sparse_values_byte_offset() {
		return this->sparse_values_byte_offset;
	}
	void set_sparse_values_byte_offset(int p_sparse_values_byte_offset) {
		this->sparse_values_byte_offset = p_sparse_values_byte_offset;
	}

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
