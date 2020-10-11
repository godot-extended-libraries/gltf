#pragma once
#include "core/resource.h"
#include "gltf_document.h"


class GLTFTexture : public Resource {
	GDCLASS(GLTFTexture, Resource);

protected:
	static void _bind_methods();

public:
	GLTFImageIndex src_image;


	int get_src_image() {
		return this->src_image;
	}
	void set_src_image(int p_src_image) {
		this->src_image = p_src_image;
	}
};



