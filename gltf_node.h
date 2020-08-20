#pragma once
#include "core/resource.h"
#include "gltf_document.h"

class GLTFNode : public Resource {
	GDCLASS(GLTFNode, Resource);

public:
	// matrices need to be transformed to this
	GLTFNodeIndex parent;
	int height;

	Transform xform;
	String name;

	GLTFMeshIndex mesh;
	GLTFCameraIndex camera;
	GLTFSkinIndex skin;

	GLTFSkeletonIndex skeleton;
	bool joint;

	Vector3 translation;
	Quat rotation;
	Vector3 scale;

	Vector<int> children;

	GLTFNodeIndex fake_joint_parent;

	GLTFLightIndex light;

	GLTFNode() :
			parent(-1), height(-1), mesh(-1), camera(-1), skin(-1), skeleton(-1), joint(false), translation(0, 0, 0), scale(Vector3(1, 1, 1)), fake_joint_parent(-1), light(-1) {}
};
