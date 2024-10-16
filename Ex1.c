#include "LPC17xx.h"
#include "ADC.h"
#include "led.h"
#include "uart.h"
#include <string.h>

#define UART_BAUD_RATE 9600


int main(void)
{
    // Initialize ADC, LEDs, and UART
    ADC_Initialize();
    LedInitialize();

    while(1)
    {

        // Start ADC conversion
        ADC_StartConversion();
        
        // Wait for conversion to complete
        while(!ADC_ConversionDone());
        
        // Get ADC value
        int adcValue = ADC_GetValue();
        
        // Display 8 high order bits on LEDs
        unsigned char ledValue = (adcValue >> 4) & 0xFF;
        
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