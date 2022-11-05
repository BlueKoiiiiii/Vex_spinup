extends Node


# Declare member variables here. Examples:

const X_SIZE = 960
const Y_SIZE = 560

const GRID_INTERACT_SCRIPT = preload("res://Scripts/Grid/GridInteract.gd")


var sensorGrid = []

# Called when the node enters the scene tree for the first time.
func _ready():
	
	# Populate sensorGrid with GridInteracts
	for i in range(X_SIZE/40):
		sensorGrid.append([])
		for j in range(Y_SIZE/40):
			var newNode = ColorRect.new()
			newNode.set_position(Vector2(i*40, 560 - j*40))
			newNode.set_script(GRID_INTERACT_SCRIPT)
			newNode.posx = i
			newNode.posy = j
			newNode.set_name("cool")
			add_child(newNode)
			sensorGrid[i].append(newNode)

func _grid_pressed(posx, posy):
	print(posx, ", ", posy)
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
