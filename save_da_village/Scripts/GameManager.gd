extends Node


# Declare member variables here. Examples:
const X_SIZE = 992
const Y_SIZE = 576

const GRID_INTERACT_SCRIPT = preload("res://Scripts/Grid/GridInteract.gd")
const GRID_BLOCK_SIZE = 32

const MENU_BUTTON_WIDTH = 80
const MENU_BUTTON_HEIGHT = 100

# Game State Variables
var sensorGrid = []
var tileGrid = []
var selected = Vector2(0, 0)

# Node references
var tileMap
var contextMenu
var label

# Preloading villagers for when they will be spawned in
const villager_base = preload("res://assets/villager0.tscn")

# Inventory
var Inventory = {
	"points"    : 10,
	"population": 1,
	"gold"      : 100,
	"wood"      : 20,
	"stone"     : 20
} # TODO: ADD FOOD


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
	label = get_node("/root/Node/Label")
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
			newNode._set_variables((tileGrid[i][j] in [6, 7, 11]), true, (tileGrid[i][j] in [6, 7, 11]), 1 + 4*int(tileGrid[i][j] in [15, 16, 19]) + 2*int(tileGrid[i][j] in [17, 18, 20, 21]), tileGrid[i][j], [["stone", 5*int(tileGrid[i][j] != -1), 1]], [])
			add_child(newNode)
			sensorGrid[i].append(newNode)
			
			
	contextMenu.visible = false
	Inventory["points"] += 1
	# TODO: PREPROCESS THE CELLS IN TILEGRID TO SHOW WHAT RESOURCES, ETC THEY HAVE



func _grid_pressed(posx, posy):
	print(sensorGrid[posx][posy].difficultyMultiplier)
	print(posx, ", ", posy)
	selected = Vector2(posx, posy)
	contextMenu.visible = true
	contextMenu.set_position(Vector2(min(get_viewport().get_mouse_position().x, X_SIZE - MENU_BUTTON_WIDTH), min(get_viewport().get_mouse_position().y, Y_SIZE - MENU_BUTTON_HEIGHT)))
	pass

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	for key in menuItems:
		menuItems[key].text = key + ": " + str(Inventory[key])
	




func _on_CancelButton_pressed():
	contextMenu.visible = false


func _on_BuildButton_pressed():
	pass



func _on_HarvestButton_pressed():
	# TODO: PICK RANDOM ITEM FROM SELECTED RESOURCE YIELDS
	var yield_r = sensorGrid[selected.x][selected.y].resources[0]
	if(sensorGrid[selected.x][selected.y].harvestable == false):
		label.text = "That block cannot be harvested!"
		label.modulate.a = 1
		return
	if(yield_r == null):
		return
	if(Inventory["points"] < yield_r[2]*sensorGrid[selected.x][selected.y].difficultyMultiplier):
		label.text = "Not enough points."
		label.modulate.a = 1
		return
	Inventory["points"] -= yield_r[2]*sensorGrid[selected.x][selected.y].difficultyMultiplier
	Inventory[yield_r[0]] += yield_r[1]
	sensorGrid[selected.x][selected.y].health -= 1
	label.text = "Successfully harvested resource. It has been damaged."
	label.modulate.a = 1
	if(sensorGrid[selected.x][selected.y].health == 0):
		print("Destroy Block!") #to do: destroy block!
		tileMap.set_cell(selected.x, selected.y, -1)
		sensorGrid[selected.x][selected.y+1].harvestable = true
		sensorGrid[selected.x][selected.y+1].buildable = true
		sensorGrid[selected.x][selected.y].harvestable = false
		sensorGrid[selected.x][selected.y].buildable = false
		for neighbour in sensorGrid[selected.x][selected.y].associatedNeighbours:
			tileMap.set_cell(neighbour.x, neighbour.y, -1)
			sensorGrid[neighbour.x][neighbour.y+1].harvestable = true
			sensorGrid[neighbour.x][neighbour.y+1].buildable = true
			sensorGrid[neighbour.x][neighbour.y].harvestable = false
			sensorGrid[neighbour.x][neighbour.y].buildable = false
	
	contextMenu.visible = false



func _on_Node__add_points(points):
	var new_vill = villager_base.instance()
	add_child(new_vill)
	Inventory["points"] += points
	print("uh ok")
	var text = str(points)
	label.text = "You got " + text + " points!"
	label.modulate.a = 1
	

	# Also add in 1-3 villagers
	print("Hello world?")
	
