tool
extends EditorPlugin

var ink_compiler_class : Script = preload("res://addons/godot-inkcpp/bin/InkCompiler.gdns")
var ink_story_class : Script = preload("res://addons/godot-inkcpp/bin/InkStory.gdns")

var compiler : EditorImportPlugin = null

func _enter_tree() -> void:
    compiler = ink_compiler_class.new()

    add_custom_type("InkStory", "Resource", ink_story_class, null)
    add_import_plugin(compiler)
    
func _exit_tree() -> void:
    remove_import_plugin(compiler)
    remove_custom_type("InkStory")
