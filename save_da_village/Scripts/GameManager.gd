extends Node


# Declare member variables here. Examples:

const X_SIZE = 992
const Y_SIZE = 576

const GRID_INTERACT_SCRIPT = preload("res://Scripts/Grid/GridInteract.gd")
const GRID_BLOCK_SIZE = 32

var sensorGrid = []
var tileGrid = []
var tileMap

# Called when the node enters the scene tree for the first time.
func _ready():
	tileMap = get_node("/root/Node/TileMap")
	print(tileMap.cell_tile_origin)
	# Populate sensorGrid with GridInteracts
	for i in range(X_SIZE/GRID_BLOCK_SIZE + 1):
		sensorGrid.append([])
		tileGrid.append([])
		for j in range(Y_SIZE/GRID_BLOCK_SIZE + 1):
			var newNode = ColorRect.new()
			newNode.set_position(Vector2(i*GRID_BLOCK_SIZE, j*GRID_BLOCK_SIZE))
			newNode.set_script(GRID_INTERACT_SCRIPT)
			newNode.posx = i
			newNode.posy = j
			newNode.set_name("GRID " + str(i) + ", " + str(j))
			add_child(newNode)
			sensorGrid[i].append(newNode)
			
			tileGrid[i].append(tileMap.get_cell(i, j))
	
	# TODO: PREPROCESS THE CELLS IN TILEGRID TO SHOW WHAT RESOURCES, ETC THEY HAVE

func _grid_pressed(posx, posy):
	print(tileGrid[posx][posy])
	print(posx, ", ", posy)
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
