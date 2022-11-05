extends Node

onready var list_not_done = get_node("ToDoList")
onready var list_done = get_node("FinishedList")
onready var new_thing = get_node("TextEdit")
onready var empty_box = preload("res://assets/Envrioment/checks1.png")
onready var checked_box = preload("res://assets/Envrioment/checks2.png")

# Declare member variables here. Examples:
# var a = 2
# var b = "text"


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass





func _on_ItemList_item_activated(index):
	if(list_not_done.get_item_text(index) != "Make The Todo List"):
		list_done.add_item(list_not_done.get_item_text(index), checked_box, false)
		list_not_done.remove_item(index)
	
	# Bubble sort lmao, but true false
	#if()
#	list.add_icon_item(checked_box,false)


func _on_ItemList_item_selected(index):
	pass # Replace with function body.


func _on_Button_pressed():
	print("Hello world")
	var new_item = new_thing.get_line(0)
	list_not_done.add_item(new_item, empty_box, true)
	new_thing.text = ""
	
