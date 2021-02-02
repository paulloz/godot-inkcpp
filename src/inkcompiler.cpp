#include "inkcompiler.h"

using namespace godot;

void InkCompiler::_register_methods()
{
    register_method("get_importer_name", &InkCompiler::get_importer_name);
    register_method("get_visible_name", &InkCompiler::get_visible_name);
    register_method("get_recognized_extensions", &InkCompiler::get_recognized_extensions);
    register_method("get_save_extension", &InkCompiler::get_save_extension);
    register_method("get_resource_type", &InkCompiler::get_resource_type);
    register_method("get_import_options", &InkCompiler::get_import_options);
    register_method("get_option_visibility", &InkCompiler::get_option_visibility);
    register_method("get_preset_count", &InkCompiler::get_preset_count);
    register_method("import", &InkCompiler::import);
}

InkCompiler::InkCompiler()
{
}

InkCompiler::~InkCompiler()
{
}

void InkCompiler::_init()
{
}

String InkCompiler::get_importer_name()
{
    return "ink";
}

String InkCompiler::get_visible_name()
{
    return "Ink story";
}

Array InkCompiler::get_recognized_extensions()
{
    Array extensions;
    extensions.push_back("json");
    return extensions;
}

String InkCompiler::get_save_extension()
{
    return "res";
}

String InkCompiler::get_resource_type()
{
    return "Resource";
}

Array InkCompiler::get_import_options(int preset)
{
    Array options;
    return options;
}

bool InkCompiler::get_option_visibility(String option, Dictionary options)
{
    return true;
}

int InkCompiler::get_preset_count()
{
    return 0;
}

int InkCompiler::import(String source_file, String save_path, Dictionary options, Array platform_variants, Array gen_files)
{
    ink::compiler::compilation_results results;
    std::stringstream out(std::ios::binary | std::ios::out);
    std::string path = std::regex_replace(source_file.alloc_c_string(), std::regex("res\\:\\/\\/"), "");
    ink::compiler::run(path.c_str(), out, &results);

    for (auto& warn : results.warnings) {
        WARN_PRINT(warn.c_str());
    }
    for (auto& error : results.errors) {
        ERR_PRINT(error.c_str());
    }

    if (results.errors.size() > 0) {
        return GODOT_ERR_COMPILATION_FAILED;
    }

    Ref<Resource> res = Resource::_new();
    Ref<Resource> script = ResourceLoader::get_singleton()->load("res://addons/godot-inkcpp/bin/InkStory.gdns");
    res->set_script(script.ptr());
    PoolByteArray pba;
    std::string data = out.str();
    pba.resize(data.size());
    for (std::string::size_type i = 0; i < data.size(); ++i) {
        pba.set(i, data[i]);
    }
    res->set("data", pba);
    ResourceSaver::get_singleton()->save(save_path + "." + get_save_extension(), res, ResourceSaver::SaverFlags::FLAG_COMPRESS);

    return GODOT_OK;
}
