#pragma once
#include "core/resource.h"
#include "gltf_document.h"

class GLTFNode : public Resource {
	GDCLASS(GLTFNode, Resource);

protected:
	static void _bind_methods();

public:
	// matrices need to be transformed to this
	GLTFNodeIndex parent = -1;
	int height = -1;
	Transform xform;
	//String name;
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

	GLTFNodeIndex get_parent() {
		return this->parent;
	}
	void set_parent(GLTFNodeIndex parent) {
		this->parent = parent;
	}

	int get_height() {
		return this->height;
	}
	void set_height(int height) {
		this->height = height;
	}

	Transform get_xform() {
		return this->xform;
	}
	void set_xform(Transform xform) {
		this->xform = xform;
	}

	//String get_name() {
	//	return this->name;
	//}
	//void set_name(String name) {
	//	this->name = name;
	//}

	GLTFMeshIndex get_mesh() {
		return this->mesh;
	}
	void set_mesh(GLTFMeshIndex mesh) {
		this->mesh = mesh;
	}

	GLTFCameraIndex get_camera() {
		return this->camera;
	}
	void set_camera(GLTFCameraIndex camera) {
		this->camera = camera;
	}

	GLTFSkinIndex get_skin() {
		return this->skin;
	}
	void set_skin(GLTFSkinIndex skin) {
		this->skin = skin;
	}

	GLTFSkeletonIndex get_skeleton() {
		return this->skeleton;
	}
	void set_skeleton(GLTFSkeletonIndex skeleton) {
		this->skeleton = skeleton;
	}

	bool get_joint() {
		return this->joint;
	}
	void set_joint(bool joint) {
		this->joint = joint;
	}

	Vector3 get_translation() {
		return this->translation;
	}
	void set_translation(Vector3 translation) {
		this->translation = translation;
	}

	Quat get_rotation() {
		return this->rotation;
	}
	void set_rotation(Quat rotation) {
		this->rotation = rotation;
	}

	Vector3 get_scale() {
		return this->scale;
	}
	void set_scale(Vector3 scale) {
		this->scale = scale;
	}

	Vector<int> get_children() {
		return this->children;
	}
	void set_children(Vector<int> children) {
		this->children = children;
	}

	GLTFNodeIndex get_fake_joint_parent() {
		return this->fake_joint_parent;
	}
	void set_fake_joint_parent(GLTFNodeIndex fake_joint_parent) {
		this->fake_joint_parent = fake_joint_parent;
	}

	GLTFLightIndex get_light() {
		return this->light;
	}
	void set_light(GLTFLightIndex light) {
		this->light = light;
	}

	GLTFNode() {}
};
