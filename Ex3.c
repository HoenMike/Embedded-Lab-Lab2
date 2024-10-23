#include "cmsis_os.h" // ARM::CMSIS:RTOS:Keil RTX
#include "LPC17xx.h"  // Device header
#include "uart.h"
#include "Led.h"
#include "Joystick.h"
#include <string.h> // Include for strlen

void ProcessJoystick(void)
{
    char *message;

    switch (Joystick_Get_Status())
    {
    case JOYSTICK_UP:
        message = "IU\r\n";
        UART_Send(message, strlen(message));
        break;
    case JOYSTICK_DOWN:
        message = "Electrical Engineering\r\n";
        UART_Send(message, strlen(message));
        break;
    case JOYSTICK_LEFT:
        message = "Embedded System\r\n";
        UART_Send(message, strlen(message));
        break;
    case JOYSTICK_RIGHT:
        message = "Hoang, Phu\r\n"; // Replace with your actual name
        UART_Send(message, strlen(message));
        break;
    case JOYSTICK_CENTER:
        // You can add functionality for the center button if needed
        break;
    default:
        // No joystick action
        break;
    }
}

void ProcessUARTCommand(void)
{
    if (UART_Buffer_Count > 0)
    {
        uint8_t command = UART_Buffer[UART_Buffer_Count - 1];
        uint8_t intention = (command >> 4) & 0x0F;
        uint8_t target = command & 0x0F;

        if (target < 8)
        { // Valid LED index
            if (intention == 1)
            {
                LedOn(target);
            }
            else if (intention == 2)
            {
                LedOff(target);
            }
        }

        UART_Buffer_Count = 0; // Reset buffer count after processing
    }
}

int main(void)
{
    UART_Initialize(9600);
    LedInitialize();
    Joystick_Initialize();

    while (1)
    {
        ProcessJoystick();
        ProcessUARTCommand();
        osDelay(100); // Small delay to prevent excessive polling
    }
}