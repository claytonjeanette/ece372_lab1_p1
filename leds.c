/*
* File:   leds.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include <xc.h>

#define OUTPUT 0
#define INPUT 1
void initLEDs(){
    //TODO: Initialize the appropriate pins to work with the LEDs
    TRISDbits.TRISD1=OUTPUT; // RUN LED
    TRISDbits.TRISD2=OUTPUT;// STOP LED
    LATBbits.LATB1=OUTPUT;
    LATBbits.LATB2=OUTPUT;    
}
void turnOnLED(int led){
    if(led==1)// RUN LED LIGHT
    {
        LATBbits.LATB1=INPUT;
        LATBbits.LATB2=OUTPUT;   
    }  
    if(led==2)// STOP LED LIGHT
    {
        LATBbits.LATB1=OUTPUT;
        LATBbits.LATB2=INPUT;    
    }
}
