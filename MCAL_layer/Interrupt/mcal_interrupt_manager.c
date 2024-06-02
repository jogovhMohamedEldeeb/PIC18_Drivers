/* 
 * File:   mcal_interrupt_manager.c
 * Author: m7md
 *
 * Created on 02 August 2023, 20:26
 */

#include "mcal_interrupt_manager.h"


static volatile uint8 RB4_Flag = 1, RB5_Flag = 1, RB6_Flag = 1, RB7_Flag = 1;

#if INTERRUPT_PRIORITY_LEVELS_ENABLE==INTERRUPT_FEATURE_ENABLE
 
void __interrupt() InterruptManagerHigh(void){
    if((INTERRUPT_ENABLE == INTCON3bits.INT2IE) && (INTERRUPT_OCCUR == INTCON3bits.INT2IF)){
        INT2_ISR();
    }
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == INTCONbits.INT0IE) && (INTERRUPT_OCCUR == INTCONbits.INT0IF)){
        INT0_ISR();
    }
    else{ /* Nothing */ }
}


void __interrupt(low_priority) InterruptManagerLow(void){
    if((INTERRUPT_ENABLE == INTCON3bits.INT1E) && (INTERRUPT_OCCUR == INTCON3bits.INT1F)){
        INT1_ISR();
    }
    else{ /* Nothing */ }
}

    
#else
void __interrupt() InterruptManager(void){
    /* ============ INTx External On Change Interrupt Start ============ */
    if((INTCONbits.INT0IE == INTERRUPT_ENABLE) && (INTCONbits.INT0IF == INTERRUPT_OCCUR)){
        INT0_ISR();
    }
    else{
        /* Nothing */
    }
    if((INTCON3bits.INT1E == INTERRUPT_ENABLE) && (INTCON3bits.INT1F == INTERRUPT_OCCUR)){
        INT1_ISR();
    }
    else{
        /* Nothing */
    }
    if((INTCON3bits.INT2IE == INTERRUPT_ENABLE) && (INTCON3bits.INT2IF == INTERRUPT_OCCUR)){
        INT2_ISR();
    }
    else{
        /* Nothing */
    }
    /* ============ INTx External On Change Interrupt End ============ */
    
    /* ============ PortB External On Change Interrupt Start ============ */
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB4 == GPIO_HIGH) && (RB4_Flag == 1)){
         RB4_Flag = 0;
         RB4_ISR(0);
    }
    else{
        /* Nothing */
    }
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB4 == GPIO_LOW) && (RB4_Flag == 0)){
         RB4_Flag = 1;
         RB4_ISR(1);
    }
    else{
        /* Nothing */
    }
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB5 == GPIO_HIGH) && (RB5_Flag == 1)){
         RB5_Flag = 0;
         RB5_ISR(0);
    }
    else{
        /* Nothing */
    }
     if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB5 == GPIO_LOW) && (RB5_Flag == 0)){
         RB5_Flag = 1;
         RB5_ISR(1);
    }
    else{
        /* Nothing */
    }
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB6 == GPIO_HIGH) && (RB6_Flag == 1)){
         RB6_Flag = 0;
         RB6_ISR(0);
    }
    else{
        /* Nothing */
    }
     if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB6 == GPIO_LOW) && (RB6_Flag == 0)){
         RB6_Flag = 1;
         RB6_ISR(1);
    }
    else{
        /* Nothing */
    }
    if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB7 == GPIO_HIGH) && (RB7_Flag == 1)){
         RB7_Flag = 0;
         RB7_ISR(0);
    }
    else{
        /* Nothing */
    }
     if((INTCONbits.RBIE == INTERRUPT_ENABLE) && (INTCONbits.RBIF == INTERRUPT_OCCUR) && 
            (PORTBbits.RB7== GPIO_LOW) && (RB7_Flag == 0)){
         RB7_Flag = 1;
         RB7_ISR(1);
    }
    else{
        /* Nothing */
    }
    
    /* ============ PortB External On Change Interrupt End ============ */
    
    if((PIE1bits.ADIE == INTERRUPT_ENABLE) && (PIR1bits.ADIF == INTERRUPT_OCCUR)){
       ADC_ISR();
    }
    else{
        /* Nothing */
    }
    
    if((INTCONbits.TMR0IE == INTERRUPT_ENABLE) && (INTCONbits.TMR0IF == INTERRUPT_OCCUR)){
        TMR0_ISR();
    }
    else{
        /* Nothing */
    }
    
    if((PIE1bits.TMR1IE == INTERRUPT_ENABLE) && (PIR1bits.TMR1IF == INTERRUPT_OCCUR)){
        TMR1_ISR();
    }
    else{
        /* Nothing */
    } 
    
    if((PIE1bits.TMR2IE == INTERRUPT_ENABLE) && (PIR1bits.TMR2IF == INTERRUPT_OCCUR)){
        TMR2_ISR();
    }
    else{
        /* Nothing */
    } 
    
    if((PIE2bits.TMR3IE == INTERRUPT_ENABLE) && (PIR2bits.TMR3IF == INTERRUPT_OCCUR)){
        TMR3_ISR();
    }
    else{
        /* Nothing */
    } 
    
    if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (INTERRUPT_OCCUR == PIR1bits.SSPIF)){
        MSSP_I2C_ISR();
    }
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == PIE2bits.BCLIE) && (INTERRUPT_OCCUR == PIR2bits.BCLIF)){
        MSSP_I2C_BC_ISR();
    }
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == PIE1bits.SSPIE) && (INTERRUPT_OCCUR == PIR1bits.SSPIF)){
        MSSP_SPI_ISR();
    }
    else{ /* Nothing */ }
    
      
    /* ============ CCP1 and CCP2 Modules Interrupt Start ============ */
    if((INTERRUPT_ENABLE == PIE1bits.CCP1IE) && (INTERRUPT_OCCUR == PIR1bits.CCP1IF)){
        CCP1_ISR();
    }
    else{ /* Nothing */ }
    if((INTERRUPT_ENABLE == PIE2bits.CCP2IE) && (INTERRUPT_OCCUR == PIR2bits.CCP2IF)){
        CCP2_ISR();
    }
    else{ /* Nothing */ }
}
#endif
