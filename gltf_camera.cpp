#include "gltf_camera.h"
#include "gltf_camera.h"




void GLTFCamera::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_perspective"),  &GLTFCamera::get_perspective);
	ClassDB::bind_method(D_METHOD("set_perspective", "perspective"),  &GLTFCamera::set_perspective);
	ClassDB::bind_method(D_METHOD("get_fov_size"),  &GLTFCamera::get_fov_size);
	ClassDB::bind_method(D_METHOD("set_fov_size", "fov_size"),  &GLTFCamera::set_fov_size);
	ClassDB::bind_method(D_METHOD("get_zfar"),  &GLTFCamera::get_zfar);
	ClassDB::bind_method(D_METHOD("set_zfar", "zfar"),  &GLTFCamera::set_zfar);
	ClassDB::bind_method(D_METHOD("get_znear"),  &GLTFCamera::get_znear);
	ClassDB::bind_method(D_METHOD("set_znear", "znear"),  &GLTFCamera::set_znear);

	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "perspective"), "set_perspective", "get_perspective"); // bool
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "fov_size"), "set_fov_size", "get_fov_size"); // float
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "zfar"), "set_zfar", "get_zfar"); // float
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "znear"), "set_znear", "get_znear"); // float

}
