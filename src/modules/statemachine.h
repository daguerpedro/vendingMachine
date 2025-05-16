#ifndef STATEMACHINE_H
#define STATEMACHINE_H

#include <stdbool.h>

typedef enum STATES
{
    MAINTENANCE = -100,
    PRODUCT_SHOWCASE,
    PRODUCT_SELECT,
    PRODUCT_DELIVER,
    EXIT
} STATES;

extern STATES machineState;

void setState(STATES newState);
void runMachine();

#endif