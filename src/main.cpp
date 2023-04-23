#include "main.h"

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
    static bool pressed = false;
    pressed = !pressed;
    if (pressed) {
        pros::lcd::set_text(2, "I was pressed!");
    } else {
        pros::lcd::clear_line(2);
    }
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
//    pros::lcd::initialize();
//    pros::lcd::register_btn1_cb(on_center_button);
    pros::delay(500);
//    autonomous();
//    LV_TICK_CUSTOM(5);
//    lv_init();
//    lv_obj_t * icon = lv_img_create(lv_scr_act(), NULL);
//    lv_img_set_src(icon, Capture);
//    lv_obj_t * icon = lv_img_create(lv_scr_act(), NULL);
//    lv_img_set_src(icon, "C:\Users\Daniel\Downloads\Capture.c");
    LV_IMG_DECLARE(converted_img_var);
//    lv_img_set_src(img1, &converted_img_var);
//    lv_img_set_src(icon, "C:\\Users\\Daniel\\Downloads\\Capture.c\");
//    LV_IMG_DECLARE(my_icon_dsc);
//    imu_sensor.reset();
//    pros::delay(2000);
//    imu_turnleft(270, 20);
////    imu_turnright(90, 20);
//    pros::delay(10000);
//    imu_sensor.reset();
//    imu_turnright(90, 10);
//    pros::delay(100000);
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    piston.set_value(false);
//    skills();
//    closeauton();
    std::ofstream Card;
    Card.open("/TuningValues.txt", std::ios_base::app);
    Card <<imu_sensor.get_heading()<<std::endl;


Master.set_text(0,0, std::to_string(imu_sensor.get_heading()));
farauton();
//worldcloseauton();
    Card.close();
//    Card.close();
//safefarauton();
//    far side (just roller)
//    DLFF.move(50);
//    DRFF.move(50);
//    DLF.move(50);
//    DRF.move(50);
//    DLB.move(50);
//    DRB.move(50);
//    pros::delay(1000);
//    DLFF.move(-50);
//    DRFF.move(50);
//    DLF.move(-50);
//    DRF.move(50);
//    DLB.move(-50);
//    DRB.move(50);
//    runintake();
//    pros::delay(700);
//    DLFF.move(-50);
//    DRFF.move(-50);
//    DLF.move(-50);
//    DRF.move(-50);
//    DLB.move(-50);
//    DRB.move(-50);
//    pros::delay(500);
//    DLFF.move(50);
//    DRFF.move(50);
//    DLF.move(50);
//    DRF.move(50);
//    DLB.move(50);
//    DRB.move(50);
//    pros::delay(200);
//    DLFF.move(0);
//    DRFF.move(0);
//    DLF.move(0);
//    DRF.move(0);
//    DLB.move(0);
//    DRB.move(0);


// far side (6 disc and roller)
//runreverseintake();
//Flywheel1.move_voltage(11000);
//    DLFF.move(50);
//    DRFF.move(50);
//    DLF.move(50);
//    DRF.move(50);
//    DLB.move(50);
//    DRB.move(50);
//    pros::delay(500);
//    DLFF.move(80);
//    DRFF.move(-80);
//    DLF.move(80);
//    DRF.move(-80);
//    DLB.move(80);
//    DRB.move(-80);
//    pros::delay(400);
//    runintake();
//    pros::delay(2000);
//    stopintake();
//    DLFF.move(-80);
//    DRFF.move(80);
//    DLF.move(-80);
//    DRF.move(80);
//    DLB.move(-80);
//    DRB.move(80);
//    pros::delay(800);
//    runreverseintake();
//    DLFF.move(50);
//    DRFF.move(50);
//    DLF.move(50);
//    DRF.move(50);
//    DLB.move(50);
//    DRB.move(50);
//    pros::delay(1000);
//    DLFF.move(80);
//    DRFF.move(-80);
//    DLF.move(80);
//    DRF.move(-80);
//    DLB.move(80);
//    DRB.move(-80);
//    pros::delay(500);
//    DLFF.move(0);
//    DRFF.move(0);
//    DLF.move(0);
//    DRF.move(0);
//    DLB.move(0);
//    DRB.move(0);
//    runintake();
//    pros::delay(1000);
//    runreverseintake();
//    DLFF.move(-80);
//    DRFF.move(-80);
//    DLF.move(-80);
//    DRF.move(-80);
//    DLB.move(-80);
//    DRB.move(-80);
//    pros::delay(1000);
//    DLFF.move(80);
//    DRFF.move(-80);
//    DLF.move(80);
//    DRF.move(-80);
//    DLB.move(80);
//    DRB.move(-80);
//    pros::delay(400);
//    DLFF.move(-50);
//    DRFF.move(-50);
//    DLF.move(-50);
//    DRF.move(-50);
//    DLB.move(-50);
//    DRB.move(-50);
//    pros::delay(500);
//    DLFF.move(0);
//    DRFF.move(0);
//    DLF.move(0);
//    DRF.move(0);
//    DLB.move(0);
//    DRB.move(0);















//    close side (5 disc and roller)







//skills























//close side (two roller, two disc)
//    runintake();
//    DLFF.move(-50);
//    DRFF.move(-50);
//    DLF.move(-50);
//    DRF.move(-50);
//    DLB.move(-50);
//    DRB.move(-50);
//    pros::delay(300);
//    DLFF.move(0);
//    DRFF.move(0);
//    DLF.move(0);
//    DRF.move(0);
//    DLB.move(0);
//    DRB.move(0);
//    stopintake();
//    DLF.move(30);
//    DLB.move(30);
//    DLFF.move(30);
//    DRF.move(-30);
//    DRB.move(-30);
//    DRFF.move(-30);
//    pros::delay(650);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    runreverseintake();
//    DLF.move(90);
//    DLB.move(90);
//    DLFF.move(90);
//    DRF.move(90);
//    DRB.move(90);
//    DRFF.move(90);
//    pros::delay(1400);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    pros::delay(2000);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(450);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    stopintake();
//    pros::delay(1000);
//    runintake();
//    pros::delay(4000);
//    stopintake();
//    Flywheel1.move(0);
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(-60);
//    DRB.move(-60);
//    DRFF.move(-60);
//    pros::delay(450);
//    runreverseintake();
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(1000);
//    runreverseintake();
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(500);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(-60);
//    DRB.move(-60);
//    DRFF.move(-60);
//    pros::delay(450);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//
//
//















//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(-60);
//    DRB.move(-60);
//    DRFF.move(-60);
//    pros::delay(450);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(4000);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    DLF.move(-60);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(500);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    runintake();
////    DLB.move(-60);
////    DLFF.move(-60);
////    DRF.move(60);
////    DRB.move(60);
////    DRFF.move(60);
////    pros::delay(380);
////    DLF.move(0);
////    DLB.move(0);
////    DLFF.move(0);
////    DRF.move(0);
////    DRB.move(0);
////    DRFF.move(0);
////
////
////    DRFF.move(50);
////    DRF.move(50);
////    DRB.move(50);
////    DLF.move(50);
////    DLFF.move(50);
////    DLB.move(50);
////    pros::delay(1000);
////    DRFF.move(0);
////    DRF.move(0);
////    DRB.move(0);
////    DLF.move(0);
//    DLFF.move(0);
//    DLB.move(0);
//
////    DRB
////    DRF.mo)ve(-20);
//    DRB.move(-20);
//    DRFF.move(-20);
//    pros::delay(900);
////    runreverseintake();
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//
//    far side
//    Flywheel1.move_velocity(600);
//    pros::delay(2000);
//    runintake();
//    pros::delay(2000);
//    stopintake();
//    pros::delay(2000);
//    runintake();

//    DLFF.move(40);
//    DLF.move(40);
//    DLB.move(40);
//    DRFF.move(40);
//    DRF.move(40);
//    DRB.move(40);
//    pros::delay(500);
//    //90 degree turn
//    DLFF.move(40);
//    DLF.move(40);
//    DLB.move(40);
//    DRFF.move(-40);
//    DRF.move(-40);
//    DRB.move(-40);
//    pros::delay(800);
//    DLFF.move(0);
//    DLF.move(0);
//    DLB.move(0);
//    DRFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//
//    DLFF.move(40);
//    DLF.move(40);
//    DLB.move(40);
//    DRFF.move(40);
//    DRF.move(40);
//    DRB.move(40);
//    pros::delay(1700);
//
//    DLFF.move(-40);
//    DLF.move(-40);
//    DLB.move(-40);
//    DRFF.move(40);
//    DRF.move(40);
//    DRB.move(40);
//    pros::delay(800);
//    DLFF.move(0);
//    DLF.move(0);
//    DLB.move(0);
//    DRFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//
//    runintake();
//    DLFF.move(-40);
//    DLF.move(-40);
//    DLB.move(-40);
//    DRFF.move(-40);
//    DRF.move(-40);
//    DRB.move(-40);
//    pros::delay(1000);
//    stopintake();
//    DLFF.move(40);
//    DLF.move(40);
//    DLB.move(40);
//    DRFF.move(40);
//    DRF.move(40);
//    DRB.move(40);
//    pidflywheel();
//    pros::delay(500);
//    DRFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    pros::delay(100);
//    DLFF.move(0);
//    DLF.move(0);
//    DLB.move(0);
//    pros::delay(2000);
//    runintake();


//    DLFF.move(40);
//    DLF.move(40);
//    DLB.move(40);
//    pros::delay(1200);
//    runreverseintake();
//    DRB.move(40);
//    DRF.move(40);
//    DRFF.move(40);
//    DLB.move(40);
//    DLF.move(40);
//    DLFF.move(40);
//    pros::delay(7000);
////    DRB.move(-50);
////    DRF.move(-50);
////    DRFF.move(-50);
////    DLB.move(-50);
////    DLF.move(-50);
////    DLFF.move(-50);
////    pros::delay(400);
////    DRB.move(30);
////    DRF.move(30);
////    DRFF.move(30);
////    DLB.move(30);
////    DLF.move(30);
////    DLFF.move(30);
////    pros::delay(3500);
//    DLB.move(-40);
//    DLF.move(-40);
//    DLFF.move(-40);
//    DRF.move(40);
//    DRFF.move(40);
//    DRB.move(40);
//    pros::delay(1000);
//    runintake();
//    DRF.move(0);
//    DRFF.move(0);
//    DRB.move(0);
//    DLF.move(0);
//    DLFF.move(0);
//    DLB.move(0);

//    pidturn(90, 4000);
//    sensors_reset();
//    pidturn(-90, 4100);
//    //closer side
//    runreverseintake();
//    pidforward(1);
//    pros::delay(200);
//    sensors_reset();
//    pros::delay(100);
//    pidreverse(3);
//    sensors_reset();
//    pros::delay(100);
////    pidturn(-0.35, 4000);
//    DLF.move(-50);
//    DRF.move(50);
//    DRB.move(50);
//    DLF.move(-50);
//    pros::delay(200);
//    DLF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DLF.move(0);
//    Flywheel1.move_velocity(600);
//    Flywheel2.move_velocity(600);
//    pros::delay(4500);
//    runindexer();
//    pros::delay(4000);
//    runindexer();
//    pros::delay(3000);
//    runindexer();
//    Flywheel1.move(0);
//    Flywheel2.move(0);

//    //farther side
//    sensors_reset();
//    pidforward(20);
//    sensors_reset();
//    pidturn(100, 3000);
//    sensors_reset();
//    pros::delay(100);
//    sensors_reset();
//    DLF.move(50);
//    DRF.move(50);
//    DLB.move(50);
//    DRB.move(50);
//    pros::delay(1000);
//    runreverseintake();
//    pros::delay(1000);

//skills
//    runreverseintake();
//    pidforward(1);
//    pros::delay(100);
//    sensors_reset();
//    pros::delay(100);
//    pidreverse(3);
//    sensors_reset();
//    pros::delay(100);
//    DLF.move(-50);
//    DRF.move(50);
//    DRB.move(50);
//    DLF.move(-50);
//    pros::delay(200);
//    DLF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DLF.move(0);
//    Flywheel1.move_velocity(550);
//    Flywheel2.move_velocity(550);
//    pros::delay(3000);
//    runindexer();
//    pros::delay(3000);
//    runindexer();
//    pros::delay(3000);
//    runindexer();
//    Flywheel1.move(0);
//    Flywheel2.move(0);
//    sensors_reset();
//    DLF.move(50);
//    DRF.move(-50);
//    DRB.move(-50);
//    DLF.move(50);
//    pros::delay(200);
//    DLF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DLF.move(0);
//    sensors_reset();
//    pidreverse(10);
//    sensors_reset();
//    DLF.move(-50);
//    DRF.move(-50);
//    DRB.move(50);
//    DLF.move(50);
//    pros::delay(1500);
//    DLF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DLF.move(0);
//    sensors_reset();
//    pidforward(50);
//    pros::delay(1000);
//    sensors_reset();
//    pidreverse(10);
//    DLF.move(-50);
//    DRF.move(50);
//    DRB.move(50);
//    DLF.move(-50);
//    pros::delay(1000);
//    DLF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DLF.move(0);
//    pidforward(160);
//    DLF.move(-50);
//    DRF.move(50);
//    DRB.move(50);
//    DLF.move(-50);
//    pros::delay(1000);
//    DLF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DLF.move(0);


//    piston.set_value(true);
//    pros::delay(1000);
//    piston.set_value(false);
////    runintake();
//    pidforward(40);
//    pros::delay(6000);
//    stopintake();
//    pidflywheel();
//    sensors_reset();
//    pidturn(-180);
//    Indexer.move_absolute(250, 300);
//    pros::delay(500);
//    Indexer.move_absolute(0, 300);
//    pros::delay(1000);
//    Indexer.move_absolute(250, 300);
//    pros::delay(500);
//    Indexer.move_absolute(0, 300);
//    pros::delay(1000);
//    Indexer.move_absolute(250, 300);
//    pros::delay(1000);
//    Indexer.move_absolute(0, 300);



//    pidforward(20);
//sensors_reset();
//pidturn(90);
//sensors_reset();
//pros::delay(10);
//pidturn(-90);
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
    while (true){
        Master.set_text(0,0, std::to_string(imu_sensor.get_heading()));
        pros::lcd::print (4, "Motor1 power: %f\n", Flywheel1.get_power());
        pros::lcd::print (6, "Motor1 RPM: %f\n", Flywheel1.get_actual_velocity());
//        pros::lcd::set_text(1, std::to_string(encoder_right.get_value()));
//        pros::lcd::set_text(2, std::to_string(encoder_left.get_value()));
//        pros::lcd::set_text(3, std::to_string(encoder_rear.get_value()));
//        pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
//        pros::lcd::set_text(
//        6, std::to_string(encoder_rear.get_value()));
//        pros::lcd::set_text(7, "hi!");
//        test_turn();
//            Flywheel1.move_velocity(600);
//            Flywheel2.move_velocity(600);
//        op_drive();
        op_drivesplitcubic();
//            op_logdrive();
//        op_flywheel(370, 475);
        flywheelop(8500, 12000);
//Flywheel1.move_voltage(10000);
//        op_indexer();
//        ArcadeDrive();
        op_intake();
        op_angler();
        opendgame();
//        std::ofstream Card;
//        Card.open("/usd/TuningValues.txt", std::ios_base::app);
//        Card << Flywheel1.get_power() << "\t" << Flywheel1.get_actual_velocity() <<std::endl;
//        Card.close();
//        pros::delay(50);


    }

}

//    float flywheelrpm = Flywheel1.get_actual_velocity() * 5;
//    while (true) {
//        op_flywheel();
//        op_indexer();
//        op_drive();
////        drivemotors();
////        setDrive();


//        pros::lcd::print (0, "Motor1 power: %f\n", Flywheel1.get_power());
//        pros::lcd::print (1, "Motor2 power: %f\n", Flywheel2.get_power());
//        pros::lcd::print (2, "Motor1 RPM: %f\n", Flywheel1.get_actual_velocity());
//        pros::lcd::print (3, "Motor2 RPM: %f\n", Flywheel2.get_actual_velocity());
//        pros::lcd::print (3, "Motor2 RPM: %f\n", Flywheel2.get_actual_velocity());
////        pros::lcd::set_text(6, std::to_string(currentFlywheelVoltage));
////        pros::lcd::print (4, "global position x: %f\n", globalposx);
//        pros::lcd::set_text(4, std::to_string(encoder_right.get_value()));
//        pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
//        pros::lcd::set_text(6, std::to_string(encoder_rear.get_value()));
//
//
//        pros::delay(50);
//    };
//};
