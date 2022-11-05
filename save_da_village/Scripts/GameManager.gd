extends Node


# Declare member variables here. Examples:

const X_SIZE = 960
const Y_SIZE = 560

const GRID_INTERACT_SCRIPT = preload("res://Scripts/Grid/GridInteract.gd")
const GRID_BLOCK_SIZE = 32

var sensorGrid = []

# Called when the node enters the scene tree for the first time.
func _ready():
	
	# Populate sensorGrid with GridInteracts
	for i in range(X_SIZE/GRID_BLOCK_SIZE):
		sensorGrid.append([])
		for j in range(Y_SIZE/GRID_BLOCK_SIZE):
			var newNode = ColorRect.new()
			newNode.set_position(Vector2(i*GRID_BLOCK_SIZE, 560 - j*GRID_BLOCK_SIZE))
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
