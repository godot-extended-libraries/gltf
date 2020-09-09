#pragma once
#include "core/resource.h"
#include "gltf_document.h"

class GLTFNode : public Resource {
	GDCLASS(GLTFNode, Resource);

public:
	// matrices need to be transformed to this
	GLTFNodeIndex parent = -1;
	int height = -1;
	Transform xform;
	String name;
	GLTFMeshIndex mesh = -1;
	GLTFCameraIndex camera = -1;
	GLTFSkinIndex skin = -1;
	GLTFSkeletonIndex skeleton = -1;
	bool joint = false;
	Vector3 translation;
	Quat rotation;
	Vector3 scale = Vector3(1, 1, 1);
	Vector<int> children;
	GLTFNodeIndex fake_joint_parent = -1;
	GLTFLightIndex light = -1;
	GLTFNode() {}
};
