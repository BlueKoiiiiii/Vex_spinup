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
    pros::lcd::initialize();
    pros::lcd::register_btn1_cb(on_center_button);
    autonomous();
    pros::delay(500);
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
        pros::lcd::print (3, "Motor1 power: %f\n", Flywheel1.get_power());
        pros::lcd::print (4, "Motor2 power: %f\n", Flywheel2.get_power());
        pros::lcd::print (5, "Motor1 RPM: %f\n", Flywheel1.get_actual_velocity());
//        pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
//        pros::lcd::set_text(
//        6, std::to_string(encoder_rear.get_value()));
//        pros::lcd::set_text(7, "hi!");
//        test_turn();
//            Flywheel1.move_velocity(600);
//            Flywheel2.move_velocity(600);
        op_flywheel(400, 600);
        op_indexer();
        op_drive();
        pros::delay(50);


    }

}
//    std::ofstream Card;
//    float flywheelrpm = Flywheel1.get_actual_velocity() * 5;
//    while (true) {
//        op_flywheel();
//        op_indexer();
//        op_drive();
////        drivemotors();
////        setDrive();
//        Card.open("/usd/TuningValues.txt", std::ios_base::app);
//        Card << Flywheel1.get_power() << "\t" << Flywheel1.get_actual_velocity() <<std::endl;
//        Card.close();
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
