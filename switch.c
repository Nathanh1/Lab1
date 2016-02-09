/*
 * File:   switch.c
 * Author: Garrett
 *
 * Created on September 19, 2015, 10:46 AM
 */

#include <proc/p32mx470f512l.h>
#define ENABLE 1

void initSW2(){
    //TODO: Initialize the appropriate pins to work with the external switch using a
    //change notification interrupt.
    
    TRISAbits.TRISA7 = ENABLE ;
    CNPUAbits.CNPUA7 = ENABLE ;
    CNCONAbits.ON = ENABLE ;
    CNENAbits.CNIEA7 = ENABLE ;
    IFS1bits.CNAIF = 0;                    ///flag
    IPC8bits.CNIP = 7;                     //priority
    IEC1bits.CNAIE = ENABLE ;
}
