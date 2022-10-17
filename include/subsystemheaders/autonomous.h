#ifndef NEW_AUTONOMOUS_H
#define NEW_AUTONOMOUS_H
#include "main.h"
extern double globalposx;
void pidforward(int target);
void sensors_reset();
extern int target;
#endif //NEW_AUTONOMOUS_H