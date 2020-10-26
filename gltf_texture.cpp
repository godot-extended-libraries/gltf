#include "gltf_texture.h"

void GLTFTexture::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_src_image"), &GLTFTexture::get_src_image);
	ClassDB::bind_method(D_METHOD("set_src_image", "src_image"), &GLTFTexture::set_src_image);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "src_image"), "set_src_image", "get_src_image"); // int
}
