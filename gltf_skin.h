#pragma once
#include "core/resource.h"
#include "gltf_document.h"
#include "godot_conversion_operators.h"

class GLTFSkin : public Resource {
	GDCLASS(GLTFSkin, Resource);

protected:
	static void _bind_methods();

public:
	String name;

	// The "skeleton" property defined in the gltf spec. -1 = Scene Root
	GLTFNodeIndex skin_root;

	Vector<GLTFNodeIndex> joints_original;
	Vector<Transform> inverse_binds;

	// Note: joints + non_joints should form a complete subtree, or subtrees
	// with a common parent

	// All nodes that are skins that are caught in-between the original joints
	// (inclusive of joints_original)
	Vector<GLTFNodeIndex> joints;

	// All Nodes that are caught in-between skin joint nodes, and are not
	// defined as joints by any skin
	Vector<GLTFNodeIndex> non_joints;

	// The roots of the skin. In the case of multiple roots, their parent *must*
	// be the same (the roots must be siblings)
	Vector<GLTFNodeIndex> roots;

	// The GLTF Skeleton this Skin points to (after we determine skeletons)
	GLTFSkeletonIndex skeleton;

	// A mapping from the joint indices (in the order of joints_original) to the
	// Godot Skeleton's bone_indices
	Map<int, int> joint_i_to_bone_i;
	Map<int, StringName> joint_i_to_name;

	// The Actual Skin that will be created as a mapping between the IBM's of
	// this skin to the generated skeleton for the mesh instances.
	Ref<Skin> godot_skin;


	GLTFNodeIndex get_skin_root() {
		return this->skin_root;
	}
	void set_skin_root(GLTFNodeIndex p_skin_root) {
		this->skin_root = p_skin_root;
	}


	Vector<GLTFNodeIndex> get_joints_original() {
		return this->joints_original;
	}
	void set_joints_original(Vector<GLTFNodeIndex> p_joints_original) {
		this->joints_original = p_joints_original;
	}


	Array get_inverse_binds() {
		return godot_conv::to_array(this->inverse_binds);
	}
	void set_inverse_binds(Array p_inverse_binds) {
		godot_conv::set_from_array(this->inverse_binds, p_inverse_binds);
	}


	Vector<GLTFNodeIndex> get_joints() {
		return this->joints;
	}
	void set_joints(Vector<GLTFNodeIndex> p_joints) {
		this->joints = p_joints;
	}

	
	Vector<GLTFNodeIndex> get_non_joints() {
		return this->non_joints;
	}
	void set_non_joints(Vector<GLTFNodeIndex> p_non_joints) {
		this->non_joints = p_non_joints;
	}


	Vector<GLTFNodeIndex> get_roots() {
		return this->roots;
	}
	void set_roots(Vector<GLTFNodeIndex> p_roots) {
		this->roots = p_roots;
	}


	int get_skeleton() {
		return this->skeleton;
	}
	void set_skeleton(int p_skeleton) {
		this->skeleton = p_skeleton;
	}


	Dictionary get_joint_i_to_bone_i() {
		return godot_conv::to_dict(this->joint_i_to_bone_i);
	}
	void set_joint_i_to_bone_i(Dictionary p_joint_i_to_bone_i) {
		godot_conv::set_from_dict(this->joint_i_to_bone_i, p_joint_i_to_bone_i);
	}


	Dictionary get_joint_i_to_name() {
		Dictionary ret;
		Map<int, StringName>::Element *elem = joint_i_to_name.front();
		while (elem) {
			ret[elem->key()] = String(elem->value());
			elem = elem->next();
		}
		return ret;
	}
	void set_joint_i_to_name(Dictionary p_joint_i_to_name) {
		this->joint_i_to_name = Map<int, StringName>();
		Array keys = p_joint_i_to_name.keys();
		for (int i = 0; i < keys.size(); i++) {
			this->joint_i_to_name[keys[i]] = StringName(p_joint_i_to_name[keys[i]]);
		}
	}


	Ref<Skin> get_godot_skin() {
		return this->godot_skin;
	}
	void set_godot_skin(Ref<Skin> p_godot_skin) {
		this->godot_skin = p_godot_skin;
	}

	GLTFSkin() :
			skin_root(-1), skeleton(-1) {}
};

