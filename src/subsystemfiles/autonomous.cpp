//
// Created by Daniel on 2022-10-13.
//
#include "main.h"
float power = 2000;
float totalerror = 0;

void sensors_reset(){
    encoder_left.reset();
    encoder_right.reset();
}
void pidforward(int inches) {
    int halftarget = inches/0.024;
    int target = halftarget *2;
    while (true) {
        pros::lcd::set_text(6, std::to_string(target));
        double leftcounts = encoder_right.get_value();
        double rightcounts = encoder_left.get_value();
        double globalposx = leftcounts + rightcounts;
        double error = target - globalposx;
//    double globalpos = globalposx + encoderGet(encoder_rear);
        float P = 0.05;
        float I = 0.005;
        int integralactivezone = 75;
        if (error < integralactivezone and error != 0){
            totalerror = totalerror + error;
        }
        else{
            totalerror = 0;
        }
        float pid = (P * error) + (I * totalerror);

        float gain = pid;

        if (globalposx >= target - 50) {
            DLF.move(0);
            DRB.move(0);
            DRF.move(0);
            DLB.move(0);
            break;
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
    void infodisplay(){
        double leftcounts = encoder_right.get_value();
        double rightcounts = encoder_left.get_value();
        double globalpos = leftcounts + rightcounts;
        pros::lcd::set_text(4, std::to_string(encoder_right.get_value()));
        pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
        pros::lcd::set_text(6, std::to_string(encoder_rear.get_value()));
        pros::delay(10);
    }
    void pidturn(int angle) {
            int target = angle / 0.245;
            int integralactivezone = 75;
//            pros::lcd::set_text(1, std::to_string(target));
            if (angle < 0) {
                while(true) {
                    double leftcounts = encoder_left.get_value();
                    double rightcounts = encoder_left.get_value();
//                    double globalpos = leftcounts + rightcounts;
                    double error = abs(target)- leftcounts;
                    float P = 0.5;
                    float I = 0.01;
                    float pid = (P * error) + (I * totalerror);
//                    float pid = (P * error);
                    float gain = pid;
                    pros::lcd::set_text(6, std::to_string(gain));
                    if (leftcounts >= abs(target) - 50) {
                        DLF.move(0);
                        DLB.move(0);
                        DRB.move(0);
                        DRF.move(0);
                        break;
                    }
                    if (leftcounts < abs(target)) {
                        DLF.move_voltage(power + gain);
                        DLB.move_voltage(power + gain);
                        DRF.move_voltage((power + gain) * -1);
                        DRB.move_voltage((power + gain) * -1);
                    }
                    if (error < integralactivezone and error != 0){
                        totalerror = totalerror + error;
                    }
                    else{
                        totalerror = 0;
                    }
                    pros::delay(10);
                }
            }
            if (angle > 0) {
                while(true) {
                    double leftcounts = encoder_right.get_value();
                    double rightcounts = encoder_right.get_value();
//                    double globalpos = leftcounts + rightcounts;
                    double error = target - rightcounts;
                    float P = 0.05;
                    float I = 0.005;
                    float pid = (P * error) + (I * totalerror);
//                    float pid = (P * error);
                    float gain = pid;
//                    pros::lcd::set_text(6, std::to_string(gain));
                    pros::lcd::set_text(1, std::to_string(totalerror));
                    if (rightcounts >= target - 50) {
                        DLF.move(0);
                        DLB.move(0);
                        DRB.move(0);
                        DRF.move(0);
                        break;
                    }
                    if (rightcounts < target) {
                        DRF.move_voltage(power + gain);
                        DRB.move_voltage(power + gain);
                        DLF.move_voltage((power + gain) * -1);
                        DLB.move_voltage((power + gain) * -1);
                    }
                    if (error<integralactivezone and error != 0){
                        totalerror = totalerror + error;
                    }
                    else{
                        totalerror = 0;
                    }
                    pros::delay(10);
                }
            }

}