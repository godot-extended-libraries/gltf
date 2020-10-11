#include "gltf_light.h"
#include "gltf_light.h"




void GLTFLight::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_color"),  &GLTFLight::get_color);
	ClassDB::bind_method(D_METHOD("set_color", "color"),  &GLTFLight::set_color);
	ClassDB::bind_method(D_METHOD("get_intensity"),  &GLTFLight::get_intensity);
	ClassDB::bind_method(D_METHOD("set_intensity", "intensity"),  &GLTFLight::set_intensity);
	ClassDB::bind_method(D_METHOD("get_type"),  &GLTFLight::get_type);
	ClassDB::bind_method(D_METHOD("set_type", "type"),  &GLTFLight::set_type);
	ClassDB::bind_method(D_METHOD("get_range"),  &GLTFLight::get_range);
	ClassDB::bind_method(D_METHOD("set_range", "range"),  &GLTFLight::set_range);
	ClassDB::bind_method(D_METHOD("get_inner_cone_angle"),  &GLTFLight::get_inner_cone_angle);
	ClassDB::bind_method(D_METHOD("set_inner_cone_angle", "inner_cone_angle"),  &GLTFLight::set_inner_cone_angle);
	ClassDB::bind_method(D_METHOD("get_outer_cone_angle"),  &GLTFLight::get_outer_cone_angle);
	ClassDB::bind_method(D_METHOD("set_outer_cone_angle", "outer_cone_angle"),  &GLTFLight::set_outer_cone_angle);

	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "color"), "set_color", "get_color"); // Color
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "intensity"), "set_intensity", "get_intensity"); // float
	ADD_PROPERTY(PropertyInfo(Variant::STRING, "type"), "set_type", "get_type"); // String
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "range"), "set_range", "get_range"); // float
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "inner_cone_angle"), "set_inner_cone_angle", "get_inner_cone_angle"); // float
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "outer_cone_angle"), "set_outer_cone_angle", "get_outer_cone_angle"); // float

}
