/**
  Analog-to-Digital Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    ADC.c

  Summary:
    This is the source file for the ADC lab

  Description:
    This source file contains the code on how the ADC lab works.
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

static uint8_t adcResult;                                                       // Used to store the result of the ADC

void ADC(void) {

    if (labState == NOT_RUNNING) {
        LEDs_SetLow();
        labState = RUNNING;
    }

    if (labState == RUNNING) {        
        adcResult = (uint8_t)(ADC_ChannelSelectAndConvert(POT_CHANNEL) >> 12);             // Get the top 4 MSBs and display it on the LEDs        
        printf("ADC Result: %u\n\r", ADRES >> 4);                               // Printing ADC result on Serial port
        LEDs = (uint8_t)(adcResult << 4);                                                // Determine which LEDs will light up
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
