#include "gltf_buffer_view.h"




void GLTFBufferView::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_buffer"),  &GLTFBufferView::get_buffer);
	ClassDB::bind_method(D_METHOD("set_buffer", "buffer"),  &GLTFBufferView::set_buffer);
	ClassDB::bind_method(D_METHOD("get_byte_offset"),  &GLTFBufferView::get_byte_offset);
	ClassDB::bind_method(D_METHOD("set_byte_offset", "byte_offset"),  &GLTFBufferView::set_byte_offset);
	ClassDB::bind_method(D_METHOD("get_byte_length"),  &GLTFBufferView::get_byte_length);
	ClassDB::bind_method(D_METHOD("set_byte_length", "byte_length"),  &GLTFBufferView::set_byte_length);
	ClassDB::bind_method(D_METHOD("get_byte_stride"),  &GLTFBufferView::get_byte_stride);
	ClassDB::bind_method(D_METHOD("set_byte_stride", "byte_stride"),  &GLTFBufferView::set_byte_stride);
	ClassDB::bind_method(D_METHOD("get_indices"),  &GLTFBufferView::get_indices);
	ClassDB::bind_method(D_METHOD("set_indices", "indices"),  &GLTFBufferView::set_indices);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "buffer"), "set_buffer", "get_buffer"); // GLTFBufferIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "byte_offset"), "set_byte_offset", "get_byte_offset"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "byte_length"), "set_byte_length", "get_byte_length"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "byte_stride"), "set_byte_stride", "get_byte_stride"); // int
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "indices"), "set_indices", "get_indices"); // bool

}
