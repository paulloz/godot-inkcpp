#ifndef INKSTORY_H
#define INKSTORY_H

#include <Godot.hpp>
#include <PoolArrays.hpp>
#include <Resource.hpp>

#include <story.h>
#include <runner.h>
#include <choice.h>

namespace godot {

class InkStory : public Resource {
    GODOT_CLASS(InkStory, Resource)

public:
    // String path;
    static void _register_methods();

    InkStory();
    ~InkStory();

    void _init();

    void load();
    bool can_continue();
    String get_line();
    bool has_choices();
    Array get_choices();
    void print_data();

private:
    ink::runtime::story *story;
    ink::runtime::runner runner;
    PoolByteArray data;
};

}

#endif // INKSTORY_H
