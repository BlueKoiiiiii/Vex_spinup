extends ColorRect


# Declare member variables here. Examples:
var posx : int
var posy : int


# Called when the node enters the scene tree for the first time.
func _ready():
	color = Color(color.r, color.g, color.b, 0) 			# transparent
	rect_size = Vector2(40, 40)
	connect("mouse_entered", self, "_on_mouse_entered")
	connect("mouse_exited", self, "_on_mouse_exited")

func _on_mouse_entered():
	color = Color(color.r, color.g, color.b, 93.0/255.0) 	# not transparent
															# In the future, stop hardcoding this! Make a variable.
	print("here")

func _on_mouse_exited():
	color = Color(color.r, color.g, color.b, 0) 			# transparent
	
	print("not here")
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
#func _process(delta):
#	pass
