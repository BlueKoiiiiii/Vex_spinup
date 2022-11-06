extends Node

onready var list_not_done = get_node("ToDoList")
onready var list_done = get_node("FinishedList")
onready var new_thing = get_node("TextEdit")
onready var timers_master = get_node("timers")
onready var empty_box = preload("res://assets/Envrioment/checks1.png")
onready var checked_box = preload("res://assets/Envrioment/checks2.png")
onready var Points = get_node("/root/Node/InventoryRect/Points")
var identifier_arr
var identifier_num = int(0)
var rng = RandomNumberGenerator.new()
var gameManager

signal _die_die_die(points)
signal _add_points(points)
# totally not a reference to reaper... *flash backs*


# Called when the node enters the scene tree for the first time.
func _ready():
	gameManager = get_node("/root/Node/GameManager")
	rng.randomize()

func _on_ItemList_item_activated(index):
	var data = list_not_done.get_item_metadata(index-1)
#	print(data)

	if(list_not_done.get_item_text(index) != "Make The Todo List"):
		list_done.add_item(list_not_done.get_item_text(index), checked_box, false)
		list_not_done.remove_item(index)
		#Only add points if the timer exists
		if is_instance_valid(data[0]):
			emit_signal("_add_points", int(rng.randf_range(1, 5)))
#			print("WHY")
	
	#deleting da timer
	if is_instance_valid(data[0]):
		# Add points here
		data[0].queue_free()
	else:
		pass
	


func _on_ItemList_item_selected(index):
	pass # Replace with function body.


func _on_Button_pressed():
#	print("Hello world")
	var new_item = new_thing.get_line(0)
	var text = new_item.split(",")
	if(text.size() > 1):
		var times = text[1].split(":")
		list_not_done.add_item(text[0], empty_box, true)
		var timer := Timer.new()
		timers_master.add_child(timer)
		timer.wait_time = (int(times[0])*60*60 + int(times[1])*60)
		timer.one_shot = true
		timer.start()
		var q = int(0)
		for i in get_node("timers").get_children():
			i.connect("timeout",self,"_on_timer_timeout",[i])
			list_not_done.set_item_metadata(q, [i])
			q += 1
		new_thing.text = ""
	
func _on_timer_timeout(which):
	emit_signal("_die_die_die")
#	print("die")
	which.queue_free()

func _on_ItemList_item_activated2():
	pass # Replace with function body.


func _on_ItemList_item_selected2():
	pass # Replace with function body.
