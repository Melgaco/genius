/*
 * File:   newmain.c
 * Author: Rafael Bessa
 * Author: Neilton Melgaço
 *
 * Created on 28 de Maio de 2019, 16:13
 */

#define _XTAL_FREQ 1000000 // 1 MHz

#include <xc.h>
#include <pic16f877a.h>

// Padrão de configurações
#pragma config FOSC = HS // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF // Watchdog Timer Enable bit (WDT enabled)
#pragma config PWRTE = OFF // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOREN = ON // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF // Flash Program Memory Code Protection bit (Code protection off)

#define  blue 0
#define  green 1
#define  yel 2
#define  red 3
#define max 5
int nivel = 0;

int genius[5] = {blue,blue,yel,green,red};
int i=0;



void PiscaTudo(){
    
    /*
    PORTBbits.RB0 = 1;
    PORTBbits.RB1 = 1;
    PORTBbits.RB2 = 1;
    PORTBbits.RB3 = 1;
    __delay_ms(2000);
    PORTBbits.RB0 = 0;
    PORTBbits.RB1 = 0;
    PORTBbits.RB2 = 0;
    PORTBbits.RB3 = 0;*/
    return;
}
int checarbtn(int nivel){
    int cont=0;
    while(1){
        if(cont>nivel){
            return 1;
        }
        //AZIVIS
        if(PORTCbits.RC0 == 1){
            if(genius[cont] == blue){
                cont++;
                 PORTBbits.RB0 = 1;
                __delay_ms(1000);
                PORTBbits.RB0 = 0;
                 __delay_ms(1000);
                 continue;
            }
            else{
                return 0;
            }
        }
        //VERDE-------------------------
        else if(PORTCbits.RC1 == 1){
            if(genius[cont] == green){
                cont++;
                 PORTBbits.RB1 = 1;
                __delay_ms(1000);
                PORTBbits.RB1 = 0;
                 __delay_ms(1000);
                 continue;
            }
            else{
                return 0;
            }
        }
        //Yel ------------------
        else if(PORTCbits.RC2 == 1){
            if(genius[cont] == yel){
                cont++;
                 PORTBbits.RB2 = 1;
                __delay_ms(1000);
                PORTBbits.RB2 = 0;
                 __delay_ms(1000);
                 continue;
            }
            else{
                return 0;
            }
        }
        //Red ------------------
       else if(PORTCbits.RC3 == 1){
            if(genius[cont] == red){
                cont++;
                 PORTBbits.RB3 = 1;
                __delay_ms(1000);
                PORTBbits.RB3 = 0;
                 __delay_ms(1000);
                 continue;
            }
            else{
                return 0;
            }
        }
        
        
        
        }
        
        
    }
    

void PiscaNivel(int pos){
    int j=0;
    for(j=0;j<=pos;j++){
        __delay_ms(1000);
        switch(genius[j]){
            case blue:
                PORTBbits.RB0 = 1;
                __delay_ms(1000);
                PORTBbits.RB0 = 0;
                break;
            
            case green:
                PORTBbits.RB1 = 1;
                __delay_ms(1000);
                PORTBbits.RB1 = 0;
                break;
            
            case yel:
                PORTBbits.RB2 = 1;
                __delay_ms(1000);
                PORTBbits.RB2 = 0;
                
                break;
                
            case red:
                PORTBbits.RB3 = 1;
                __delay_ms(300);
                PORTBbits.RB3 = 0;
                break;
                
            
        }
        
    }
    return;
}



void main(void) {
    TRISB = 0b00000000;
    TRISC = 0b11111111;
    PORTB = 0;
    PORTC = 1;
    while(1){
        nivel = 0;
       __delay_ms(300);
    PORTBbits.RB0 = 1;
    __delay_ms(100);
    PORTBbits.RB0 = 0;
   PORTBbits.RB1 = 1;
    __delay_ms(100);
    PORTBbits.RB1 = 0;
    PORTBbits.RB2 = 1;
    __delay_ms(100);
    PORTBbits.RB2 = 0;
    PORTBbits.RB3 = 1;
    __delay_ms(100);
    PORTBbits.RB3 = 0;
    
       for(i=0;i<=max-1;i++){
          __delay_ms(1000);
           PiscaNivel(i);
          
             if(checarbtn(nivel) == 0){
            break;   
           }
            nivel +=1;
       } 
       /* if(PORTCbits.RC0 == 1){
        PORTBbits.RB0 = 1;
        }
        if(PORTCbits.RC0 == 0){
        PORTBbits.RB0 = 0;
        }*/
     //    __delay_ms(100);

    }
    return;
}

