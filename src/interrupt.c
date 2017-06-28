#include <stdio.h>
#include <stdlib.h>
#include <xc.h>
#include <pic18f4550.h>
#define _XTAL_FREQ 8000000

void reset_interrupt(){
    INTCON = 0x0;
}

void config_tmr0(){
    INTCONbits.PEIE_GIEL = 1;
    T0CON = 0x00;
    T0CONbits.TMR0ON = 1;
    T0CONbits.T0PS = 3;
    INTCONbits.TMR0IE = 1;
    INTCONbits.GIE_GIEH = 1;
}

void config_int0(){
    INTCONbits.PEIE_GIEL = 0;
    TRISBbits.RB0 = 1;
    INTCON2bits.INTEDG0 = 0;
    INTCONbits.INT0IF = 0;
    INTCONbits.INT0IE = 1;
    INTCONbits.GIE_GIEH = 1;
}

void config_int1(){
    INTCONbits.GIE_GIEH = 1;
    INTCONbits.PEIE_GIEL = 0;
    TRISBbits.RB1 = 1;
    INTCON3bits.INT1IE = 1;
    INTCON2bits.INTEDG2 = 0;
    INTCON3bits.INT2IF = 0;
}

void config_int2(){
    INTCONbits.GIE_GIEH = 1;
    INTCONbits.PEIE_GIEL = 0;
    TRISBbits.RB2 = 1;
    INTCON3bits.INT2E = 1;
    INTCON2bits.INTEDG2 = 0;
    INTCON3bits.INT2IF = 0;
}

void interrupt ISR(){
    if(INTCONbits.INT0IF){      //Bot�o 1 pressionado
        INTCONbits.INT0IF = 0;
        //button_1();
        PORTDbits.RD1 = !PORTDbits.RD1;
    }
    
    if(INTCON3bits.INT1IF){     //Bot�o 2 pressionado    
        INTCON3bits.INT1IF = 0;
        //button_2();
    }
    
    if(INTCON3bits.INT2IF){     //Bot�o 3 pressionado
        INTCON3bits.INT2F = 0; 
        //button_3();
    } 
}