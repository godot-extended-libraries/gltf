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
	void set_joints(Vector<GLTFNodeIndex> joints) {
		this->joints = joints;
	}


	Vector<GLTFNodeIndex> get_roots() {
		return this->roots;
	}
	void set_roots(Vector<GLTFNodeIndex> roots) {
		this->roots = roots;
	}


	// Skeleton *get_godot_skeleton() {
	// 	return this->godot_skeleton;
	// }
	// void set_godot_skeleton(Skeleton *godot_skeleton) {
	// 	this->godot_skeleton = godot_skeleton;
	// }


	Array get_unique_names() {
		return godot_conv::to_array(this->unique_names);
	}
	void set_unique_names(Array unique_names) {
		godot_conv::set_from_array(this->unique_names, unique_names);
	}


	//Map<int32_t, GLTFNodeIndex> get_godot_bone_node() {
	//	return this->godot_bone_node;
	//}
	//void set_godot_bone_node(Map<int32_t, GLTFNodeIndex> godot_bone_node) {
	//	this->godot_bone_node = godot_bone_node;
	//}
	Dictionary get_godot_bone_node() {
		return godot_conv::to_dict(this->godot_bone_node);
	}
	void set_godot_bone_node(Dictionary indict) {
		godot_conv::set_from_dict(this->godot_bone_node, indict);
	}

	//Dictionary get_godot_bone_node() {
	//	return godot_conv::to_dict(this->godot_bone_node);
	//}
	//void set_godot_bone_node(Dictionary indict) {
	//	godot_conv::set_from_dict(this->godot_bone_node, indict);
	//}



	// Vector<BoneAttachment *> get_bone_attachments() {
	// 	return this->bone_attachments;
	// }
	// void set_bone_attachments(Vector<BoneAttachment *> bone_attachments) {
	// 	this->bone_attachments = bone_attachments;
	// }

	GLTFSkeleton() :
			godot_skeleton(nullptr) {}
};
