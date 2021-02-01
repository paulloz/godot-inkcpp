tool
extends EditorPlugin

func _enter_tree() -> void:
    add_custom_type("InkStory", "Resource", preload("res://addons/godot-inkcpp/bin/gdinkcpp.gdns"), null)

func _exit_tree() -> void:
    remove_custom_type("InkStory")
