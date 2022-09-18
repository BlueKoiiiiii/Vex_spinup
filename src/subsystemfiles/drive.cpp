//
// Created by Daniel on 2022-08-07.
//

#include "main.h"
bool run_flywheel = false;
int flypower = 0;

void op_indexer() {
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        Indexer.move_absolute (200, 300);
        pros::delay (300);
        Indexer.move_absolute (0, 300);
    }
}
void op_flywheel() {
//    if (flypower > 127) {
//        flypower = 127;
//    }
//
//    if (flypower < 0) {
//        flypower = 0;
//    }

    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        run_flywheel = true;
    }
    else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        run_flywheel = false;
    }
//
    if (Flywheel1.get_actual_velocity()<450 and Flywheel2.get_actual_velocity()<450) {
        flypower = 12000;
    }

    else {
        flypower = 1378;
    }
//    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
//        flypower = flypower + 10;
//        pros::delay(100);
//    }
//
//    if (Master.get_digital (pros::E_CONTROLLER_DIGITAL_DOWN)){
//        flypower = flypower - 10;
//        pros::delay(100);
//    }
//
//    if (flypower > 127) {
//        flypower = 127;
//        pros::delay(50);
//    }
//
//    if (flypower < 0) {
//        flypower = 0;
//        pros::delay(50);
//    }

    if (run_flywheel) {
//        Flywheel1.move_velocity(550);
//        Flywheel2.move_velocity(550);
            Flywheel1.move_voltage (flypower);
            Flywheel2.move_voltage (flypower);
    }
    else {
        Flywheel1.move (0);
        Flywheel2.move (0);
    }
}

void op_drive() {
        int power = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int Left = power + turn;
        int Right = power - turn;

        DLF.move(Left);
        DLB.move(Left);
        DRF.move(Right);
        DRB.move(Right);
    }

//void setDrive(int left, int right){
//    DLF.move_voltage(left);
//    DRF.move_voltage(right);
//    DLB.move_voltage(left);
//    DRB.move_voltage(right);
//    DLF.move(left);
//    DRF.move(right);
//    DLB.move(left);
//    DRB.move(right);
//}
//
//double Pwr = 0;
//double Trn = 0;
//int leftPower = 0;
//int rightPower = 0;
//void drivemotors(){
//    int x = abs(Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X));
//    int y = abs(Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y));
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
//    if (Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y) < 0){
//        Pwr = -Pwr;
//    }
//    if (Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X) < 0){
//        Trn = -Trn;
//    }
//    leftPower = Pwr + Trn * 0.8;
//    rightPower = Pwr - Trn * 0.8;
//    setDrive(leftPower, rightPower);
//}
//
