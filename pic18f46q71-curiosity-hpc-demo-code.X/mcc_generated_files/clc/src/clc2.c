/**
 * CLC2 Generated Driver File.
 * 
 * @file clc2.c
 * 
 * @ingroup  clc2
 * 
 * @brief This file contains the API implementations for the CLC2 driver.
 *
 * @version CLC2 Driver Version 1.2.0
*/
/*
© [2025] Microchip Technology Inc. and its subsidiaries.

    Subject to your compliance with these terms, you may use Microchip 
    software and any derivatives exclusively with Microchip products. 
    You are responsible for complying with 3rd party license terms  
    applicable to your use of 3rd party software (including open source  
    software) that may accompany Microchip software. SOFTWARE IS ?AS IS.? 
    NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS 
    SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,  
    MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT 
    WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY 
    KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF 
    MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE 
    FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S 
    TOTAL LIABILITY ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT 
    EXCEED AMOUNT OF FEES, IF ANY, YOU PAID DIRECTLY TO MICROCHIP FOR 
    THIS SOFTWARE.
*/


#include <xc.h>
#include "../clc2.h"


static void (*CLC2_Callback)(void);
static void CLC2_DefaultCallback(void);

void CLC2_Initialize(void) 
{
    
    // SLCT 0x1; 
    CLCSELECT = 0x1;
    // LCG1POL not_inverted; LCG2POL inverted; LCG3POL not_inverted; LCG4POL not_inverted; LCPOL not_inverted; 
    CLCnPOL = 0x2;
    // LCD1S CLCIN0 (CLCIN0PPS); 
    CLCnSEL0 = 0x0;
    // LCD2S TMR2; 
    CLCnSEL1 = 0x14;
    // LCD3S CLCIN0 (CLCIN0PPS); 
    CLCnSEL2 = 0x0;
    // LCD4S CLCIN0 (CLCIN0PPS); 
    CLCnSEL3 = 0x0;
    // LCG1D1N disabled; LCG1D1T disabled; LCG1D2N disabled; LCG1D2T enabled; LCG1D3N disabled; LCG1D3T disabled; LCG1D4N disabled; LCG1D4T disabled; 
    CLCnGLS0 = 0x8;
    // LCG2D1N disabled; LCG2D1T enabled; LCG2D2N disabled; LCG2D2T disabled; LCG2D3N disabled; LCG2D3T disabled; LCG2D4N disabled; LCG2D4T disabled; 
    CLCnGLS1 = 0x2;
    // LCG3D1N disabled; LCG3D1T enabled; LCG3D2N disabled; LCG3D2T disabled; LCG3D3N disabled; LCG3D3T disabled; LCG3D4N disabled; LCG3D4T disabled; 
    CLCnGLS2 = 0x2;
    // LCG4D1N disabled; LCG4D1T disabled; LCG4D2N disabled; LCG4D2T disabled; LCG4D3N disabled; LCG4D3T disabled; LCG4D4N disabled; LCG4D4T disabled; 
    CLCnGLS3 = 0x0;
    // LCOUT 0x00; 
    CLCDATA = 0x0;
    // LCMODE 1-input D flip-flop with S and R; LCINTN disabled; LCINTP enabled; LCEN enabled; 
    CLCnCON = 0x94;

    //Set default callback for CLC2 interrupt Overflow.
    CLC2_CallbackRegister(CLC2_DefaultCallback);

    // Clear the CLC interrupt flag
    PIR5bits.CLC2IF = 0;
}

void CLC2_Enable(void) 
{
    CLCSELECTbits.SLCT = 1;
    CLCnCONbits.EN = 1;
}

void CLC2_Disable(void) 
{
    CLCSELECTbits.SLCT = 1;
    CLCnCONbits.EN = 0;
}

void CLC2_RisingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 1;
    CLCnCONbits.INTP = 1;
}

void CLC2_RisingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 1;
    CLCnCONbits.INTP = 0;
}

void CLC2_FallingEdgeDetectionEnable(void) 
{
    CLCSELECTbits.SLCT = 1;
    CLCnCONbits.INTN = 1;
}

void CLC2_FallingEdgeDetectionDisable(void) 
{
    CLCSELECTbits.SLCT = 1;
    CLCnCONbits.INTN = 0;
}

void CLC2_CallbackRegister(void (* CallbackHandler)(void))
{
    CLC2_Callback = CallbackHandler;
}

static void CLC2_DefaultCallback(void)
{
    //Add your interrupt code here or
    //Use CLC2_CallbackRegister function to use Custom ISR
}

void CLC2_Tasks(void)
{
    if(PIR5bits.CLC2IF == 1)
    {
        if(CLC2_Callback != NULL)
        {
            CLC2_Callback();
        }
        PIR5bits.CLC2IF = 0;
    }
}


bool CLC2_OutputStatusGet(void) 
{
    return(CLCDATAbits.CLC2OUT);
}
/**
 End of File
*/
