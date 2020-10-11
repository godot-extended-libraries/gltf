#include "gltf_spec_gloss.h"
#include "gltf_spec_gloss.h"


void GLTFSpecGloss::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_diffuse_img"),  &GLTFSpecGloss::get_diffuse_img);
	ClassDB::bind_method(D_METHOD("set_diffuse_img", "diffuse_img"),  &GLTFSpecGloss::set_diffuse_img);
	ClassDB::bind_method(D_METHOD("get_diffuse_factor"),  &GLTFSpecGloss::get_diffuse_factor);
	ClassDB::bind_method(D_METHOD("set_diffuse_factor", "diffuse_factor"),  &GLTFSpecGloss::set_diffuse_factor);
	ClassDB::bind_method(D_METHOD("get_gloss_factor"),  &GLTFSpecGloss::get_gloss_factor);
	ClassDB::bind_method(D_METHOD("set_gloss_factor", "gloss_factor"),  &GLTFSpecGloss::set_gloss_factor);
	ClassDB::bind_method(D_METHOD("get_specular_factor"),  &GLTFSpecGloss::get_specular_factor);
	ClassDB::bind_method(D_METHOD("set_specular_factor", "specular_factor"),  &GLTFSpecGloss::set_specular_factor);
	ClassDB::bind_method(D_METHOD("get_spec_gloss_img"),  &GLTFSpecGloss::get_spec_gloss_img);
	ClassDB::bind_method(D_METHOD("set_spec_gloss_img", "spec_gloss_img"),  &GLTFSpecGloss::set_spec_gloss_img);

	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "diffuse_img"), "set_diffuse_img", "get_diffuse_img"); // Ref<Image>
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "diffuse_factor"), "set_diffuse_factor", "get_diffuse_factor"); // Color
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "gloss_factor"), "set_gloss_factor", "get_gloss_factor"); // float
	ADD_PROPERTY(PropertyInfo(Variant::COLOR, "specular_factor"), "set_specular_factor", "get_specular_factor"); // Color
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "spec_gloss_img"), "set_spec_gloss_img", "get_spec_gloss_img"); // Ref<Image>

}
