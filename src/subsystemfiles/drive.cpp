//
// Created by Daniel on 2022-08-07.
//

#include "main.h"
bool run_flywheel = false;
bool run_fast = false;
bool driveforward = true;
//int targetrpm = 550;
//double flypower = pow(targetrpm, 2) * 0.000003 + 0.0032 * targetrpm - 0.2616;


void op_indexer() {
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_R2)) {
        Indexer.move_absolute (100, 300);
        pros::delay (100);
        Indexer.move_absolute (10, 300);
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
        float kp = 0.55;
        float ki = 0.09;
        float kd = 0.085;
//PID Variables Here//
        double doublecurrentVelocity = Flywheel1.get_actual_velocity() + Flywheel2.get_actual_velocity();
        double currentVelocity = doublecurrentVelocity/2;
        int error = fast_target - currentVelocity;
        int lastError = 0;
        int totalError = 0;
        int integralActiveZone = 60;
        int currentFlywheelVoltage = 20;
        int onTargetCount = 0;
        float finalAdjustment = ((error * kp) + (totalError * ki) + ((error - lastError) * kd));

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

    if (run_flywheel) {
        //Constants//
        float kp = 0.30;
        float ki = 0.03;
        float kd = 0.05;
//PID Variables Here//
        double doublecurrentVelocity = Flywheel1.get_actual_velocity() + Flywheel2.get_actual_velocity();
        double currentVelocity = doublecurrentVelocity/2;
        int error = low_target - currentVelocity;
        int lastError = 0;
        int totalError = 0;
        int integralActiveZone = 60;
        int currentFlywheelVoltage = 20;
        int onTargetCount = 0;
        float finalAdjustment = ((error * kp) + (totalError * ki) + ((error - lastError) * kd));

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

void op_drive() {

    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_UP)){
        driveforward = true;
    }

   else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_DOWN)){
        driveforward = false;
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
        int power = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_Y);
        int turn = Master.get_analog(pros::E_CONTROLLER_ANALOG_LEFT_X);
        int Left = power + turn * -1;
        int Right = power - turn * -1;

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
