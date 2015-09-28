/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>
void initTimer1(){
    TMR1=0;// clear timer1
    T1CONbits.ON=1;// enable timer1
    T1CONbits.TCKPS=0;// pre-scalar is equal to 1
    T1CONbits.TCS=0;// internal oscillator 
    IFS0bits.T1IF=0;// Put down flag
    //IPC2bits.T1IP=3;// configure the interrupt priority 
    IEC0bits.T1IE=1; // Enable the interrupt
}

//Uses timer 1 the oscillator is 10M (*20/2/16/8)
void delayUs(unsigned int delay){
    //TODO: Create a delay using timer 1 for "delay" microseconds.
    TMR1=0;// clear timer1
    PR1= delay*781;// delay 1ms 
    IFS0bits.T1IF=0;// Put flag down
    T1CONbits.ON=1;// enable timer1
    while(IFS0bits.T1IF==0);
    T1CONbits.ON=0;//turn off timer1
   
}




