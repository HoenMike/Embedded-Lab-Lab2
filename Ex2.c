int main(void)
{
  UART_Initialize(9600);
	LedInitialize();
	
  while(1)
  {
    if(UART_Buffer_Count>0)
    {
      if(UART_Buffer[UART_Buffer_Count-1] == 0xFF)
	     {
        for(int i =0 ; i<8;i++)
				 LedOn(i)
        UART_Send("\nLEDs are turned on",19);
        UART_Buffer_Count = 0;
      }
      else if(UART_Buffer[UART_Buffer_Count-1] == 0xF0)
      {
       for(int i =0 ; i<8;i++)
				 LedOff(i)
        UART_Send("\nLEDs are turned off",20);
        UART_Buffer_Count = 0;
      }
    }
  }
}