/*************************************************************************/
/*  gltf_node.h                                                          */
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

#ifndef GLTF_NODE_H
#define GLTF_NODE_H

#include "core/io/resource.h"
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
	void set_parent(GLTFNodeIndex p_parent) {
		this->parent = p_parent;
	}

	int get_height() {
		return this->height;
	}
	void set_height(int p_height) {
		this->height = p_height;
	}

	Transform get_xform() {
		return this->xform;
	}
	void set_xform(Transform p_xform) {
		this->xform = p_xform;
	}

	GLTFMeshIndex get_mesh() {
		return this->mesh;
	}
	void set_mesh(GLTFMeshIndex p_mesh) {
		this->mesh = p_mesh;
	}

	GLTFCameraIndex get_camera() {
		return this->camera;
	}
	void set_camera(GLTFCameraIndex p_camera) {
		this->camera = p_camera;
	}

	GLTFSkinIndex get_skin() {
		return this->skin;
	}
	void set_skin(GLTFSkinIndex p_skin) {
		this->skin = p_skin;
	}

	GLTFSkeletonIndex get_skeleton() {
		return this->skeleton;
	}
	void set_skeleton(GLTFSkeletonIndex p_skeleton) {
		this->skeleton = p_skeleton;
	}

	bool get_joint() {
		return this->joint;
	}
	void set_joint(bool p_joint) {
		this->joint = p_joint;
	}

	Vector3 get_translation() {
		return this->translation;
	}
	void set_translation(Vector3 p_translation) {
		this->translation = p_translation;
	}

	Quat get_rotation() {
		return this->rotation;
	}
	void set_rotation(Quat p_rotation) {
		this->rotation = p_rotation;
	}

	Vector3 get_scale() {
		return this->scale;
	}
	void set_scale(Vector3 p_scale) {
		this->scale = p_scale;
	}

	Vector<int> get_children() {
		return this->children;
	}
	void set_children(Vector<int> p_children) {
		this->children = p_children;
	}

	GLTFNodeIndex get_fake_joint_parent() {
		return this->fake_joint_parent;
	}
	void set_fake_joint_parent(GLTFNodeIndex p_fake_joint_parent) {
		this->fake_joint_parent = p_fake_joint_parent;
	}

	GLTFLightIndex get_light() {
		return this->light;
	}
	void set_light(GLTFLightIndex p_light) {
		this->light = p_light;
	}

	GLTFNode() {}
};
#endif
