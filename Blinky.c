// #include "cmsis_os.h"                  // ARM::CMSIS:RTOS:Keil RTX
// #include "LPC17xx.h"                   // Device header
// #include "Led.h"
// #include "Joystick.h"
// void Led_Style_OnOffEachLed(void);
// void LedChasing(void);
// void LedChasing3(void);
// void Led_Style_OnOffEachLed()
// {
//    int i;
//   for(i=0; i<8; i++)
//   {
//     LedOn(i);                        // Turn on Led i
//     osDelay(1000);                    // Delay 1000ms
//     LedOff(i);                       // Turn off Led i
//   }
// }
// void LedChasing(){
// 	int i;
// 	for(i=0; i<8; i++)
//   {
//     LedOn(i);                        // Turn on Led i
//     osDelay(1000);                    // Delay 1000ms                       // Turn off Led i
//   }
// 	for(i=0; i<8; i++)
//   {
//     LedOff(i);                        // Turn on Led i
//     osDelay(1000);                    // Delay 1000ms                       // Turn off Led i
//   }
// }
// void LedChasing3(){
// 	 int i;
// 	for(i=-2; i<11; i++)
//   {
// 		for(int j =0 ; j<8;j++)
// 		{
// 			LedOff(j);
// 		}
// 	  LedOn(i-1);
// 		LedOn(i);
// 		LedOn(i+1);
//     osDelay(1000);                    // Delay 1000ms                       // Turn off Led i
//   }
	
// }

// int main()
// {
	
//     LedInitialize();
//     Joystick_Initialize();
    
//     while(1) {
// 			Joystick_Status_Enum  status = Joystick_Get_Status();
//            switch(status) {
//             case JOYSTICK_UP:
//                 // Implement "Chasing" style
// 						LedChasing();
//                 break;
//             case JOYSTICK_DOWN:
//                 // Implement "3 led chasing" style
// 						LedChasing3();
//                 break;
//             case JOYSTICK_LEFT:
//                 // Implement "Blinking each led" style
// 						 Led_Style_OnOffEachLed();
//                 break;
//             case JOYSTICK_RIGHT:
//                 // Turn off all LEDs
//               for(int j =0 ; j<8;j++)
// 		{
// 			LedOff(j);
// 		}
//                 break;
//             case JOYSTICK_CENTER:
//                 // Turn off all LEDs
//               for(int j =0 ; j<8;j++)
// 		{
// 			LedOn(j);
			
// 		}
// 		break;
           
//         }
//         // Add a small delay to debounce the joystick input
        
//         osDelay(50);
//     }
// }