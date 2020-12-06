/*************************************************************************/
/*  gltf_skin.cpp                                                        */
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

#include "gltf_skin.h"

void GLTFSkin::_bind_methods() {
	ClassDB::bind_method(D_METHOD("get_skin_root"), &GLTFSkin::get_skin_root);
	ClassDB::bind_method(D_METHOD("set_skin_root", "skin_root"), &GLTFSkin::set_skin_root);
	ClassDB::bind_method(D_METHOD("get_joints_original"), &GLTFSkin::get_joints_original);
	ClassDB::bind_method(D_METHOD("set_joints_original", "joints_original"), &GLTFSkin::set_joints_original);
	ClassDB::bind_method(D_METHOD("get_inverse_binds"), &GLTFSkin::get_inverse_binds);
	ClassDB::bind_method(D_METHOD("set_inverse_binds", "inverse_binds"), &GLTFSkin::set_inverse_binds);
	ClassDB::bind_method(D_METHOD("get_joints"), &GLTFSkin::get_joints);
	ClassDB::bind_method(D_METHOD("set_joints", "joints"), &GLTFSkin::set_joints);
	ClassDB::bind_method(D_METHOD("get_non_joints"), &GLTFSkin::get_non_joints);
	ClassDB::bind_method(D_METHOD("set_non_joints", "non_joints"), &GLTFSkin::set_non_joints);
	ClassDB::bind_method(D_METHOD("get_roots"), &GLTFSkin::get_roots);
	ClassDB::bind_method(D_METHOD("set_roots", "roots"), &GLTFSkin::set_roots);
	ClassDB::bind_method(D_METHOD("get_skeleton"), &GLTFSkin::get_skeleton);
	ClassDB::bind_method(D_METHOD("set_skeleton", "skeleton"), &GLTFSkin::set_skeleton);
	ClassDB::bind_method(D_METHOD("get_joint_i_to_bone_i"), &GLTFSkin::get_joint_i_to_bone_i);
	ClassDB::bind_method(D_METHOD("set_joint_i_to_bone_i", "joint_i_to_bone_i"), &GLTFSkin::set_joint_i_to_bone_i);
	ClassDB::bind_method(D_METHOD("get_joint_i_to_name"), &GLTFSkin::get_joint_i_to_name);
	ClassDB::bind_method(D_METHOD("set_joint_i_to_name", "joint_i_to_name"), &GLTFSkin::set_joint_i_to_name);
	ClassDB::bind_method(D_METHOD("get_godot_skin"), &GLTFSkin::get_godot_skin);
	ClassDB::bind_method(D_METHOD("set_godot_skin", "godot_skin"), &GLTFSkin::set_godot_skin);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "skin_root"), "set_skin_root", "get_skin_root"); // GLTFNodeIndex
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "joints_original"), "set_joints_original", "get_joints_original"); // Vector<GLTFNodeIndex>
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "inverse_binds", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_INTERNAL), "set_inverse_binds", "get_inverse_binds"); // Vector<Transform>
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "joints"), "set_joints", "get_joints"); // Vector<GLTFNodeIndex>
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "non_joints"), "set_non_joints", "get_non_joints"); // Vector<GLTFNodeIndex>
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "roots"), "set_roots", "get_roots"); // Vector<GLTFNodeIndex>
	ADD_PROPERTY(PropertyInfo(Variant::INT, "skeleton"), "set_skeleton", "get_skeleton"); // int
	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "joint_i_to_bone_i", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_INTERNAL), "set_joint_i_to_bone_i", "get_joint_i_to_bone_i"); // Map<int,
	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "joint_i_to_name", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_INTERNAL), "set_joint_i_to_name", "get_joint_i_to_name"); // Map<int,
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "godot_skin"), "set_godot_skin", "get_godot_skin"); // Ref<Skin>
}
