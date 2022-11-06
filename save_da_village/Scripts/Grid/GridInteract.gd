extends ColorRect


# Signals
signal grid_pressed(x, y)

# Declare member variables here. Examples:
var posx : int
var posy : int

var gameManager

# Block properties
var buildable  : bool
var surveyable : bool
var harvestable: bool
var difficultyMultiplier : int 
var health = 3 # Takes three hits to kill

var blockType : int 		# TODO: CREATE ENUM FOR BLOCK TYPES
var resources : Array 		# Each element is of the form ["RESOURCE_NAME", numberOfResources, baseCostInPoints]
var resourceYields : Array	# EXAMPLE: (RESOURCE_ID, 3600 seconds)

var associatedNeighbours : Array # Neighbours to delete upon destruction. Array of Vector2()s


# Called when the node enters the scene tree for the first time.
func _ready():
	gameManager = get_node("/root/Node/GameManager")
	
	color = Color(color.r, color.g, color.b, 0) 			# transparent
	rect_size = Vector2(40, 40)
	connect("mouse_entered", self, "_on_mouse_entered")
	connect("mouse_exited", self, "_on_mouse_exited")
	connect("gui_input", self, "_on_mouse_pressed")
	connect("grid_pressed", gameManager, "_grid_pressed")

func _set_variables(buildable_v, surveyable_v, harvestable_v, difficultyMultiplier_v, blockType_v, resources_v, resourceYields_v):
	buildable = buildable_v
	surveyable = surveyable_v
	harvestable = harvestable_v
	difficultyMultiplier = difficultyMultiplier_v
	blockType = blockType_v
	resources = resources_v
	resourceYields = resourceYields_v

func _on_mouse_entered():
	color = Color(color.r, color.g, color.b, 93.0/255.0) 	# not transparent
															# In the future, stop hardcoding this! Make a variable.
	#print("here")

func _on_mouse_exited():
	color = Color(color.r, color.g, color.b, 0) 			# transparent
	
	#print("not here")
	
func _on_mouse_pressed(event):
	if(event is InputEventMouseButton and event.button_index == 1 and event.pressed): # If the sprite is left-clicked
		emit_signal("grid_pressed", posx, posy)
		
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
