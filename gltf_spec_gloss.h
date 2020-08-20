#pragma once
#include "core/resource.h"
#include "core/image.h"

class GLTFSpecGloss : public Resource {
	GDCLASS(GLTFSpecGloss, Resource);

public:
	Ref<Image> diffuse_img = nullptr;
	Color diffuse_factor = Color(1.0f, 1.0f, 1.0f);
	float gloss_factor = 1.0f;
	Color specular_factor = Color(1.0f, 1.0f, 1.0f);
	Ref<Image> spec_gloss_img = nullptr;
};


