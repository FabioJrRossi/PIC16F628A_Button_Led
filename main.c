/*
 * File:   main.c
 * Author: Fabio Jr. Rossi.
 *
 * Main file of the project.
 */

// PIC16F628A Configuration Bit Settings
#pragma config FOSC = INTOSCCLK // Oscillator Selection bits (INTOSC oscillator: CLKOUT function on RA6/OSC2/CLKOUT pin, I/O function on RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RA5/MCLR/VPP Pin Function Select bit (RA5/MCLR/VPP pin function is digital input, MCLR internally tied to VDD)
#pragma config BOREN = OFF      // Brown-out Detect Enable bit (BOD disabled)
#pragma config LVP = OFF        // Low-Voltage Programming Enable bit (RB4/PGM pin has digital I/O function, HV on MCLR must be used for programming)
#pragma config CPD = OFF        // Data EE Memory Code Protection bit (Data memory code protection off)
#pragma config CP = OFF         // Flash Program Memory Code Protection bit (Code protection off)

#define LED PORTAbits.RA0       // Macro for led (PORTA RA0 pin).         
#define BTN PORTAbits.RA1       // Macro for button (PORTA RA1 pin).

#include <xc.h>                 // Standard compiler library.

void main(void) {
    
    CMCON = 0b00000111;         // Disable PORTA comparator. 
    TRISA = 0b00000010;         // Setting RA1 pin to input and other pins of PORTA to output.
          
    while(1) {   
        if(BTN){                // If button pressed.   
            LED = 1;            // Turn on led.
        }    
        else{                   // If button unpressed.    
            LED = 0;            // Turn led off.
        }
    }
    
    return;
}
