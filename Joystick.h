#ifndef JOYSTICK_H
#define JOYSTICK_H

#include "LPC17xx.h"

typedef enum {
    JOYSTICK_UP,
    JOYSTICK_DOWN,
    JOYSTICK_LEFT,
    JOYSTICK_RIGHT,
	  JOYSTICK_CENTER
} Joystick_Status_Enum;

void Joystick_Initialize(void);
Joystick_Status_Enum Joystick_Get_Status(void);

#endif // JOYSTICK_H