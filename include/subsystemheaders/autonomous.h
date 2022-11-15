#ifndef NEW_AUTONOMOUS_H
#define NEW_AUTONOMOUS_H
#include "main.h"
extern double globalposx;
void pidforward(int inches);
void sensors_reset();
extern float totalerror;
extern int target;
void pidturn(int angle);
void infodisplay();
void runintake();
void stopintake();
void stopflywheel();
void runindexer();
void pidflywheel();
#endif //NEW_AUTONOMOUS_H