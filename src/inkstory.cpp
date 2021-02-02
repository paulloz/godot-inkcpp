#include "inkstory.h"

using namespace godot;

void InkStory::_register_methods()
{
	PoolByteArray pba;
	register_property<InkStory, PoolByteArray>("data", &InkStory::data, pba);

	register_method("load", &InkStory::load);
	register_method("can_continue", &InkStory::can_continue);
	register_method("has_choices", &InkStory::has_choices);
	register_method("continue", &InkStory::get_line);
	register_method("get_choices", &InkStory::get_choices);
}

InkStory::InkStory()
{
}

InkStory::~InkStory()
{
}

void InkStory::_init()
{
}

void InkStory::load()
{
	PoolByteArray::Read r = data.read();
	story = ink::runtime::story::from_binary((unsigned char *)r.ptr(), data.size());
	runner = story->new_runner();
}

bool InkStory::can_continue()
{
	return runner->can_continue();
}

bool InkStory::has_choices()
{
	return runner->has_choices();
}

String InkStory::get_line()
{
	return runner->getline().c_str();
}

Array InkStory::get_choices()
{
	Array choices;
	for (const ink::runtime::choice& choice : *runner) {
		choices.push_back(choice.text());
	}
	return choices;
}
