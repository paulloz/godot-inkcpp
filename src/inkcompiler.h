#ifndef INKCOMPILER_H
#define INKCOMPILER_H

#include <regex>
#include <sstream>

#include <EditorImportPlugin.hpp>
#include <File.hpp>
#include <Godot.hpp>
#include <Ref.hpp>
#include <ResourceSaver.hpp>
#include <ResourceLoader.hpp>

#include <compiler.h>

#include "inkstory.h"

namespace godot {

class InkCompiler : public EditorImportPlugin {
    GODOT_CLASS(InkCompiler, EditorImportPlugin)    
public:
    static void _register_methods();

    InkCompiler();
    ~InkCompiler();

    void _init();

    String get_importer_name();
    String get_visible_name();
    Array get_recognized_extensions();
    String get_save_extension();
    String get_resource_type();
    Array get_import_options(int);
    bool get_option_visibility(String, Dictionary);
    int get_preset_count();
    int import(String, String, Dictionary, Array, Array);
};

}

#endif // INKCOMPILER_H