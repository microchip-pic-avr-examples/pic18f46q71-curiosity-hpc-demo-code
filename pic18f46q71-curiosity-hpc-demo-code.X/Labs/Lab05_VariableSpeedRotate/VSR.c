/**
  Variable Speed Rotate Lab Source File

  Company:
    Microchip Technology Inc.

  File Name:
    VSR.c

  Summary:
    This is the source file for the VSR lab

  Description:
    This source file contains the code on how the VSR lab works.
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

static uint8_t delay;
static uint8_t rotateReg;

void VSR(void) {

    if (labState == NOT_RUNNING) {
        LEDs_SetLow();        
        rotateReg = 1;                                                          // Initialize temporary register to begin at 1
        labState = RUNNING;
    }

    if (labState == RUNNING) {        
        delay = (uint8_t)(ADC_ChannelSelectAndConvert(POT_CHANNEL) >> 8);                  // Use the top 8 MSbs of the ADC result as delay
        printf("ADC Result: %u\n\r", ADRES >> 4);                               // Printing ADC result on Serial port
        __delay_ms(2);
    
        while (delay-- != 0) {                                                  // Decrement the 8 MSbs of the ADC and delay each for 2ms
            __delay_ms(2);
        }
    
        LEDs = (uint8_t)(rotateReg << 4);                                                // Determine which LED will light up

        rotateReg <<= 1;
       
        if (rotateReg == LAST) {                                                // Return to initial position of LED
            rotateReg = 1;
        }
    }

    if (switchEvent) {
        labState = NOT_RUNNING;
    }
}
/**
 End of File
 */
