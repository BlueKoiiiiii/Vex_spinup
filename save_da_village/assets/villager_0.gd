extends KinematicBody2D

onready var animation = get_node("frames")

var rand = RandomNumberGenerator.new()
export(int) var speed = 40.0
var motion = Vector2()
var UP = Vector2(0,-1)
var move
var autostart = false

var timer_ref

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.
	var timer := Timer.new()
	self.add_child(timer)
	timer.wait_time = 2
	timer.one_shot = true
	timer.start()
	timer.connect("timeout",self,"_on_timer_timeout")
	timer.autostart = true
	timer_ref = timer
	rand.randomize()
	move = rand.randf_range(-100, 100)
	
	if(move < 0):
		animation.flip_h = false
	else:
		animation.flip_h = true
	
	var char_selector = rand.randf_range(1,6)
#	print(char_selector)
	animation.animation = str(int(char_selector))
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	if is_on_floor() == true:
		motion.y = 400
	if is_on_floor() == false:
		if motion.y <= 390:
			motion.y += 98
	
#	print(timer_ref.is_stopped())
	
	motion.x = move
#	print(motion.x)
	move_and_slide(motion, UP)
	
func _on_timer_timeout():
	move = rand.randf_range(-100, 100)
	if(move < 0):
		animation.flip_h = false
	else:
		animation.flip_h = true
	timer_ref.start()
