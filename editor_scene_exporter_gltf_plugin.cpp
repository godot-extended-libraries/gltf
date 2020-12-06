/*************************************************************************/
/*  editor_scene_exporter_gltf_plugin.cpp                                */
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

#include "editor_scene_exporter_gltf_plugin.h"
#include "core/config/project_settings.h"
#include "core/object/object.h"
#include "core/templates/vector.h"
#include "editor/editor_file_system.h"
#include "scene/3d/mesh_instance_3d.h"
#include "scene/gui/check_box.h"
#include "scene/main/node.h"

#include "editor/editor_node.h"

#ifndef _3D_DISABLED
String SceneExporterGLTFPlugin::get_name() const {
	return "ConvertGLTF2";
}

void SceneExporterGLTFPlugin::_bind_methods() {
	ClassDB::bind_method("_gltf2_dialog_action", &SceneExporterGLTFPlugin::_gltf2_dialog_action);
	ClassDB::bind_method(D_METHOD("convert_scene_to_gltf2"), &SceneExporterGLTFPlugin::convert_scene_to_gltf2);
}

void SceneExporterGLTFPlugin::_notification(int notification) {
	String gltf_scene_name = TTR("Export GLTF...");
	if (notification == NOTIFICATION_ENTER_TREE) {
		editor->add_tool_menu_item(gltf_scene_name, this, "convert_scene_to_gltf2");
	} else if (notification == NOTIFICATION_EXIT_TREE) {
		editor->remove_tool_menu_item(gltf_scene_name);
	}
}

bool SceneExporterGLTFPlugin::has_main_screen() const {
	return false;
}

SceneExporterGLTFPlugin::SceneExporterGLTFPlugin(EditorNode *p_node) {
	editor = p_node;
	convert_gltf2.instance();
}

void SceneExporterGLTFPlugin::_gltf2_dialog_action(String p_file) {
	Node *root = editor->get_tree()->get_edited_scene_root();
	if (!root) {
		editor->show_accept(TTR("This operation can't be done without a scene."), TTR("OK"));
		return;
	}
	List<String> deps;
	convert_gltf2->save_scene(root, p_file, p_file, 0, 1000.0f, &deps);
	EditorFileSystem::get_singleton()->scan_changes();
	file_export_lib->queue_delete();
}

void SceneExporterGLTFPlugin::convert_scene_to_gltf2(Variant p_user_data) {
	file_export_lib = memnew(EditorFileDialog);
	file_export_lib->set_title(TTR("Export Library"));
	file_export_lib->set_file_mode(EditorFileDialog::FILE_MODE_SAVE_FILE);
	file_export_lib->set_access(EditorFileDialog::ACCESS_FILESYSTEM);
	editor->get_gui_base()->add_child(file_export_lib);
	file_export_lib->clear_filters();
	file_export_lib->add_filter("*.glb");
	file_export_lib->add_filter("*.gltf");
	file_export_lib->popup_centered_ratio();
	file_export_lib->set_title(TTR("Export Mesh GLTF2"));
	Node *root = editor->get_tree()->get_edited_scene_root();
	if (!root) {
		editor->show_accept(TTR("This operation can't be done without a scene."), TTR("OK"));
		return;
	}
	String filename = String(root->get_filename().get_file().get_basename());
	if (filename.empty()) {
		filename = root->get_name();
	}
	file_export_lib->set_current_file(filename + String(".gltf"));
	file_export_lib->connect_compat("file_selected", this, "_gltf2_dialog_action");
}
#endif
