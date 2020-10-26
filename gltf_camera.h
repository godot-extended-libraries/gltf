#pragma once
#include "core/resource.h"

class GLTFCamera : public Resource {
	GDCLASS(GLTFCamera, Resource);
	bool perspective;
	float fov_size;
	float zfar;
	float znear;

protected:
	static void _bind_methods();

public:
	bool get_perspective() const { return perspective; }
	void set_perspective(bool p_val) { perspective = p_val; }
	float get_fov_size() const { return fov_size; }
	void set_fov_size(float p_val) { fov_size = p_val; }
	float get_zfar() const { return zfar; }
	void set_zfar(float p_val) { zfar = p_val; }
	float get_znear() const { return znear; }
	void set_znear(float p_val) { znear = p_val; }
	GLTFCamera() {
		set_perspective(true);
		set_fov_size(65);
		set_zfar(500);
		set_znear(0.1);
	}
};
