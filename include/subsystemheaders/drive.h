//
// Created by Daniel on 2022-08-07.
//

#ifndef NEW_DRIVE_H
#define NEW_DRIVE_H

#endif //NEW_DRIVE_H
#include "main.h"

extern bool run_flywheel;
void op_indexer();
void op_flywheel(int low_target, int fast_target);
void op_drive();
void op_intake();
void pneumatic();
void op_angler();
void op_drivesplitcubic();
void op_logdrive();
void opendgame();
//void ArcadeDrive();
void flywheelop(int low_volt, int high_volt);
extern double flypower;
extern int currentFlywheelVoltage;
void test_turn();
