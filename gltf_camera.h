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
	void set_perspective(bool val) { perspective = val; }
	float get_fov_size() const { return fov_size; }
	void set_fov_size(float val) { fov_size = val; }
	float get_zfar() const { return zfar; }
	void set_zfar(float val) { zfar = val; }
	float get_znear() const { return znear; }
	void set_znear(float val) { znear = val; }
	GLTFCamera() {
		set_perspective(true);
		set_fov_size(65);
		set_zfar(500);
		set_znear(0.1);
	}
};

