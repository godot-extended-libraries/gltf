#include "gltf_accessor.h"


void GLTFAccessor::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_buffer_view"),  &GLTFAccessor::get_buffer_view);
	ClassDB::bind_method(D_METHOD("set_buffer_view", "buffer_view"),  &GLTFAccessor::set_buffer_view);
	ClassDB::bind_method(D_METHOD("get_byte_offset"),  &GLTFAccessor::get_byte_offset);
	ClassDB::bind_method(D_METHOD("set_byte_offset", "byte_offset"),  &GLTFAccessor::set_byte_offset);
	ClassDB::bind_method(D_METHOD("get_component_type"),  &GLTFAccessor::get_component_type);
	ClassDB::bind_method(D_METHOD("set_component_type", "component_type"),  &GLTFAccessor::set_component_type);
	ClassDB::bind_method(D_METHOD("get_normalized"),  &GLTFAccessor::get_normalized);
	ClassDB::bind_method(D_METHOD("set_normalized", "normalized"),  &GLTFAccessor::set_normalized);
	ClassDB::bind_method(D_METHOD("get_count"),  &GLTFAccessor::get_count);
	ClassDB::bind_method(D_METHOD("set_count", "count"),  &GLTFAccessor::set_count);
	ClassDB::bind_method(D_METHOD("get_type"),  &GLTFAccessor::get_type);
	ClassDB::bind_method(D_METHOD("set_type", "type"),  &GLTFAccessor::set_type);
	ClassDB::bind_method(D_METHOD("get_min"),  &GLTFAccessor::get_min);
	ClassDB::bind_method(D_METHOD("set_min", "min"),  &GLTFAccessor::set_min);
	ClassDB::bind_method(D_METHOD("get_max"),  &GLTFAccessor::get_max);
	ClassDB::bind_method(D_METHOD("set_max", "max"),  &GLTFAccessor::set_max);
	ClassDB::bind_method(D_METHOD("get_sparse_count"),  &GLTFAccessor::get_sparse_count);
	ClassDB::bind_method(D_METHOD("set_sparse_count", "sparse_count"),  &GLTFAccessor::set_sparse_count);
	ClassDB::bind_method(D_METHOD("get_sparse_indices_buffer_view"),  &GLTFAccessor::get_sparse_indices_buffer_view);
	ClassDB::bind_method(D_METHOD("set_sparse_indices_buffer_view", "sparse_indices_buffer_view"),  &GLTFAccessor::set_sparse_indices_buffer_view);
	ClassDB::bind_method(D_METHOD("get_sparse_indices_byte_offset"),  &GLTFAccessor::get_sparse_indices_byte_offset);
	ClassDB::bind_method(D_METHOD("set_sparse_indices_byte_offset", "sparse_indices_byte_offset"),  &GLTFAccessor::set_sparse_indices_byte_offset);
	ClassDB::bind_method(D_METHOD("get_sparse_indices_component_type"),  &GLTFAccessor::get_sparse_indices_component_type);
	ClassDB::bind_method(D_METHOD("set_sparse_indices_component_type", "sparse_indices_component_type"),  &GLTFAccessor::set_sparse_indices_component_type);
	ClassDB::bind_method(D_METHOD("get_sparse_values_buffer_view"),  &GLTFAccessor::get_sparse_values_buffer_view);
	ClassDB::bind_method(D_METHOD("set_sparse_values_buffer_view", "sparse_values_buffer_view"),  &GLTFAccessor::set_sparse_values_buffer_view);
	ClassDB::bind_method(D_METHOD("get_sparse_values_byte_offset"),  &GLTFAccessor::get_sparse_values_byte_offset);
	ClassDB::bind_method(D_METHOD("set_sparse_values_byte_offset", "sparse_values_byte_offset"),  &GLTFAccessor::set_sparse_values_byte_offset);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "buffer_view"), "set_buffer_view", "get_buffer_view"); // GLTFBufferViewIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "byte_offset"), "set_byte_offset", "get_byte_offset"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "component_type"), "set_component_type", "get_component_type"); // int
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "normalized"), "set_normalized", "get_normalized"); // bool
	ADD_PROPERTY(PropertyInfo(Variant::INT, "count"), "set_count", "get_count"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "type"), "set_type", "get_type"); // GLTFDocument::GLTFType
	ADD_PROPERTY(PropertyInfo(Variant::POOL_REAL_ARRAY, "min"), "set_min", "get_min"); // Vector<real_t>
	ADD_PROPERTY(PropertyInfo(Variant::POOL_REAL_ARRAY, "max"), "set_max", "get_max"); // Vector<real_t>
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sparse_count"), "set_sparse_count", "get_sparse_count"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sparse_indices_buffer_view"), "set_sparse_indices_buffer_view", "get_sparse_indices_buffer_view"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sparse_indices_byte_offset"), "set_sparse_indices_byte_offset", "get_sparse_indices_byte_offset"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sparse_indices_component_type"), "set_sparse_indices_component_type", "get_sparse_indices_component_type"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sparse_values_buffer_view"), "set_sparse_values_buffer_view", "get_sparse_values_buffer_view"); // int
	ADD_PROPERTY(PropertyInfo(Variant::INT, "sparse_values_byte_offset"), "set_sparse_values_byte_offset", "get_sparse_values_byte_offset"); // int

}
