#ifndef INKSTORY_H
#define INKSTORY_H

#include <Godot.hpp>
#include <Resource.hpp>

#include <story.h>
#include <runner.h>
#include <choice.h>

namespace godot {

class InkStory : public Resource {
    GODOT_CLASS(InkStory, Resource)

public:
    static void _register_methods();

    InkStory();
    ~InkStory();
    void _init();
};

}

#endif // INKSTORY_H
