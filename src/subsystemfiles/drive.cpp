//
// Created by Daniel on 2022-08-07.
//

#include "main.h"
bool run_flywheel = false;

void op_flywheel() {
    if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_A)) {
        run_flywheel = true;
    }
    else if (Master.get_digital(pros::E_CONTROLLER_DIGITAL_B)) {
        run_flywheel = false;
    }

    if (run_flywheel) {
        Flywheel1.move_velocity(500);
        Flywheel2.move_velocity(500);
//            Flywheel1.move (127);
//            Flywheel2.move (127);
    }
    else {
        Flywheel1. move_velocity(0);
        Flywheel2. move_velocity (0);
    }

}