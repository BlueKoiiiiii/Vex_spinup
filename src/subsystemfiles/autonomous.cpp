//
// Created by Daniel on 2022-10-13.
//
#include "main.h"
float power = 5000;
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
        double error = target*2 - globalposx;
//    double globalpos = globalposx + encoderGet(encoder_rear);
        float P = 0.05;
        float I = 0.01;
        totalerror += error;
        float pid = (P*error) + (I*totalerror);

        float gain = pid;

        pros::lcd::set_text(4, std::to_string(encoder_right.get_value()));
        pros::lcd::set_text(5, std::to_string(encoder_left.get_value()));
        pros::lcd::set_text(6, std::to_string(encoder_rear.get_value()));
        pros::lcd::set_text(1, std::to_string(gain));

        if (globalposx >= target*2 - 50) {
            DLF.move(0);
            DRB.move(0);
            DRF.move(0);
            DLB.move(0);
            break;
        }
        if (globalposx < target*2) {
            DLF.move_voltage(power + gain);
            DRB.move_voltage(power + gain);
            DRF.move_voltage(power + gain);
            DLB.move_voltage(power + gain);
        }
        pros::delay(150);

    }

}