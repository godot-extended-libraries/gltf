#pragma once
#include "core/resource.h"
#include "gltf_document.h"
#include "godot_conversion_operators.h"

class GLTFSkeleton : public Resource {
	GDCLASS(GLTFSkeleton, Resource);

protected:
	static void _bind_methods();

public:
	// The *synthesized* skeletons joints
	Vector<GLTFNodeIndex> joints;

	// The roots of the skeleton. If there are multiple, each root must have the
	// same parent (ie roots are siblings)
	Vector<GLTFNodeIndex> roots;

	// The created Skeleton for the scene
	Skeleton *godot_skeleton;

	// Set of unique bone names for the skeleton
	Set<String> unique_names;

	Map<int32_t, GLTFNodeIndex> godot_bone_node;

	Vector<BoneAttachment *> bone_attachments;


	Vector<GLTFNodeIndex> get_joints() {
		return this->joints;
	}
	void set_joints(Vector<GLTFNodeIndex> p_joints) {
		this->joints = p_joints;
	}


	Vector<GLTFNodeIndex> get_roots() {
		return this->roots;
	}
	void set_roots(Vector<GLTFNodeIndex> p_roots) {
		this->roots = p_roots;
	}


	// Skeleton *get_godot_skeleton() {
	// 	return this->godot_skeleton;
	// }
	// void set_godot_skeleton(Skeleton p_*godot_skeleton) {
	// 	this->godot_skeleton = p_godot_skeleton;
	// }


	Array get_unique_names() {
		return godot_conv::to_array(this->unique_names);
	}
	void set_unique_names(Array p_unique_names) {
		godot_conv::set_from_array(this->unique_names, p_unique_names);
	}


	//Map<int32_t, GLTFNodeIndex> get_godot_bone_node() {
	//	return this->godot_bone_node;
	//}
	//void set_godot_bone_node(Map<int32_t, GLTFNodeIndex> p_godot_bone_node) {
	//	this->godot_bone_node = p_godot_bone_node;
	//}
	Dictionary get_godot_bone_node() {
		return godot_conv::to_dict(this->godot_bone_node);
	}
	void set_godot_bone_node(Dictionary p_indict) {
		godot_conv::set_from_dict(this->godot_bone_node, p_indict);
	}

	//Dictionary get_godot_bone_node() {
	//	return godot_conv::to_dict(this->godot_bone_node);
	//}
	//void set_godot_bone_node(Dictionary p_indict) {
	//	godot_conv::set_from_dict(this->godot_bone_node, p_indict);
	//}



	// Vector<BoneAttachment *> get_bone_attachments() {
	// 	return this->bone_attachments;
	// }
	// void set_bone_attachments(Vector<BoneAttachment *> p_bone_attachments) {
	// 	this->bone_attachments = p_bone_attachments;
	// }

	GLTFSkeleton() :
			godot_skeleton(nullptr) {}
};
