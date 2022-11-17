//
// Created by Daniel on 2022-08-07.
//

#include "main.h"
bool run_flywheel = false;
bool run_fast = true;
bool driveforward = true;
bool run_intake = false;
int intakecounts = 1;
//int targetrpm = 550;
//double flypower = pow(targetrpm, 2) * 0.000003 + 0.0032 * targetrpm - 0.2616;


void op_indexer() {
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)) {
        Indexer.move_absolute (250, 300);
        pros::delay (500);
        Indexer.move_absolute (0, 300);
        pros::delay(100);
    }
}

void op_flywheel(int low_target, int fast_target) {
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

    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L1)){
        run_fast = true;
    }
    else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_L2)){
        run_fast = false;
    }
//
//    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
//        targetrpm = targetrpm + 50;
//        pros::delay(100);
//    }
//
//    if (Master.get_digital (pros::E_CONTROLLER_DIGITAL_DOWN)){
//        targetrpm = targetrpm - 50;
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

    if (run_flywheel and run_fast) {
        //Constants//
        float kp = 0.5;
        float ki = 0.002;
        float kd = 0.029;
//PID Variables Here//
        double doublecurrentVelocity = Flywheel1.get_actual_velocity() + Flywheel2.get_actual_velocity();
        double currentVelocity = doublecurrentVelocity/2;
        int fasterror = fast_target - currentVelocity;
        int lastfastError = 0;
        int totalfastError = 0;
        int integralfastActiveZone = 150;
        int currentfastFlywheelVoltage = 60;
        int onTargetCount = 0;
        float finalfastAdjustment = ((fasterror * kp) + (totalfastError * ki) + ((fasterror - lastfastError) * kd));

//Temp Variable//
        int deltaTime = 0;

                if (fasterror == 0)
                {
                    lastfastError = 0;
                }
                else{
                    lastfastError = fasterror;
                }

                if (abs(fasterror) < integralfastActiveZone and fasterror != 0)
                {
                    totalfastError += fasterror;
                }
                else
                {
                    totalfastError = 0;
                }

                finalfastAdjustment = ((fasterror * kp) + (totalfastError * ki) + ((fasterror - lastfastError) * kd));
                currentfastFlywheelVoltage = currentfastFlywheelVoltage + finalfastAdjustment;
        pros::lcd::set_text(8, "Fast");
        pros::lcd::set_text(1, std::to_string(fasterror));
        pros::lcd::set_text(2, std::to_string(totalfastError));

                Flywheel1.move(currentfastFlywheelVoltage);
                Flywheel2.move(currentfastFlywheelVoltage);
                pros::delay(10);
        std::ofstream Card;
        Card.open("/usd/TuningValues.txt", std::ios_base::app);
        Card << fasterror << "\t" << finalfastAdjustment << "\t" << currentfastFlywheelVoltage <<std::endl;
        Card.close();
            }

    else if (run_flywheel and not run_fast) {
        //Constants//
        float kp = 0.4;
        float ki = 0.03;
        float kd = 0.05;
//PID Variables Here//
        double doublecurrentVelocity = Flywheel1.get_actual_velocity() + Flywheel2.get_actual_velocity();
        double currentVelocity = doublecurrentVelocity/2;
        int error = low_target - currentVelocity;
        int lastError = 0;
        int totalError = 0;
        int integralActiveZone = 70;
        int currentFlywheelVoltage = 20;
        int onTargetCount = 0;
        float finalAdjustment = ((error * kp) + (totalError * ki) + ((error - lastError) * kd));
        pros::lcd::set_text(8, "Slow");
//Temp Variable//
        int deltaTime = 0;

        if (error == 0)
        {
            lastError = 0;
        }
        else{
            lastError = error;
        }

        if (abs(error) < integralActiveZone and error != 0)
        {
            totalError += error;
        }
        else
        {
            totalError = 0;
        }

        finalAdjustment = ((error * kp) + (totalError * ki) + ((error - lastError) * kd));
        currentFlywheelVoltage = currentFlywheelVoltage + finalAdjustment;

        pros::lcd::set_text(1, std::to_string(error));
        pros::lcd::set_text(2, std::to_string(totalerror));

        Flywheel1.move(currentFlywheelVoltage);
        Flywheel2.move(currentFlywheelVoltage);
        pros::delay(5);
        std::ofstream Card;
        Card.open("/usd/TuningValues.txt", std::ios_base::app);
        Card << error << "\t" << finalAdjustment << "\t" << currentFlywheelVoltage <<std::endl;
        Card.close();
    }
//        float currentvelocity = Flywheel1.get_actual_velocity() + Flywheel2.get_actual_velocity();
//        float actualcurrentvelocity = currentvelocity/2;
//        float error = 500 - actualcurrentvelocity;
//        float proportional = 0.07;
//        float integral = 0.03;
//        float proportionalerror = error * proportional;
//        float integralerror = error * integral;
//        float actualerror = proportionalerror;
//        float actualerror = proportionalerror + integralerror;
//        float flypower = 12000 * actualerror;
//        int flypower = 12000;
//        Flywheel1.move_voltage(flypower);
//        Flywheel2.move_voltage(flypower);
//        pros::lcd::set_text(6, std::to_string(flypower));
//        Flywheel1.move_velocity(550);
//        Flywheel2.move_velocity(550);

//        if(Flywheel1.get_actual_velocity()>500) {
//            Flywheel1.move_voltage(flypower * 1000);
//            Flywheel2.move_voltage(flypower * 1000);
//        }
//            else {
//            Flywheel1.move_voltage (12000);
//            Flywheel2.move_voltage (12000);
//            }

    else {
        Flywheel1.move (0);
        Flywheel2.move (0);
    }
}
void op_intake(){
    if(Master.get_digital(pros::E_CONTROLLER_DIGITAL_Y)){
        intakecounts = intakecounts + 1;
        pros::delay(200);
    }

    if (intakecounts % 2 == 0){
        run_intake = true;
    }
    else {
        run_intake = false;
    }
    if (run_intake){
        Intake.move(127);
    }
    else {
        Intake.move(0);
    }

}
void op_drive() {

    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)){
        driveforward = false;
    }

   else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R1)){
        driveforward = true;
    }
    if (driveforward) {
        int power = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int Left = power + turn;
        int Right = power - turn;

        DLF.move(Left * 0.7);
        DLB.move(Left * 0.7);
        DRF.move(Right * 0.7);
        DRB.move(Right * 0.7);
    }

    else {
//        int power = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int Left = turn;
        int Right = -turn;

        DLF.move(Left * 0.3);
        DLB.move(Left * 0.3);
        DRF.move(Right * 0.3);
        DRB.move(Right * 0.3);
    }
    }

    void test_turn() {
    bool pressed = false;
        if(Master.get_digital(pros::E_CONTROLLER_DIGITAL_A)){
            pressed = true;
        }
        if(Master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
            pressed = false;
        }

        if (pressed) {
            DLF.move(50);
            DLB.move(50);
            DRF.move(-50);
            DRB.move(-50);
        }
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
