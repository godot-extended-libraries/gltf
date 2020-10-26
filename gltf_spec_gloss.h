#ifndef GLTF_SPEC_GLOSS_H
#define GLTF_SPEC_GLOSS_H

#include "core/image.h"
#include "core/resource.h"

class GLTFSpecGloss : public Resource {
	GDCLASS(GLTFSpecGloss, Resource);

protected:
	static void _bind_methods();

public:
	Ref<Image> diffuse_img = nullptr;
	Color diffuse_factor = Color(1.0f, 1.0f, 1.0f);
	float gloss_factor = 1.0f;
	Color specular_factor = Color(1.0f, 1.0f, 1.0f);
	Ref<Image> spec_gloss_img = nullptr;

	Ref<Image> get_diffuse_img() {
		return this->diffuse_img;
	}
	void set_diffuse_img(Ref<Image> p_diffuse_img) {
		this->diffuse_img = p_diffuse_img;
	}

	Color get_diffuse_factor() {
		return this->diffuse_factor;
	}
	void set_diffuse_factor(Color p_diffuse_factor) {
		this->diffuse_factor = p_diffuse_factor;
	}

	float get_gloss_factor() {
		return this->gloss_factor;
	}
	void set_gloss_factor(float p_gloss_factor) {
		this->gloss_factor = p_gloss_factor;
	}

	Color get_specular_factor() {
		return this->specular_factor;
	}
	void set_specular_factor(Color p_specular_factor) {
		this->specular_factor = p_specular_factor;
	}

	Ref<Image> get_spec_gloss_img() {
		return this->spec_gloss_img;
	}
	void set_spec_gloss_img(Ref<Image> p_spec_gloss_img) {
		this->spec_gloss_img = p_spec_gloss_img;
	}
};
#endif