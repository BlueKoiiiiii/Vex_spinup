//
// Created by Daniel on 2022-10-13.
//
#include "main.h"
float P = 0.1;
void Sensors_reset(){
    encoder_left.reset();
    encoder_right.reset();
}
void pidforward (int target){
    while (true) {
        int leftcounts = encoder_right.get_value();
        int rightcounts = encoder_left.get_value();
    double globalposx = leftcounts + rightcounts;
//    double globalpos = globalposx + encoderGet(encoder_rear);
    float P = 0.1;
    float pid = P;
    float gain = globalposx - target * pid;
    float power = power * gain;
    if (globalposx == target + 50) {
        DLF.move(0);
        DRB.move(0);
        DRF.move(0);
        DLB.move(0);
        break;
    }
    if (globalposx < target) {
        DLF.move(gain);
        DRB.move(gain);
        DRF.move(gain);
        DLB.move(gain);
    }

    }

}