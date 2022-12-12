//
// Created by Daniel on 2022-10-13.
//
#include "main.h"
float power = 4000;
//float turnpower = 1800;
float totalerror = 0;

void sensors_reset(){
    encoder_left.reset();
    encoder_right.reset();
}
void pidreverse(int inches){
    int halftarget = inches / 0.024;
    int target = halftarget * 2;
    while (true) {
        pros::lcd::set_text(6, std::to_string(target));
        double leftcounts = encoder_right.get_value();
        double rightcounts = encoder_left.get_value();
        int globalposx = leftcounts + rightcounts;
        double error = target + abs(globalposx);
        int lastError = 0;
//    double globalpos = globalposx + encoderGet(encoder_rear);
        float P = 0.05;
        float I = 0.005;
        float D = 0.02;
        int integralactivezone = 75;
        float gain = (P * error) + (I * totalerror) + ((error - lastError) * D);
        if (error < integralactivezone and error != 0) {
            totalerror = totalerror + error;
        } else {
            totalerror = 0;
        }
        if (abs(globalposx) >= target - 50) {
            DLF.move(0);
            DRB.move(0);
            DRF.move(0);
            DLB.move(0);
            break;
        }
        if (error == 0) {
            lastError = 0;
        } else {
            lastError = error;
        }
        if (globalposx < target) {
            DLF.move_voltage(-power - gain);
            DRB.move_voltage(-power - gain);
            DRF.move_voltage(-power - gain);
            DLB.move_voltage(-power - gain);
        }
        pros::delay(10);

    }
}


void pidforward(int inches) {
    int halftarget = inches / 0.024;
    int target = halftarget * 2;
    while (true) {
        pros::lcd::set_text(6, std::to_string(target));
        double leftcounts = encoder_right.get_value();
        double rightcounts = encoder_left.get_value();
        double globalposx = leftcounts + rightcounts;
        double error = target - globalposx;
        int lastError = 0;
//    double globalpos = globalposx + encoderGet(encoder_rear);
        float P = 0.05;
        float I = 0.005;
        float D = 0.02;
        int integralactivezone = 75;
        float gain = (P * error) + (I * totalerror) + ((error - lastError) * D);
        if (error < integralactivezone and error != 0) {
            totalerror = totalerror + error;
        } else {
            totalerror = 0;
        }
        if (globalposx >= target - 50) {
            DLF.move(0);
            DRB.move(0);
            DRF.move(0);
            DLB.move(0);
            break;
        }
        if (error == 0) {
            lastError = 0;
        } else {
            lastError = error;
        }
        if (globalposx < target) {
            DLF.move_voltage(power + gain);
            DRB.move_voltage(power + gain);
            DRF.move_voltage(power + gain);
            DLB.move_voltage(power + gain);
        }
        pros::delay(10);

    }
}
//    void infodisplay(){
//        double leftcounts = encoder_right.get_value();
//        double rightcounts = encoder_left.get_value();
//        double globalpos = leftcounts + rightcounts;
//        pros::lcd::set_text(4, std::to_string(encoder_right.get_value()));
//        pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
//        pros::lcd::set_text(6, std::to_string(encoder_rear.get_value()));
//        pros::delay(10);
//    }
    void runintake(){
    Intake.move (80);
};
    void stopintake(){
        Intake.move (0);
    }
    void runreverseintake(){
        Intake.move (-80);
    }
    void runindexer() {
        Indexer.move_absolute(300, 300);
        pros::delay(100);
        Indexer.move_absolute(0, 300);
    }
    void pidflywheel() {
//        float kp = 0.5;
//        float ki = 0.07;
//        float kd = 0.     08;
        float kp = 0.5;
        float ki = 0.002;
        float kd = 0.029;
//PID Variables Here//
        double doublecurrentVelocity = Flywheel1.get_actual_velocity() + Flywheel2.get_actual_velocity();
        double currentVelocity = doublecurrentVelocity / 2;
        int fasterror = 600 - currentVelocity;
        int lastfastError = 0;
        int totalfastError = 0;
        int integralfastActiveZone = 70;
        int currentfastFlywheelVoltage = 30;
        int onTargetCount = 0;
        float finalfastAdjustment = ((fasterror * kp) + (totalfastError * ki) + ((fasterror - lastfastError) * kd));

//Temp Variable//
        int deltaTime = 0;

        if (fasterror == 0) {
            lastfastError = 0;
        } else {
            lastfastError = fasterror;
        }

        if (abs(fasterror) < integralfastActiveZone and fasterror != 0) {
            totalfastError += fasterror;
        } else {
            totalfastError = 0;
        }

        finalfastAdjustment = ((fasterror * kp) + (totalfastError * ki) + ((fasterror - lastfastError) * kd));
        currentfastFlywheelVoltage = currentfastFlywheelVoltage + finalfastAdjustment;
        pros::lcd::set_text(8, "Fast");
        pros::lcd::set_text(1, std::to_string(fasterror));
        pros::lcd::set_text(2, std::to_string(totalfastError));

        Flywheel1.move(currentfastFlywheelVoltage);
        Flywheel2.move(currentfastFlywheelVoltage);
        pros::delay(5);
    }
    void stopflywheel(){
        Flywheel1.move (0);
        Flywheel2.move (0);
};
    void pidturn(double angle, int turnpower) {
            int target = angle / 0.35;
            int integralactivezone = 75;
            int lasterror = 0;
//            pros::lcd::set_text(1, std::to_string(target));
while(true) {
    if (angle < 0) {
        while (true) {
            double leftcounts = encoder_left.get_value();
            double rightcounts = encoder_right.get_value();
//                    double globalpos = leftcounts + rightcounts;
            double error = abs(target) - rightcounts;
            float P = 0.5;
            float I = 0.01;
            float D = 0.06;
            float pid = (P * error) + (I * totalerror) + ((error - lasterror) * D);
//                    float pid = (P * error);
            float gain = pid;
            pros::lcd::set_text(6, std::to_string(gain));
            if (rightcounts >= abs(target)) {
                DLF.move(0);
                DLB.move(0);
                DRB.move(0);
                DRF.move(0);
                break;
            }
            if (error == 0) {
                lasterror = 0;
            } else {
                lasterror = error;
            }
            if (rightcounts < abs(target)) {
                DLF.move_voltage(-turnpower - gain);
                DLB.move_voltage(-turnpower - gain);
                DRF.move_voltage(turnpower + gain);
                DRB.move_voltage(turnpower + gain);
            }
            if (error < integralactivezone and error != 0) {
                totalerror = totalerror + error;
            } else {
                totalerror = 0;
            }
            pros::delay(10);
        }
    }
    if (angle > 0) {
            double leftcounts = encoder_left.get_value();
            double rightcounts = encoder_right.get_value();
//                    double globalpos = leftcounts + rightcounts;
            double error = target - leftcounts;
            float P = 0.5;
            float I = 0.01;
            float D = 0.06;
            float pid = (P * error) + (I * totalerror);
//                    float pid = (P * error);
            float gain = pid;
//                    pros::lcd::set_text(6, std::to_string(gain));
            pros::lcd::set_text(1, std::to_string(totalerror));
            if (leftcounts >= target) {
                DLF.move(0);
                DLB.move(0);
                DRB.move(0);
                DRF.move(0);
                break;
            }
            if (leftcounts < target) {
                DRF.move_voltage(-turnpower - gain);
                DRB.move_voltage(-turnpower - gain);
                DLF.move_voltage((turnpower + gain));
                DLB.move_voltage((turnpower + gain));
            }
            if (error < integralactivezone and error != 0) {
                totalerror = totalerror + error;
            } else {
                totalerror = 0;
            }
            if (error == 0) {
                lasterror = 0;
            } else {
                lasterror = error;
            }
            pros::delay(10);

    }
    break;
}
}