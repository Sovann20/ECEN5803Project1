/*---------------------------------------------------------------------------- 

LAB EXERCISE 9 - Analog input and PWM 

 ---------------------------------------- 

Use two potentiometers to adjust the volume and pitch of the output sound wave. 

 

Inputs: Virtual potentiometers 1 and 2 

Output: Virtual speaker,  Real PC 

 

GOOD LUCK! 

 *----------------------------------------------------------------------------*/ 

 

#include "mbed.h" 

#include "pindef.h" 

 

/* 

Define the PWM speaker output 

Define analog inputs 

Define serial output 

*/ 

 

//Write your code here 

  PwmOut speaker(D6); // Speaker Output 

AnalogIn pitchControl(A0); // Picth Control 

AnalogIn volumeControl(A1); // Volume Control 

 	 

 

 

//Define variables 

float i; 

 

/*---------------------------------------------------------------------------- 

 MAIN function 

 *----------------------------------------------------------------------------*/ 

 

int main(){ 

while(1){ 

/* 

Print values of the potentiometers to the PC serial terminal 

Create a saw-tooth sound wave 

Make the period and volume adjustable using the potentiometers 

*/ 

float freq = (7680.0f * ((pitchControl.read() - 0.49f)/0.51f) + 320.0f); // will need to do some math to map the pitch 

float volume = (volumeControl.read()-0.49f)/0.51f; // maps volume analog input to duty cycle 

volume = volume < 0.01 ? 0 : volume; 

 

printf("Frequency: %f\r\n",freq); 

printf("Volume: %0.2f\r\n",volume); 

 

speaker.period(1.0f/freq); 

 

for(i=0; i<1; i+=0.1) { 

speaker = i * volume; 

// will need to wait here to make the entire loop one period 

wait_ms(20); 

} 

 

 

} 

} 

 

// *******************************ARM University Program Copyright © ARM Ltd 2014************************************* 

 
