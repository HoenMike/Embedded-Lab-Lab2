#include "Joystick.h"

void Joystick_Initialize(void)
{
    // Enable power to GPIO
    LPC_SC->PCONP |= (1 << 15);

    // Configure joystick pins as inputs
    LPC_GPIO1->FIODIR &= ~((1 << 20) | (1 << 23) | (1 << 24) | (1 << 25) | (1 << 26));
}

Joystick_Status_Enum Joystick_Get_Status(void)
{
    uint32_t joystick_state = LPC_GPIO1->FIOPIN;

    // The joystick inputs are active low, so we check for a 0
    if (!(joystick_state & (1 << 24)))
        return JOYSTICK_UP;
    if (!(joystick_state & (1 << 26)))
        return JOYSTICK_DOWN;
    if (!(joystick_state & (1 << 23)))
        return JOYSTICK_LEFT;
    if (!(joystick_state & (1 << 25)))
        return JOYSTICK_RIGHT;
    if (!(joystick_state & (1 << 20)))
        return JOYSTICK_CENTER;
    return -1;
}