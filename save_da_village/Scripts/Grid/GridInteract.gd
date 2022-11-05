extends ColorRect


# Signals
signal grid_pressed(x, y)

# Declare member variables here. Examples:
var posx : int
var posy : int

var gameManager

# Called when the node enters the scene tree for the first time.
func _ready():
	gameManager = get_node("/root/Node/GameManager")
	
	color = Color(color.r, color.g, color.b, 0) 			# transparent
	rect_size = Vector2(40, 40)
	connect("mouse_entered", self, "_on_mouse_entered")
	connect("mouse_exited", self, "_on_mouse_exited")
	connect("gui_input", self, "_on_mouse_pressed")
	connect("grid_pressed", gameManager, "_grid_pressed")

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
