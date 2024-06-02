/* 
 * File:   mcal_interrupt_manager.h
 * Author: m7md
 *
 * Created on 02 August 2023, 20:26
 */

#ifndef MCAL_INTERRUPT_MANAGER_H
#define	MCAL_INTERRUPT_MANAGER_H

/************************ Includes ************************/
#include "mcal_interrupt_config.h"

/************************  Macro Declaration ************************/
 

/************************  Macro Function Declaration ************************/


/************************  Data Type Declaration ************************/
 

/************************  Software interface Declaration ************************/
void INT0_ISR(void);
void INT1_ISR(void);
void INT2_ISR(void);

void RB4_ISR(uint8 RB4_source);
void RB5_ISR(uint8 RB5_source);
void RB6_ISR(uint8 RB5_source);
void RB7_ISR(uint8 RB5_source);

void ADC_ISR();

void TMR0_ISR();
void TMR1_ISR(void);
void TMR2_ISR(void);
void TMR3_ISR(void);

void MSSP_I2C_BC_ISR(void);
void MSSP_I2C_ISR(void);
void MSSP_SPI_ISR(void);

void CCP1_ISR(void);
void CCP2_ISR(void);
#endif	/* MCAL_INTERRUPT_MANAGER_H */

