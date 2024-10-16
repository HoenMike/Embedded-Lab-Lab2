#include "cmsis_os.h"                       // ARM::CMSIS:RTOS:Keil RTX
#include "LPC17xx.h" // Device header
void LedInitialize(void);
void LedOn( int);
void LedOff(int);
void LedInitialize(){
	LPC_SC->PCONP       |= (1 << 15);         // Enable power to GPIO & IOCON
  LPC_GPIO1->FIODIR = 0xB0000000;
  LPC_GPIO2->FIODIR = 0x0000007C;
}
void LedOn(int index){
	switch(index){
		case 0:
			LPC_GPIO2->FIOSET = 1 << 6; 
			break;
		case 1:
			LPC_GPIO2->FIOSET = 1 << 5; 
			break;
		case 2:
			LPC_GPIO2->FIOSET = 1 << 4; 
			break;
		case 3:
			LPC_GPIO2->FIOSET = 1 << 3; 
			break;
		case 4:
			LPC_GPIO2->FIOSET = 1 << 2; 
			break;
		case 5:
			LPC_GPIO1->FIOSET = 1 << 31; 
			break;
		case 6:
			LPC_GPIO1->FIOSET = 1 << 29; 
			break;
		case 7:
			LPC_GPIO1->FIOSET = 1 << 28; 
			break;
	} 
}
void LedOff(int index){
	switch(index){
		case 0:
			LPC_GPIO2->FIOCLR = 1 << 6; 
			break;
		case 1:
			LPC_GPIO2->FIOCLR = 1 << 5; 
			break;
		case 2:
			LPC_GPIO2->FIOCLR = 1 << 4; 
			break;
		case 3:
			LPC_GPIO2->FIOCLR = 1 << 3; 
			break;
		case 4:
			LPC_GPIO2->FIOCLR = 1 << 2; 
			break;
		case 5:
			LPC_GPIO1->FIOCLR = 1 << 31; 
			break;
		case 6:
			LPC_GPIO1->FIOCLR = 1 << 29; 
			break;
		case 7:
			LPC_GPIO1->FIOCLR = 1 << 28; 
			break;
	} 
}