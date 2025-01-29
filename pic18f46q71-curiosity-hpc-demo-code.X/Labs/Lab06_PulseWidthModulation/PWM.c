/**
  Pulse Width Modulation Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    PWM.c

  Summary:
    This is the source file for the PWM lab

  Description:
    This source file contains the code on how the PWM lab works.
 */

/*
    (c) 2016 Microchip Technology Inc. and its subsidiaries. You may use this
    software and any derivatives exclusively with Microchip products.

    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
    WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
    PARTICULAR PURPOSE, OR ITS INTERACTION WITH MICROCHIP PRODUCTS, COMBINATION
    WITH ANY OTHER PRODUCTS, OR USE IN ANY APPLICATION.

    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
    BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
    FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
    ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
    THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.

    MICROCHIP PROVIDES THIS SOFTWARE CONDITIONALLY UPON YOUR ACCEPTANCE OF THESE
    TERMS.
 */

#include "../../mcc_generated_files/system/system.h"
#include "../../labs.h"

void PWM_Output_D5_Enable(void);
void PWM_Output_D5_Disable(void);

static uint16_t adcResult;

void PWM(void) {
    if (labState == NOT_RUNNING) {
        LEDs_SetLow();
        PWM_Output_D5_Enable();

        labState = RUNNING;
    }

    if (labState == RUNNING) {
        adcResult = (uint16_t)(ADC_ChannelSelectAndConvert(POT_CHANNEL));
        printf("ADC Result: %u\n\r", adcResult);                                // Printing ADC result on Serial port
        PWM3_16BIT_SetSlice1Output1DutyCycleRegister(adcResult);
        PWM3_16BIT_LoadBufferRegisters();
    }

    if (switchEvent) {
        PWM_Output_D5_Disable();
        labState = NOT_RUNNING;
    }
}

void PWM_Output_D5_Enable(void) {    
    RA7PPS = 0x5;                  // Set D5 as the output of CLC5
}

void PWM_Output_D5_Disable(void) {       
    RA7PPS = 0x00;                  // Set D5 as GPIO pin
}
/**
 End of File
 */
