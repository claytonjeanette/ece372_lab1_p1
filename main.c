// ******************************************************************************************* //
//
// File:         lab1p1.c
// Date:         
// Authors:      
//
// Description: Part 1 for lab 1
// ******************************************************************************************* //

#include <xc.h>
#include <sys/attribs.h>
#include "leds.h"
#include "interrupt.h"
#include "switch.h"
#include "timer.h"
//#define SW1 PORTDbits.RD0

#define OUTPUT 0
#define INPUT 1
#define delay 5
#define PRESS 0
#define RELEASE 1


typedef enum stateTypeEnum {
    led1, led2, waitRelease1, waitRelease2
 
} stateType;
volatile stateType state;

/* Please note that the configuration file has changed from lab 0.
 * the oscillator is now of a different frequency.
 */
int main(void)
{

    enableInterrupts();
    initSW1();
    initTimer1();
    initLEDs();
    state =led1;
    
    while(1)
    {
        //TODO: Using a finite-state machine, define the behavior of the LEDs
        //Debounce the switch
        switch (state) {
            case led1:
                delayUs(delay);
                turnOnLED(1);// turn run led on
                if(SW1==PRESS){
                    state=waitRelease1;
                }
                break;
            case waitRelease1:
                delayUs(delay);
                if(SW1==PRESS)
                {
                    state=waitRelease1;
                }
                else if(SW1=RELEASE){
                    state=led2;
                }
                break;
            case led2:
                delayUs(delay);
                turnOnLED(2);// turn run led on
                if(SW1==PRESS){
                    state=waitRelease2;
                }
                break;
            case waitRelease2:
                
                delayUs(delay);
                if(SW1==PRESS)
                {
                    state=waitRelease2;
                }
                else if(SW1=RELEASE){
                    state=led1;
                }
                break;
                
                        
                
                
        }
                
       
    }
    
    return 0;
}

void __ISR(_TIMER_1_VECTOR, IPL3SRS) _T1Interrupt(void){
    //TODO: Implement the interrupt to capture the press of the button
    IFS0bits.T1IF = 0;
}