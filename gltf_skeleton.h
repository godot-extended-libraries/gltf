#pragma once
#include "core/resource.h"
#include "gltf_document.h"

class GLTFSkeleton : public Resource {
	GDCLASS(GLTFSkeleton, Resource);

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

	GLTFSkeleton() :
			godot_skeleton(nullptr) {}
};
