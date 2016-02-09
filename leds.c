/*
* File:   leds.c
* Author: 
*
* Created on December 27, 2014, 1:31 PM
*/

#include <xc.h>
#define OUTPUT 0
#define INPUT 1
#define OFF 0
#define ON 1
#define RUN_LED LATGbits.LATG12 
#define STOP_LED  LATGbits.LATG14
#define TRIS_RUN TRISGbits.TRISG12
#define TRIS_STOP TRISGbits.TRISG14

void initLEDs()
{
    
    TRIS_RUN = OUTPUT;
    TRIS_STOP = OUTPUT;
    
    
    RUN_LED = ON;  // Run LED
    STOP_LED = OFF;  // Stop
    
}