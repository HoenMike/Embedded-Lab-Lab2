#include "LPC17xx.h"
#include "ADC.h"
#include "led.h"
#include "uart.h"
#include <string.h>
#include <stdio.h> // Include for snprintf
#define UART_BAUD_RATE 9600

int main(void)
{
    char buffer[BUFFER_SIZE];

    // Initialize ADC, LEDs, and UART
    ADC_Initialize();
    LedInitialize();
    UART_Initialize(UART_BAUD_RATE);

    while (1)
    {
        // Start ADC conversion
        ADC_StartConversion();

        // Wait for conversion to complete
        while (!ADC_ConversionDone())
            ;

        // Get ADC value
        int adcValue = ADC_GetValue();

        // Debug: Send ADC value through UART
        snprintf(buffer, BUFFER_SIZE, "ADC Value: %d\r\n", adcValue);
        UART_Send(buffer, strlen(buffer));

        // Display 8 high order bits on LEDs
        unsigned char ledValue = (adcValue >> 4) & 0xFF;

        // Debug: Send LED value through UART
        snprintf(buffer, BUFFER_SIZE, "LED Value: %02X\r\n", ledValue);
        UART_Send(buffer, strlen(buffer));

        // Turn off all LEDs first
        for (int i = 0; i < 8; i++)
        {
            LedOff(i);
        }

        // Turn on LEDs according to ledValue
        for (int i = 0; i < 8; i++)
        {
            if (ledValue & (1 << i))
            {
                LedOn(i);
            }
        }
    }
}