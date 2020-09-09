#pragma once
#include "core/resource.h"
#include "gltf_document.h"


class GLTFTexture : public Resource {
	GDCLASS(GLTFTexture, Resource);

public:
	GLTFImageIndex src_image;
};



