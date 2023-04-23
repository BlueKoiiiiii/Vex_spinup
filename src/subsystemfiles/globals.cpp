#include "main.h"

//    pros::Motor Flywheel1(6, pros::E_MOTOR_GEARSET_06, false, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor Flywheel2(21, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor Indexer(9, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor DLF(4, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor DRF(2, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor DLB(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor DRB(3, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Motor Intake(11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
//    pros::Controller Master (pros::E_CONTROLLER_MASTER);
//    pros::ADIEncoder encoder_right(3, 4, true);
//    pros::ADIEncoder encoder_left (1, 2, true);
//    pros::ADIEncoder encoder_rear (5, 6, true);
//    pros::ADIDigitalOut piston (7);
const int IMU_PORT = 4;
pros::Motor Flywheel1(18, pros::E_MOTOR_GEARSET_06, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Indexer(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLF(2, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DRF(17, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLB(1, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DRB(13, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DLFF(15, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor DRFF(14, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor Intake(6, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Imu imu_sensor(IMU_PORT);
//pros::Motor_Group rightside ({DRF, DRB, DRFF});
//pros::Motor_Group leftside ({DLF, DLB, DLFF});
pros::Controller Master (pros::E_CONTROLLER_MASTER);
//pros::ADIEncoder encoder_right(3, 4, true);
//pros::ADIEncoder encoder_left (1, 2, true);
//pros::ADIEncoder encoder_rear (5, 6, true);
pros::ADIDigitalOut piston (8);
pros::ADIDigitalOut endgame (6);

//
//void drivemotors(){
//    int x = abs(con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
//    int y = abs(con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
//
//    double LjoyY = y/10.0;
//    double LjoyX = x/10.0;
//    if ((y > 5) || (x > 5)) {
//        if (y > 85) {
//            Pwr = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyY - 6.0)))) * 10.0 - 3.0;
//        } else if (y > 55 && y <= 85) {
//            Pwr = (12.7 / (1.0 + exp(-(3.0 / 4.0) * (LjoyY - 6.0)))) * 10.0 - 10.0;
//        } else {
//            Pwr = 5*pow((1.0/5.5)*(LjoyY), 3.0) * 12.7;
//        }
//        if (x > 85) {
//            Trn = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyX - 6.0)))) * 10.0 - 3.0;
//        }
//        else if (x > 55 && x <= 85){
//            Trn = (12.7 / (1.0 + exp(-(3.0/4.0)*(LjoyX - 6.0)))) * 10.0 - 10.0;
//        } else {
//            Trn = 5*pow((1.0/5.5)*(LjoyX), 3.0) * 12.7;
//        }
//    }
//    else {
//        Pwr = 0;
//        Trn = 0;
//    }
//    if (con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) < 0){
//        Pwr = -Pwr;
//    }
//    if (con.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) < 0){
//        Trn = -Trn;
//    }
//    leftPower = Pwr + Trn * 0.8;
//    rightPower = Pwr - Trn * 0.8;
//    setDrive(leftPower, rightPower);
//}
