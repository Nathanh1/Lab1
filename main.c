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
#define RUN_LED LATGbits.LATG12 
#define STOP_LED  LATGbits.LATG13
#define ON 1
#define OFF 0

volatile int state = 1;
 


/* Please note that the configuration file has changed from lab 0.
 * the oscillator is now of a different frequency.
 */
int main(void)
{
    initTimer1();
    initLEDs();
    initSW2();
    SYSTEMConfigPerformance(10000000);
    enableInterrupts();
    
    while(1)
    {
        switch(state)
        {
            case 1:
               
               RUN_LED = ON;  // Run LED
               STOP_LED = OFF;  // Stop LED
               
               break;
                
            case 2:
                
                RUN_LED = OFF;  // Run LED
                STOP_LED = ON;  // Stop LED
                
                
                break;
    }
    
    return 0;
}

void __ISR(_CHANGE_NOTICE_VECTOR, IPL7SRS) __CNInterrupt(void)
{
    
    IFS1bits.CNAIF = 0;
    int e;
    e = PORTA;
   
    delayMs(5);
      
      
     if(PORTAbits.RA7 == 1)     
     {
         if(state == 1) state = 2;
         else if(state == 2) state = 1;
     }
     

    //TODO: Implement the interrupt to capture the press of the button

}