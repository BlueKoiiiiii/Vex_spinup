#ifndef NEW_AUTONOMOUS_H
#define NEW_AUTONOMOUS_H
#include "main.h"
extern double globalposx;
void pidforward(int inches);
void sensors_reset();
extern float totalerror;
extern int target;
void pidturn(double angle, int turnpower);
void imu_turnright(int target_angle, int speed);
void imu_turnleft(int target_angle, int speed);
void infodisplay();
void skills();
void farauton();
void closeauton();
void safefarauton();
//void farautonworlds();
void runintake();
void stopintake();
void stopflywheel();
void runindexer();
void runreverseintake();
void pidflywheel();
void pidreverse(int inches);
#endif //NEW_AUTONOMOUS_H