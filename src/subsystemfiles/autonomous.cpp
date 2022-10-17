//
// Created by Daniel on 2022-10-13.
//
#include "main.h"
float power = 3000;
float totalerror = 0;

void sensors_reset(){
    encoder_left.reset();
    encoder_right.reset();
}
void pidforward(int target) {
    while (true) {
        double leftcounts = encoder_right.get_value();
        double rightcounts = encoder_left.get_value();
        double globalposx = leftcounts + rightcounts;
        double error = target - globalposx;
//    double globalpos = globalposx + encoderGet(encoder_rear);
        float P = 0.03;
        float I = 0.005;
        totalerror += error;
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
            float target = angle / 0.26;

            if (angle < 0) {
                while(true) {
                    double leftcounts = encoder_left.get_value();
                    double rightcounts = encoder_left.get_value();
//                    double globalpos = leftcounts + rightcounts;
                    double error = target - leftcounts;
                    float P = 0.03;
                    float I = 0.005;
//                    float pid = (P * error) + (I * totalerror);
                    float pid = (P * error);
                    float gain = pid;
                    if (leftcounts >= target - 50) {
                        DLF.move(0);
                        DLB.move(0);
                        DRB.move(0);
                        DRF.move(0);
                        break;
                    }
                    if (leftcounts < target) {
                        DLF.move_voltage(power + gain);
                        DLB.move_voltage(power + gain);
                        DRF.move_voltage((power + gain) * -1);
                        DRB.move_voltage((power + gain) * -1);
                    }
                    totalerror+=error;
                    pros::delay(10);
                }
            }
            if (angle > 0) {
                while(true) {
                    double leftcounts = encoder_right.get_value();
                    double rightcounts = encoder_right.get_value();
//                    double globalpos = leftcounts + rightcounts;
                    double error = target - rightcounts;
                    float P = 0.03;
                    float I = 0.005;
//                    float pid = (P * error) + (I * totalerror);
                    float pid = (P * error);
                    float gain = pid;
                    pros::lcd::set_text(4, std::to_string(encoder_right.get_value()));
                    pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
                    pros::lcd::set_text(6, std::to_string(gain));

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
                    totalerror+=error;
                    pros::delay(10);
                }
            }

}