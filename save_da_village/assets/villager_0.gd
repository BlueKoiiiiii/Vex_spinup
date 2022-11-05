extends KinematicBody2D

var motion = Vector2()
var movement = RandomNumberGenerator.new()

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.
	
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	movement.randomize()
	var move = movement.randf_range(-100, 100)
	motion.x = move
