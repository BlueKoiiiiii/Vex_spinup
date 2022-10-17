//
// Created by Daniel on 2022-10-13.
//
#include "main.h"
float power = 4000;
void sensors_reset(){
    encoder_left.reset();
    encoder_right.reset();
}
void pidforward(int target) {
    while (true) {
        double leftcounts = encoder_right.get_value();
        double rightcounts = encoder_left.get_value();
        double globalposx = leftcounts + rightcounts;
//    double globalpos = globalposx + encoderGet(encoder_rear);
        float P = 0.05;
        float pid = P;
        float gain = ((target * 2) - globalposx) * P;
        float power = (power + gain);

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
            DLF.move_voltage(power);
            DRB.move_voltage(power);
            DRF.move_voltage(power);
            DLB.move_voltage(power);
        }
        pros::delay(150);

    }

}