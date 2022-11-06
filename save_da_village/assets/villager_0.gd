extends KinematicBody2D

var rand = RandomNumberGenerator.new()
export(int) var speed = 40.0
var motion = Vector2()
var UP = Vector2(0,-1)


# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.
	
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	var motion = Vector2()
	movement.randomize()
	var move = movement.randf_range(-25, 25)
	motion.x += move

	move_and_slide(motion * speed)
