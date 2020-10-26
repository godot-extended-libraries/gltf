#pragma once
#include "core/resource.h"
#include "gltf_document.h"

class GLTFBufferView : public Resource {
	GDCLASS(GLTFBufferView, Resource);

protected:
	static void _bind_methods();

public:
	GLTFBufferIndex buffer;
	int byte_offset;
	int byte_length;
	int byte_stride;
	bool indices;


	GLTFBufferIndex get_buffer() {
		return this->buffer;
	}
	void set_buffer(GLTFBufferIndex buffer) {
		this->buffer = buffer;
	}


	int get_byte_offset() {
		return this->byte_offset;
	}
	void set_byte_offset(int byte_offset) {
		this->byte_offset = byte_offset;
	}


	int get_byte_length() {
		return this->byte_length;
	}
	void set_byte_length(int byte_length) {
		this->byte_length = byte_length;
	}


	int get_byte_stride() {
		return this->byte_stride;
	}
	void set_byte_stride(int byte_stride) {
		this->byte_stride = byte_stride;
	}


	bool get_indices() {
		return this->indices;
	}
	void set_indices(bool indices) {
		this->indices = indices;
	}
	// matrices need to be transformed to this

	GLTFBufferView() :
			buffer(-1), byte_offset(0), byte_length(0), byte_stride(-1), indices(false) {}
};
