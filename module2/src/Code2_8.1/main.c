/*---------------------------------------------------------------------------- 

LAB EXERCISE 8.1 - DIGITAL INPUTS AND OUTPUTS 

PROGRAMMING USING MBED API 

 ---------------------------------------- 

 In this exercise you need to use the mbed API functions to: 

  

1) Define BusIn, BusOut interfaces for inputs and outputs 

2) The LED is controlled by the button: 

+ USER_BUTTON - LED1 

 

GOOD LUCK! 

 *----------------------------------------------------------------------------*/ 

 

#include "mbed.h" 

 

//Define input bus 

//Write your code here 

BusIn buttons(D2,D3,D4,D5); //1 - PA_10/D2, 2 - PB_3/D3, 4 - PB_5/D4, 8 - PB_4/D5 

 

//Define output bus for the  LED 

//Write your code here 

BusOut leds(LED2,D8); //1 - nucleo led , 2 - breadboard led 

 

/*---------------------------------------------------------------------------- 

 MAIN function 

 *----------------------------------------------------------------------------*/ 

 

int main(){ 

 

while(1){ 

 

//Check which button was pressed and light up the corresponding LED 

//Write your code here 

// This will control the led on the nucleo board 

if ((buttons & 0x2) && not (buttons & 0x1)) { 

leds = leds | 0x1; 

} else if ((buttons & 0x1) && not (buttons & 0x2)){ 

leds = leds & 0x2; 

} 

 

    if ((buttons & 0x8) && not (buttons & 0x4)) { 

leds = leds | 0x2; 

} else if ((buttons & 0x4) && not (buttons & 0x8)){ 

leds = leds & 0x1; 

} 

__wfi(); // sleep 

} 

} 

 

// *******************************ARM University Program Copyright (c) ARM Ltd 2014************************************* 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
 
