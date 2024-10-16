#include "cmsis_os.h"                     // ARM::CMSIS:RTOS:Keil RTX
#include "LPC17xx.h"                      // Device header
#include "uart.h"
#include "Led.h"
#include "Joystick.h"

void ProcessJoystick(void) {
    switch (Joystick_Get_Status()) {
        case JOYSTICK_UP:
            UART_Send("International University\r\n", 26);
            break;
        case JOYSTICK_DOWN:
            UART_Send("Electrical Engineering\r\n", 24);
            break;
        case JOYSTICK_LEFT:
            UART_Send("Embedded System\r\n", 17);
            break;
        case JOYSTICK_RIGHT:
            UART_Send("Hoang, Phu\r\n", 15); // Replace with your actual name
            break;
        case JOYSTICK_CENTER:
            // You can add functionality for the center button if needed
            break;
        default:
            // No joystick action
            break;
    }
}

void ProcessUARTCommand(void) {
    if (UART_Buffer_Count > 0) {
        uint8_t command = UART_Buffer[UART_Buffer_Count - 1];
        uint8_t intention = (command >> 4) & 0x0F;
        uint8_t target = command & 0x0F;

        if (target < 8) {  // Valid LED index
            if (intention == 1) {
                LedOn(target);
            } else if (intention == 2) {
                LedOff(target);
            }
        }

        UART_Buffer_Count = 0;  // Reset buffer count after processing
    }
}

int main(void) {
    UART_Initialize(9600);
    LedInitialize();
    Joystick_Initialize();

    while(1) {
        ProcessJoystick();
        ProcessUARTCommand();
        osDelay(100);  // Small delay to prevent excessive polling
    }
}