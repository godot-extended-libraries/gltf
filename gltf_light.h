#pragma once
#include "core/resource.h"

class GLTFLight : public Resource {
	GDCLASS(GLTFLight, Resource);

public:
	Color color = Color(1.0f, 1.0f, 1.0f);
	float intensity = 0.0f;
	String type = "";
	float range = Math_INF;
	float inner_cone_angle = 0.0f;
	float outer_cone_angle = Math_PI / 4.0;
};
