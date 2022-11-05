extends Node


# Declare member variables here. Examples:
var initialized = false

const X_SIZE = 992
const Y_SIZE = 576

const GRID_INTERACT_SCRIPT = preload("res://Scripts/Grid/GridInteract.gd")
const GRID_BLOCK_SIZE = 32

const MENU_BUTTON_WIDTH = 80
const MENU_BUTTON_HEIGHT = 100

# Game State Variables
var sensorGrid = []
var tileGrid = []

# Node references
var tileMap
var contextMenu

# Inventory
var Inventory = {
	"points"    : 10,
	"population": 1,
	"gold"      : 100,
	"wood"      : 20,
	"stone"     : 20
}

var menuItems

# Called when the node enters the scene tree for the first time.
func _ready():
	# Initialize Inventory Menu
	menuItems = {
		"points"    : get_node("/root/Node/InventoryRect/Points"),
		"population": get_node("/root/Node/InventoryRect/Population"),
		"gold"      : get_node("/root/Node/InventoryRect/Gold"),
		"stone"     : get_node("/root/Node/InventoryRect/Stone"),
		"wood"      : get_node("/root/Node/InventoryRect/Wood")
	}
	
	tileMap = get_node("/root/Node/TileMap")
	contextMenu = get_node("/root/Node/ContextMenu")
	print(tileMap.cell_tile_origin)
	# Populate sensorGrid with GridInteracts
	for i in range(X_SIZE/GRID_BLOCK_SIZE + 1):
		sensorGrid.append([])
		tileGrid.append([])
		for j in range(Y_SIZE/GRID_BLOCK_SIZE + 1):
			tileGrid[i].append(tileMap.get_cell(i, j))
			
			var newNode = ColorRect.new()
			newNode.set_position(Vector2(i*GRID_BLOCK_SIZE, j*GRID_BLOCK_SIZE))
			newNode.set_script(GRID_INTERACT_SCRIPT)
			newNode.posx = i
			newNode.posy = j
			newNode.set_name("GRID " + str(i) + ", " + str(j))
			newNode._set_variables((tileGrid[i][j] in [6, 7, 11]), true, (tileGrid[i][j] in [6, 7, 11]), 1 + 4*int(tileGrid[i][j] in [15, 16, 19]) + 2*int(tileGrid[i][j] in [17, 18, 20, 21]), tileGrid[i][j], [], [])
			add_child(newNode)
			sensorGrid[i].append(newNode)
			
			
	contextMenu.visible = false
	Inventory["points"] += 1
	# TODO: PREPROCESS THE CELLS IN TILEGRID TO SHOW WHAT RESOURCES, ETC THEY HAVE
	
	initialized = true

func _grid_pressed(posx, posy):
	print(sensorGrid[posx][posy].difficultyMultiplier)
	print(posx, ", ", posy)
	contextMenu.visible = true
	contextMenu.set_position(Vector2(min(get_viewport().get_mouse_position().x, X_SIZE - MENU_BUTTON_WIDTH), min(get_viewport().get_mouse_position().y, Y_SIZE - MENU_BUTTON_HEIGHT)))
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	for key in menuItems:
		menuItems[key].text = key + ": " + str(Inventory[key])


func _on_CancelButton_pressed():
	contextMenu.visible = false
