#include "gltf_animation.h"



void GLTFAnimation::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_loop"),  &GLTFAnimation::get_loop);
	ClassDB::bind_method(D_METHOD("set_loop", "loop"),  &GLTFAnimation::set_loop);
	//ClassDB::bind_method(D_METHOD("get_name"),  &GLTFAnimation::get_name);
	//ClassDB::bind_method(D_METHOD("set_name", "name"),  &GLTFAnimation::set_name);

	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "loop"), "set_loop", "get_loop"); // bool
	//ADD_PROPERTY(PropertyInfo(Variant::STRING, "name"), "set_name", "get_name"); // String

}
