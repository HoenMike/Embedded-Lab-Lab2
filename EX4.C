#include "LPC17xx.h"
#include "ADC.h"
#include "led.h"
#include "uart.h"
#include "Joystick.h"
#include <string.h>
#include <stdio.h>

#define UART_BAUD_RATE 9600

void ProcessJoystick(void)
{
  switch (Joystick_Get_Status())
  {
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
    UART_Send("Your Name\r\n", 11); // Replace with your actual name
    break;
  case JOYSTICK_CENTER:
    // You can add functionality for the center button if needed
    break;
  default:
    // No joystick action
    break;
  }
}

void UintToChar(int value, char *buffer)
{
  sprintf(buffer, "%d", value);
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
  char adcValueStr[10];

  UART_Initialize(UART_BAUD_RATE);
  LedInitialize();
  Joystick_Initialize();
  ADC_Initialize();

  while (1)
  {
    // Process Joystick
    if (Joystick_Get_Status() != JOYSTICK_CENTER)
    {
      ProcessJoystick();
    }
    else
    {
      // Process ADC
      ADC_StartConversion();
      while (!ADC_ConversionDone())
        ;
      int adcValue = ADC_GetValue();
      UintToChar(adcValue, adcValueStr);
      UART_Send(adcValueStr, strlen(adcValueStr));
      UART_Send("\r\n", 2);
    }

    // Process UART Commands
    ProcessUARTCommand();

    // osDelay(100); // Small delay to prevent excessive polling
  }
}