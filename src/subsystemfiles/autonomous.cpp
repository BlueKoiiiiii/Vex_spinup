void TBH_loop(targetvalue) {
    float TBH = 0.0;
    int lasterror = 0;
    float gain = 0.0;
    while (true){
        float GainConst = 0.1;
        double currentvalue = encoder.get_value();
        float error = targetvalue - currentvalue;
        lasterror = error;
        if (error * lasterror < 0){
            TBH = 0.5 * (TBH + currentvalue);
        }
        else{
            TBH = 0;
        }
        float adjustment = GainConst * error + TBH;
    }
}



void PID_loop(targetvalue) {
    float totalerror = 0;
    int lastError = 0;
    while (true) {
        float Kp = 0.01;
        float Ki = 0.001;
        float Kd = 0.05;
        int integralactivezone = 50;
        int initialvoltage = 90;
        float Derivative = error - lastError;
        double currentvalue = encoder.get_value();
        float error = targetvalue - currentvalue;
        float P = error * Kp;
        float D = Derivative * Kd;
        lastError = error;

        if (abs(error) < integralactivezone and error != 0){
            totalerror += fasterror;
        }
        else {
            totalerror = 0;
        }
        float I = totalerror * Ki
        float adjustment = (P + I + D)
        motor.move(initalvoltage + adjustment);
    }
}
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

void worldcloseauton(){
    imu_sensor.reset();
    Flywheel1.move_voltage(12000);
    pros::delay(2000);

//    // move backwards to make sure roller wheel touches roller
//    DLFF.move(-15);
//    DRFF.move(-15);
//    DLF.move(-15);
//    DRF.move(-15);
//    DLB.move(-15);
//    DRB.move(-15);
//
//    // does roller
//    pros::delay(500);
//    Intake.move(127);
//    pros::delay(100);
//    Intake.move(0);

    // move forward slightly to avoid touching roller or walls when turning
    DLFF.move(40);
    DRFF.move(40);
    DLF.move(40);
    DRF.move(40);
    DLB.move(40);
    DRB.move(40);
    pros::delay(100);
    Intake.move(-127);

    DLFF.move(0);
    DRFF.move(0);
    DLF.move(0);
    DRF.move(0);
    DLB.move(0);
    DRB.move(0);

    // go closer to high goal
    imu_turnright(45, 50);
    DLFF.move(60);
    DRFF.move(60);
    DLF.move(60);
    DRF.move(60);
    DLB.move(60);
    DRB.move(60);
    pros::delay(700);

    DLFF.move(0);
    DRFF.move(0);
    DLF.move(0);
    DRF.move(0);
    DLB.move(0);
    DRB.move(0);

    // aim towards high-goal
    imu_turnleft(295, 50);

    // shoot 2 discs towards high goal (very inconsistent)
    Intake.move_voltage(12000);
    pros::delay(200);
    Intake.move_voltage(-12000);
    pros::delay(1000);
    Intake.move_voltage(12000);
    pros::delay(600);
    Intake.move_voltage(-12000);
    Flywheel1.move_voltage(0);
    pros::delay(500);
    Intake.move_voltage(0);
    pros::delay(500);

    imu_turnright(65,50);
    Intake.move(120);
    DLFF.move(-70);
    DRFF.move(-70);
    DLF.move(-70);
    DRF.move(-70);
    DLB.move(-70);
    DRB.move(-70);
    pros::delay(700);
    DLFF.move(0);
    DRFF.move(0);
    DLF.move(0);
    DRF.move(0);
    DLB.move(0);
    DRB.move(0);
    imu_turnleft(315,50);
    DLFF.move(-90);
    DRFF.move(-90);
    DLF.move(-90);
    DRF.move(-90);
    DLB.move(-90);
    DRB.move(-90);
    pros::delay(500);
    DLFF.move(0);
    DRFF.move(0);
    DLF.move(0);
    DRF.move(0);
    DLB.move(0);
    DRB.move(0);
    // turn towards stack of three discs
//    imu_turnright(60, 50);
//
//    // move into the stack of three discs
//    DLFF.move(127);
//    DRFF.move(127);
//    DLF.move(127);
//    DRF.move(127);
//    DLB.move(127);
//    DRB.move(127);
//    pros::delay(300);
//
//    DLFF.move(-127);
//    DRFF.move(-127);
//    DLF.move(-127);
//    DRF.move(-127);
//    DLB.move(-127);
//    DRB.move(-127);
//    pros::delay(300);
//
//    // start intake
//    DLFF.move(30);
//    DRFF.move(30);
//    DLF.move(30);
//    DRF.move(30);
//    DLB.move(30);
//    DRB.move(30);
//    pros::delay(200);
//    Intake.move_voltage(-12000);
//    pros::delay(3000);
//    Intake.move_voltage(12000);
//    pros::delay(50);
//    Intake.move_voltage(-12000);
//    pros::delay(1000);
//    Intake.move_voltage(12000);
//    pros::delay(50);
//    Intake.move_voltage(-12000);
//    pros::delay(1000);
//    Intake.move_voltage(12000);
//    pros::delay(50);
//
//    DLFF.move(0);
//    DRFF.move(0);
//    DLF.move(0);
//    DRF.move(0);
//    DLB.move(0);
//    DRB.move(0);
//
////    Intake.move_voltage(-12000);
////    pros::delay(1000);
////    Intake.move_voltage(12000);
////    pros::delay(500);
////    Intake.move_voltage(-12000);
////    pros::delay(1000);
////    Intake.move_voltage(12000);
////    pros::delay(500);
////    Intake.move_voltage(-12000);
////    pros::delay(1000);
//
//    imu_turnleft(260, 50);
//
//    // move towards high goal (get closer)
////    DLFF.move(40);
////    DRFF.move(40);
////    DLF.move(40);
////    DRF.move(40);
////    DLB.move(40);
////    DRB.move(40);
////    pros::delay(400);
////
////    DLFF.move(0);
////    DRFF.move(0);
////    DLF.move(0);
////    DRF.move(0);
////    DLB.move(0);
////    DRB.move(0);
////
////    pros::delay(400);
//
//    // shoot 3 discs towards high goal
//    Intake.move_voltage(12000);
//    pros::delay(300);
//    Intake.move_voltage(-12000);
//    pros::delay(700);
//    Intake.move_voltage(12000);
//    pros::delay(300);
//    Intake.move_voltage(-12000);
//    pros::delay(700);
//    Intake.move_voltage(12000);
//    pros::delay(300);
//    Intake.move_voltage(-12000);
//    pros::delay(700);
//    Intake.move_voltage(12000);
//    pros::delay(300);
//    Intake.move_voltage(0);

}
void farauton() {
    imu_sensor.reset();
    Flywheel1.move_voltage(11000);
    pros::delay(2000);
    Intake.move_voltage(-12000);
    DLF.move(70);
    DRF.move(70);
    DLFF.move(70);
    DLB.move(70);
    DRFF.move(70);
    DRB.move(70);
    pros::delay(550);
    DLF.move(0);
    DRF.move(0);
    DLFF.move(0);
    DLB.move(0);
    DRFF.move(0);
    DRB.move(0);
    pros::delay(2000);
    Intake.move_voltage(12000);
    pros::delay(100);
    Intake.move_voltage(-12000);
    imu_sensor.set_heading(1);
    imu_turnright(27, 40);
    pros::delay(500);
    Intake.move_voltage(12000);
    pros::delay(200);
    Intake.move_voltage(-12000);
    pros::delay(1000);
    Intake.move_voltage(12000);
    pros::delay(200);
    Intake.move_voltage(-12000);
    pros::delay(1000);
    Intake.move_voltage(12000);
    pros::delay(1000);
    Intake.move_voltage(-12000);
    pros::delay(400);
    Intake.move_voltage(0);
//    DLF.move(-70);
//    DRF.move(-70);
//    DLFF.move(-70);
//    DLB.move(-70);
//    DRFF.move(-70);
//    DRB.move(-70);
//    pros::delay(200);
//    DLF.move(0);
//    DRF.move(0);
//    DLFF.move(0);
//    DLB.move(0);
//    DRFF.move(0);
//    DRB.move(0);
    imu_turnleft(290, 50);
//    Intake.move(-127);
//    DLF.move(70);
//    DRF.move(70);
//    DLFF.move(70);
//    DLB.move(70);
//    DRFF.move(70);
//    DRB.move(70);
//    pros::delay(200);
//    DLF.move(0);
//    DRF.move(0);
//    DLFF.move(0);
//    DLB.move(0);
//    DRFF.move(0);
//    DRB.move(0);
//    pros::delay(1000);
//    imu_sensor.set_heading(1);
//    imu_turnright(90, 30);
//    Intake.move_voltage(12000);
//    pros::delay(500);
//    Intake.move_voltage(-12000)
//    pros::delay(500);
//    Intake.move_voltage(12000);
//    pros::delay(500);
//    Intake.move_voltage(0);
//    imu_turnleft(260, 40);
    DLF.move(-120);
    DRF.move(-120);
    DLFF.move(-120);
    DLB.move(-120);
    DRFF.move(-120);
    DRB.move(-120);
    pros::delay(700);
    DLF.move(0);
    DRF.move(0);
    DLFF.move(0);
    DLB.move(0);
    DRFF.move(0);
    DRB.move(0);
    Intake.move(120);
    imu_turnright(50, 60);
    DLF.move(-90);
    DRF.move(-90);
    DLFF.move(-90);
    DLB.move(-90);
    DRFF.move(-90);
    DRB.move(-90);
    pros::delay(500);
    DLF.move(0);
    DRF.move(0);
    DLFF.move(0);
    DLB.move(0);
    DRFF.move(0);
    DRB.move(0);
//    pros::delay(200);
    Intake.move(0);



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
//        pros::lcd::set_text(5, std::fyto_string(encoder_left.get_value()));
//        pros::lcd::set_text(6, std::to_string(encoder_rear.get_value()));
//        pros::delay(10);
//    }
    void imu_turnright(int target_angle, int speed) {
    double kp = 0.5;
    double ki = 0.03;
    double kd = 0.1;
    int lastError = 0;
    int totalError = 0;
    int integralActiveZone = 20;
    bool runloop = true;
    imu_sensor.set_heading(2);
    int deltatime = 0;

//    imu_sensor.reset();
    while (runloop) {
        int current_angle = imu_sensor.get_heading();
        int error = target_angle - current_angle;
        double adjustment = (error * kp) + (totalError * ki) + ((error - lastError) * kd);

        if (error == 0) {
            lastError = 0;
        } else {
            lastError = error;
        }

        if (abs(error) < integralActiveZone and error != 0) {
            totalError += error;
        } else {
            totalError = 0;
        }

//        if (error > 0) {
            DLF.move(speed + adjustment);
            DRF.move(-speed - adjustment);
            DLFF.move(speed + adjustment);
            DLB.move(speed + adjustment);
            DRFF.move(-speed - adjustment);
            DRB.move(-speed - adjustment);
//        } else {
//            DLF.move(-speed - adjustment);
//            DRF.move(speed + adjustment);
//            DLFF.move(-speed - adjustment);
//            DLB.move(-speed - adjustment);
//            DRFF.move(speed + adjustment);
//            DRB.move(speed + adjustment);
//        }

        if (5 > error and error > -5) {
            deltatime += 1;
            speed = 0;
        }

        if (deltatime > 25) {
            DLF.move(0);
            DRF.move(0);
            DLFF.move(0);
            DLB.move(0);
            DRFF.move(0);
            DRB.move(0);
            runloop = false;
        }
        Master.set_text(0, 0, std::to_string(error));
        pros::delay(10);
    }
}

    void imu_turnleft(int target_angle, int speed) {
        double kp = 0.5;
        double ki = 0.03;
        double kd = 0.1;
        int lastError = 0;
        int totalError = 0;
        int integralActiveZone = 20;
        bool runloop = true;
        imu_sensor.set_heading(358);
        int deltatime = 0;
//    imu_sensor.reset();
        while (runloop) {
            int current_angle = imu_sensor.get_heading();
            int error = (current_angle - target_angle );
            double adjustment = (error * kp) + (totalError * ki) + ((error - lastError) * kd);

            if (error == 0) {
                lastError = 0;
            } else {
                lastError = error;
            }

            if (abs(error) < integralActiveZone and error != 0) {
                totalError += error;
            } else {
                totalError = 0;
            }

//            if (error < 0) {
//                DLF.move(speed + adjustment);
//                DRF.move(-speed - adjustment);
//                DLFF.move(speed + adjustment);
//                DLB.move(speed + adjustment);
//                DRFF.move(-speed - adjustment);
//                DRB.move(-speed - adjustment);
//            } else {
                DLF.move(-speed - adjustment);
                DRF.move(speed + adjustment);
                DLFF.move(-speed - adjustment);
                DLB.move(-speed - adjustment);
                DRFF.move(speed + adjustment);
                DRB.move(speed + adjustment);
//            }

            if (5 > error and error > -5) {
                deltatime += 1;
                speed = 0;
            }

            if (deltatime > 25) {
                DLF.move(0);
                DRF.move(0);
                DLFF.move(0);
                DLB.move(0);
                DRFF.move(0);
                DRB.move(0);
                runloop = false;
            }
            Master.set_text(0, 0, std::to_string(imu_sensor.get_heading()));
            pros::delay(10);
        }
}

    void skills(){
        piston.set_value(true);
        imu_sensor.reset();
        Flywheel1.move_voltage(10000);
        pros::delay(2000);
        runreverseintake();
        DLFF.move(-50);
        DRFF.move(-50);
        DLF.move(-50);
        DRF.move(-50);
        DLB.move(-50);
        DRB.move(-50);
        pros::delay(400);
        DLFF.move(0);
        DRFF.move(0);
        DLF.move(0);
        DRF.move(0);
        DLB.move(0);
        DRB.move(0);
        pros::delay(200);
        stopintake();
        runreverseintake();
        DLFF.move(50);
        DRFF.move(50);
        DLF.move(50);
        DRF.move(50);
        DLB.move(50);
        DRB.move(50);
        pros::delay(100);
        DLFF.move(0);
        DRFF.move(0);
        DLF.move(0);
        DRF.move(0);
        DLB.move(0);
        DRB.move(0);
        imu_turnright(90, 10);
//    DRF.move(20);
//    DRB.move(20);
//    DRFF.move(20);
//    pros::delay(600);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    runreverseintake();
//    Flywheel1.move_velocity(520);
//    pros::delay(450);
        stopintake();
        pros::delay(500);
        runintake();
        pros::delay(3000);
//    pros::delay(400);
//    stopintake();
//    pros::delay(1500);
//    runintake();
//    pros::delay(500);
        stopintake();
//    DLF.move(30);
//    DLB.move(30);
//    DLFF.move(30);
//    DRF.move(-30);
//    DRB.move(-30);
//    DRFF.move(-30);
//    pros::delay(1150);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
        imu_sensor.tare();
        imu_turnleft(320, 10);
        runintake();
        DLF.move(90);
        DLB.move(90);
        DLFF.move(90);
        DRF.move(90);
        DRB.move(90);
        DRFF.move(90);
        pros::delay(900);
        DLF.move(-80);
        DLB.move(-80);
        DLFF.move(-80);
        DRF.move(-80);
        DRB.move(-80);
        DRFF.move(-80);
        pros::delay(500);
        runreverseintake();
        DLF.move(50);
        DLB.move(50);
        DLFF.move(50);
        DRF.move(50);
        DRB.move(50);
        DRFF.move(50);
        pros::delay(1500);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);

        Flywheel1.move_voltage(10000);
//    DLF.move(-90);
//    DLB.move(-90);
//    DLFF.move(-90);
//    DRF.move(-90);
//    DRB.move(-90);
//    DRFF.move(-90);
//    pros::delay(1000);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
//    stopintake();
//    runreverseintake()
//    stopintake();
//    runreverseintake()


        pros::delay(2000);
//    Flywheel1.move(999);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(500);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
        imu_turnright(75, 10);
        DLF.move(90);
        DLB.move(90);
        DLFF.move(90);
        DRF.move(90);
        DRB.move(90);
        DRFF.move(90);
        pros::delay(100);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        Flywheel1.move_voltage(10000);
//    pros::delay(1000);
//    DLF.move(-90);
//    DLB.move(-90);
//    DLFF.move(-90);
//    DRF.move(-90);
//    DRB.move(-90);
//    DRFF.move(-90);
//    pros::delay(1000);

//    stopintake();
        pros::delay(2000);
        runintake();
        pros::delay(3000);
        stopintake();
//    Flywheel1.move(0);
        runreverseintake();
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(-60);
//    DRB.move(-60);
//    DRFF.move(-60);
//    pros::delay(500);
        Flywheel1.move_voltage(11000);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    DLF.move(-30);
//    DLB.move(-30);
//    DLFF.move(-30);
//    DRF.move(-30);
//    DRB.move(-30);
//    DRFF.move(-30);
//    pros::delay(200);
////    Flywheel1.move_voltage(10000);
////    DLF.move(-90);
////    DLB.move(-90);
////    DLFF.move(-90);
////    DRF.move(-90);
////    DRB.move(-90);
////    DRFF.move(-90);
////    pros::delay(1000);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
        DLF.move(-90);
        DLB.move(-90);
        DLFF.move(-90);
        DRF.move(-90);
        DRB.move(-90);
        DRFF.move(-90);
        pros::delay(250);
//    Flywheel1.move_voltage(10000);
//    DLF.move(-90);
//    DLB.move(-90);
//    DLFF.move(-90);
//    DRF.move(-90);
//    DRB.move(-90);
//    DRFF.move(-90);
//    pros::delay(1000);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        imu_turnleft(275, 10);
        DLF.move(60);
        DLB.move(60);
        DLFF.move(60);
        DRF.move(60);
        DRB.move(60);
        DRFF.move(60);
        pros::delay(2950);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        imu_turnleft(240, 10);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(690);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    runintake();
//    pros::delay(2000);
//    stopintake();
        runreverseintake();
        DLF.move(-90);
        DLB.move(-90);
        DLFF.move(-90);
        DRF.move(-90);
        DRB.move(-90);
        DRFF.move(-90);
        pros::delay(500);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        DLF.move(60);
        DLB.move(60);
        DLFF.move(60);
        DRF.move(60);
        DRB.move(60);
        DRFF.move(60);
        pros::delay(100);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);

        imu_turnleft(270, 10);
//    DLF.move(30);
//    DLB.move(30);
//    DLFF.move(30);
//    pros::delay(600);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    imu_turnleft(350, 0);
        runintake();
        pros::delay(2500);
//    runreverseintake();
//    stopintake();
//    runreverseintake();
        imu_turnright(90, 10);
        DLF.move(90);
        DLB.move(90);
        DLFF.move(90);
        DRF.move(90);
        DRB.move(90);
        DRFF.move(90);
        pros::delay(800);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        DLF.move(-90);
        DLB.move(-90);
        DLFF.move(-90);
        DRF.move(-90);
        DRB.move(-90);
        DRFF.move(-90);
        pros::delay(400);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
//    stopintake();
        imu_turnleft(270,10);
        DLF.move(-90);
        DLB.move(-90);
        DLFF.move(-90);
        DRF.move(-90);
        DRB.move(-90);
        DRFF.move(-90);
        pros::delay(800);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        DLF.move(60);
        DLB.move(60);
        DLFF.move(60);
        DRF.move(60);
        DRB.move(60);
        DRFF.move(60);
        pros::delay(100);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);

//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(510);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
        imu_turnright(43, 10);
        runreverseintake();
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(1100);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(100);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    imu_turnleft(315, 10);
        DLF.move(50);
        DLB.move(50);
        DLFF.move(50);
        DRF.move(50);
        DRB.move(50);
        DRFF.move(50);
        pros::delay(2800);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
//    pros::delay(2300);
        imu_turnright(84, 10);
//    runreverseintake();
//    DLF.move(50);
//    DLB.move(50);
//    DLFF.move(50);
//    DRF.move(50);
//    DRB.move(50);
//    DRFF.move(50);
//    pros::delay(2300);
//    Flywheel1.move(999);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(500);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    imu_turnleft(265, 10);
        DLF.move(90);
        DLB.move(90);
        DLFF.move(90);
        DRF.move(90);
        DRB.move(90);
        DRFF.move(90);
        pros::delay(100);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        Flywheel1.move_voltage(9000);
//    pros::delay(1000);
//    DLF.move(-90);
//    DLB.move(-90);
//    DLFF.move(-90);
//    DRF.move(-90);
//    DRB.move(-90);
//    DRFF.move(-90);
//    pros::delay(1000);

//    stopintake();
        pros::delay(2000);
        runintake();
        pros::delay(3000);
        stopintake();
//    Flywheel1.move(0);
        runreverseintake();
//    DLF.move(60);
//    DLB.move(60);
//    DLFF.move(60);
//    DRF.move(-60);
//    DRB.move(-60);
//    DRFF.move(-60);
//    pros::delay(500);
        Flywheel1.move_voltage(11000);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    DLF.move(-30);
//    DLB.move(-30);
//    DLFF.move(-30);
//    DRF.move(-30);
//    DRB.move(-30);
//    DRFF.move(-30);
//    pros::delay(200);
////    Flywheel1.move_voltage(10000);
////    DLF.move(-90);
////    DLB.move(-90);
////    DLFF.move(-90);
////    DRF.move(-90);
////    DRB.move(-90);
////    DRFF.move(-90);
////    pros::delay(1000);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
        DLF.move(-90);
        DLB.move(-90);
        DLFF.move(-90);
        DRF.move(-90);
        DRB.move(-90);
        DRFF.move(-90);
        pros::delay(250);
//    Flywheel1.move_voltage(10000);
//    DLF.move(-90);
//    DLB.move(-90);
//    DLFF.move(-90);
//    DRF.move(-90);
//    DRB.move(-90);
//    DRFF.move(-90);
//    pros::delay(1000);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        imu_turnleft(265, 10);
        DLF.move(60);
        DLB.move(60);
        DLFF.move(60);
        DRF.move(60);
        DRB.move(60);
        DRFF.move(60);
        pros::delay(2700);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        imu_sensor.tare();
        imu_turnleft(240, 10);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(690);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    runintake();
//    pros::delay(2000);
//    stopintake();
        runreverseintake();
        DLF.move(-90);
        DLB.move(-90);
        DLFF.move(-90);
        DRF.move(-90);
        DRB.move(-90);
        DRFF.move(-90);
        pros::delay(500);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);
        DLF.move(60);
        DLB.move(60);
        DLFF.move(60);
        DRF.move(60);
        DRB.move(60);
        DRFF.move(60);
        pros::delay(100);
        DLF.move(0);
        DLB.move(0);
        DLFF.move(0);
        DRF.move(0);
        DRB.move(0);
        DRFF.move(0);

        imu_turnleft(270, 10);
//    DLF.move(30);
//    DLB.move(30);
//    DLFF.move(30);
//    pros::delay(600);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
//    imu_turnleft(350, 0);
        runintake();
        pros::delay(2500);
}



    void closeauton(){
    runintake();
    DLFF.move(-50);
    DRFF.move(-50);
    DLF.move(-50);
    DRF.move(-50);
    DLB.move(-50);
    DRB.move(-50);
    pros::delay(300);
    DLFF.move(0);
    DRFF.move(0);
    DLF.move(0);
    DRF.move(0);
    DLB.move(0);
    DRB.move(0);
    stopintake();
    runreverseintake();
    Flywheel1.move_voltage(11500);
    DRF.move(20);
    DRB.move(20);
    DRFF.move(20);
    pros::delay(800);
    DRF.move(0);
    DRB.move(0);
    DRFF.move(0);
//    runreverseintake();
//    Flywheel1.move_velocity(520);
//    pros::delay(450);
    stopintake();
    pros::delay(3000);
    runintake();
    pros::delay(2500);
//    pros::delay(400);
//    stopintake();
//    pros::delay(1500);
//    runintake();
//    pros::delay(500);
    stopintake();
    DLF.move(30);
    DLB.move(30);
    DLFF.move(30);
    DRF.move(-30);
    DRB.move(-30);
    DRFF.move(-30);
    pros::delay(900);
    DLF.move(0);
    DLB.move(0);
    DLFF.move(0);
    DRF.move(0);
    DRB.move(0);
    DRFF.move(0);
    runreverseintake();
    DLF.move(110);
    DLB.move(110);
    DLFF.move(110);
    DRF.move(110);
    DRB.move(110);
    DRFF.move(110);
    pros::delay(650);
    Flywheel1.move_voltage(10500);
//    DLF.move(-90);
//    DLB.move(-90);
//    DLFF.move(-90);
//    DRF.move(-90);
//    DRB.move(-90);
//    DRFF.move(-90);
//    pros::delay(1000);
    DLF.move(0);
    DLB.move(0);
    DLFF.move(0);
    DRF.move(0);
    DRB.move(0);
    DRFF.move(0);



    pros::delay(2000);
//    Flywheel1.move(999);
//    DLF.move(-60);
//    DLB.move(-60);
//    DLFF.move(-60);
//    DRF.move(60);
//    DRB.move(60);
//    DRFF.move(60);
//    pros::delay(430);
//    DLF.move(0);
//    DLB.move(0);
//    DLFF.move(0);
//    DRF.move(0);
//    DRB.move(0);
//    DRFF.move(0);
////    stopintake();
//    pros::delay(1500);
//    runintake();
//    pros::delay(4000);
//    stopintake();
//    Flywheel1.move(0);

}


    void safefarauton(){
    DLFF.move(50);
    DRFF.move(50);
    DLF.move(50);
    DRF.move(50);
    DLB.move(50);
    DRB.move(50);
    pros::delay(1300);
    DLFF.move(-50);
    DRFF.move(50);
    DLF.move(-50);
    DRF.move(50);
    DLB.move(-50);
    DRB.move(50);
    runintake();
    pros::delay(700);
    DLFF.move(-50);
    DRFF.move(-50);
    DLF.move(-50);
    DRF.move(-50);
    DLB.move(-50);
    DRB.move(-50);
    pros::delay(300);
    DLFF.move(50);
    DRFF.move(50);
    DLF.move(50);
    DRF.move(50);
    DLB.move(50);
    DRB.move(50);
    pros::delay(200);
    DLFF.move(0);
    DRFF.move(0);
    DLF.move(0);
    DRF.move(0);
    DLB.move(0);
    DRB.move(0);
};

    void runintake(){
    Intake.move (999);
};
    void stopintake(){
        Intake.move (0);
    }
    void runreverseintake(){
        Intake.move (-999);
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
        double doublecurrentVelocity = Flywheel1.get_actual_velocity();
        double currentVelocity = doublecurrentVelocity;
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
        pros::delay(5);
    }
    void stopflywheel(){
        Flywheel1.move (0);
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