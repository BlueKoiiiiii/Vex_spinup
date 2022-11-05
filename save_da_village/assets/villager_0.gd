extends KinematicBody2D

var rand = RandomNumberGenerator.new()
export(int) var speed = 40.0
var motion = Vector2()
var UP = Vector2(0,-1)
var move = rand.randf_range(-100, 100)

# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.
	var timer := Timer.new()
	self.add_child(timer)
	timer.wait_time = 8
	timer.one_shot = true
	timer.start()
	timer.connect("timeout",self,"_on_timer_timeout")
	
	var move = rand.randf_range(-100, 100)
	
# Called every frame. 'delta' is the elapsed time since the previous frame.
func _physics_process(delta):
	#rand.randomize()
	#if is_on_floor() == true:
		#motion.y = 400
	#if is_on_floor() == false:
		#if motion.y <= 390:
			#motion.y += 98
			
	motion.x = move
	print(motion.x)
	move_and_slide(motion, UP)
	

func _on_timer_timeout():
	move = rand.randf_range(-100, 100)
	print(move)
