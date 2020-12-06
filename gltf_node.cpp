/*************************************************************************/
/*  gltf_node.cpp                                                        */
/*************************************************************************/
/*                       This file is part of:                           */
/*                           GODOT ENGINE                                */
/*                      https://godotengine.org                          */
/*************************************************************************/
/* Copyright (c) 2007-2020 Juan Linietsky, Ariel Manzur.                 */
/* Copyright (c) 2014-2020 Godot Engine contributors (cf. AUTHORS.md).   */
/*                                                                       */
/* Permission is hereby granted, free of charge, to any person obtaining */
/* a copy of this software and associated documentation files (the       */
/* "Software"), to deal in the Software without restriction, including   */
/* without limitation the rights to use, copy, modify, merge, publish,   */
/* distribute, sublicense, and/or sell copies of the Software, and to    */
/* permit persons to whom the Software is furnished to do so, subject to */
/* the following conditions:                                             */
/*                                                                       */
/* The above copyright notice and this permission notice shall be        */
/* included in all copies or substantial portions of the Software.       */
/*                                                                       */
/* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,       */
/* EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF    */
/* MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.*/
/* IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY  */
/* CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,  */
/* TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE     */
/* SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.                */
/*************************************************************************/

#include "gltf_node.h"

void GLTFNode::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_parent"), &GLTFNode::get_parent);
	ClassDB::bind_method(D_METHOD("set_parent", "parent"), &GLTFNode::set_parent);
	ClassDB::bind_method(D_METHOD("get_height"), &GLTFNode::get_height);
	ClassDB::bind_method(D_METHOD("set_height", "height"), &GLTFNode::set_height);
	ClassDB::bind_method(D_METHOD("get_xform"), &GLTFNode::get_xform);
	ClassDB::bind_method(D_METHOD("set_xform", "xform"), &GLTFNode::set_xform);
	//ClassDB::bind_method(D_METHOD("get_name"),  &GLTFNode::get_name);
	//ClassDB::bind_method(D_METHOD("set_name", "name"),  &GLTFNode::set_name);
	ClassDB::bind_method(D_METHOD("get_mesh"), &GLTFNode::get_mesh);
	ClassDB::bind_method(D_METHOD("set_mesh", "mesh"), &GLTFNode::set_mesh);
	ClassDB::bind_method(D_METHOD("get_camera"), &GLTFNode::get_camera);
	ClassDB::bind_method(D_METHOD("set_camera", "camera"), &GLTFNode::set_camera);
	ClassDB::bind_method(D_METHOD("get_skin"), &GLTFNode::get_skin);
	ClassDB::bind_method(D_METHOD("set_skin", "skin"), &GLTFNode::set_skin);
	ClassDB::bind_method(D_METHOD("get_skeleton"), &GLTFNode::get_skeleton);
	ClassDB::bind_method(D_METHOD("set_skeleton", "skeleton"), &GLTFNode::set_skeleton);
	ClassDB::bind_method(D_METHOD("get_joint"), &GLTFNode::get_joint);
	ClassDB::bind_method(D_METHOD("set_joint", "joint"), &GLTFNode::set_joint);
	ClassDB::bind_method(D_METHOD("get_translation"), &GLTFNode::get_translation);
	ClassDB::bind_method(D_METHOD("set_translation", "translation"), &GLTFNode::set_translation);
	ClassDB::bind_method(D_METHOD("get_rotation"), &GLTFNode::get_rotation);
	ClassDB::bind_method(D_METHOD("set_rotation", "rotation"), &GLTFNode::set_rotation);
	ClassDB::bind_method(D_METHOD("get_scale"), &GLTFNode::get_scale);
	ClassDB::bind_method(D_METHOD("set_scale", "scale"), &GLTFNode::set_scale);
	ClassDB::bind_method(D_METHOD("get_children"), &GLTFNode::get_children);
	ClassDB::bind_method(D_METHOD("set_children", "children"), &GLTFNode::set_children);
	ClassDB::bind_method(D_METHOD("get_fake_joint_parent"), &GLTFNode::get_fake_joint_parent);
	ClassDB::bind_method(D_METHOD("set_fake_joint_parent", "fake_joint_parent"), &GLTFNode::set_fake_joint_parent);
	ClassDB::bind_method(D_METHOD("get_light"), &GLTFNode::get_light);
	ClassDB::bind_method(D_METHOD("set_light", "light"), &GLTFNode::set_light);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "parent"), "set_parent", "get_parent"); // GLTFNodeIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "height"), "set_height", "get_height"); // int
	ADD_PROPERTY(PropertyInfo(Variant::TRANSFORM, "xform"), "set_xform", "get_xform"); // Transform
	ADD_PROPERTY(PropertyInfo(Variant::INT, "mesh"), "set_mesh", "get_mesh"); // GLTFMeshIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "camera"), "set_camera", "get_camera"); // GLTFCameraIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skin"), "set_skin", "get_skin"); // GLTFSkinIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skeleton"), "set_skeleton", "get_skeleton"); // GLTFSkeletonIndex
	ADD_PROPERTY(PropertyInfo(Variant::BOOL, "joint"), "set_joint", "get_joint"); // bool
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "translation"), "set_translation", "get_translation"); // Vector3
	ADD_PROPERTY(PropertyInfo(Variant::QUAT, "rotation"), "set_rotation", "get_rotation"); // Quat
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR3, "scale"), "set_scale", "get_scale"); // Vector3
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "children"), "set_children", "get_children"); // Vector<int>
	ADD_PROPERTY(PropertyInfo(Variant::INT, "fake_joint_parent"), "set_fake_joint_parent", "get_fake_joint_parent"); // GLTFNodeIndex
	ADD_PROPERTY(PropertyInfo(Variant::INT, "light"), "set_light", "get_light"); // GLTFLightIndex
}
