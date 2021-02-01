extends VBoxContainer

var story = load("res://TheIntercept.tres")

func _ready():
    add_child(HSeparator.new())
    story.load()
    for _i in range(100):
        if story.can_continue():
            continue_story()
        elif story.has_choices():
            display_choices(story.get_choices())
        else:
            # this is probably the end of the story
            add_child(HSeparator.new())
            break

func continue_story() -> void:
    var new_line : String = story.continue().strip_edges()
    if not len(new_line):
        return
    var label : Label = Label.new()
    label.align = ALIGN_CENTER
    label.text = new_line
    add_child(label)

func display_choices(choices : Array) -> void:
    for choice in choices:
        var button : Button = Button.new()
        button.text = choice
        add_child(button)
