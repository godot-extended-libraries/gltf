#include "gltf_skeleton.h"




void GLTFSkeleton::_bind_methods() {

	ClassDB::bind_method(D_METHOD("get_joints"),  &GLTFSkeleton::get_joints);
	ClassDB::bind_method(D_METHOD("set_joints", "joints"),  &GLTFSkeleton::set_joints);
	ClassDB::bind_method(D_METHOD("get_roots"),  &GLTFSkeleton::get_roots);
	ClassDB::bind_method(D_METHOD("set_roots", "roots"),  &GLTFSkeleton::set_roots);
	// ClassDB::bind_method(D_METHOD("get_godot_skeleton"),  &GLTFSkeleton::get_*godot_skeleton);
	// ClassDB::bind_method(D_METHOD("set_godot_skeleton", "godot_skeleton"),  &GLTFSkeleton::set_godot_skeleton);
	ClassDB::bind_method(D_METHOD("get_unique_names"),  &GLTFSkeleton::get_unique_names);
	ClassDB::bind_method(D_METHOD("set_unique_names", "unique_names"),  &GLTFSkeleton::set_unique_names);
	ClassDB::bind_method(D_METHOD("get_godot_bone_node"),  &GLTFSkeleton::get_godot_bone_node);
	ClassDB::bind_method(D_METHOD("set_godot_bone_node", "godot_bone_node"),  &GLTFSkeleton::set_godot_bone_node);
	//ClassDB::bind_method(D_METHOD("get_bone_attachments"),  &GLTFSkeleton::get_bone_attachments);
	//ClassDB::bind_method(D_METHOD("set_bone_attachments", "bone_attachments"),  &GLTFSkeleton::set_bone_attachments);

	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "joints"), "set_joints", "get_joints"); // Vector<GLTFNodeIndex>
	ADD_PROPERTY(PropertyInfo(Variant::PACKED_INT32_ARRAY, "roots"), "set_roots", "get_roots"); // Vector<GLTFNodeIndex>
	// ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "*godot_skeleton"), "set_*godot_skeleton", "get_*godot_skeleton"); // Skeleton
	ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "unique_names", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_INTERNAL | PROPERTY_USAGE_EDITOR), "set_unique_names", "get_unique_names"); // Set<String>
	ADD_PROPERTY(PropertyInfo(Variant::DICTIONARY, "godot_bone_node", PROPERTY_HINT_NONE, "", PROPERTY_USAGE_STORAGE | PROPERTY_USAGE_INTERNAL | PROPERTY_USAGE_EDITOR), "set_godot_bone_node", "get_godot_bone_node"); // Map<int32_t,
	//ADD_PROPERTY(PropertyInfo(Variant::ARRAY, "bone_attachments"), "set_bone_attachments", "get_bone_attachments"); // Vector<BoneAttachment

}
