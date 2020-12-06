#ifndef GLTF_LIGHT_H
#define GLTF_LIGHT_H

#include "core/engine.h"
#include "core/resource.h"

class GLTFLight : public Resource {
	GDCLASS(GLTFLight, Resource);

protected:
	static void _bind_methods();

public:
	Color color;
	float intensity;
	String type;
	float range;
	float inner_cone_angle;
	float outer_cone_angle;


	Color get_color() {
		return this->color;
	}
	void set_color(Color p_color) {
		this->color = p_color;
	}


	float get_intensity() {
		return this->intensity;
	}
	void set_intensity(float p_intensity) {
		this->intensity = p_intensity;
	}


	String get_type() {
		return this->type;
	}
	void set_type(String p_type) {
		this->type = p_type;
	}


	float get_range() {
		return this->range;
	}
	void set_range(float p_range) {
		this->range = p_range;
	}


	float get_inner_cone_angle() {
		return this->inner_cone_angle;
	}
	void set_inner_cone_angle(float p_inner_cone_angle) {
		this->inner_cone_angle = p_inner_cone_angle;
	}


	float get_outer_cone_angle() {
		return this->outer_cone_angle;
	}
	void set_outer_cone_angle(float p_outer_cone_angle) {
		this->outer_cone_angle = p_outer_cone_angle;
	}

	GLTFLight() {}
	~GLTFLight(){}
};

#endif