/*
 * File:   timer.c
 * Authors:
 *
 * Created on December 30, 2014, 8:07 PM
 */

#include <xc.h>

void initTimer1(){
    TMR1 = 0;
    PR1 = 2442;
    T1CONbits.TCKPS = 3;
    T1CONbits.TCS = 0;
    IEC0bits.T1IE = 1;
    IFS0bits.T1IF = 0;
    IPC1bits.T1IP = 3;
    T1CONbits.ON = 1;


}


//Uses timer 2
void delayMs(unsigned int delay){
    //TODO: Create a delay using timer 2 for "delay" microseconds.
    
    

    TMR1 = 0;
    PR1 = delay*624;
    IFS0bits.T1IF = 0;
    T1CONbits.ON = 1;
    while(IFS0bits.T1IF == 0);
    T1CONbits.ON = 0;
    
    
    
    
}