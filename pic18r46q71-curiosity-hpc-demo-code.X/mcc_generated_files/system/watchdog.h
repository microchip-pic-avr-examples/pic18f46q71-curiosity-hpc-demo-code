/**
  @Generated WWDT Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    watchdog.h

  @Summary:
    This is the watchdog.h file generated using CCL

  @Description:
    This header file provides implementations for driver APIs for all modules selected in the GUI.
    Generation Information :
        Driver Version    :  2.00
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20
        MPLAB             :  MPLAB X 5.40
*/

/*
© [2022] Microchip Technology Inc. and its subsidiaries.

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

#ifndef WATCHDOG_H
#define WATCHDOG_H

 /**
   Section: Included Files
 */

#include <xc.h>
#include <stdbool.h>
#include <stdint.h>

#define WDTCWS  7
#define WDTCCS  16
#define WDTCPS  24


/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes the WWDT to the default states configured in the
 *                  MCC GUI
 * @Example
    WWDT_Initialize();
 */
void WWDT_Initialize(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
   Enable the WWDT by setting the SEN bit.
 * @Example
    WWDT_SoftEnable();
 */
void WWDT_SoftEnable(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
   Disable the WWDT by clearing the SEN bit.
 * @Example
    WWDT_SoftDisable();
 */
void WWDT_SoftDisable(void);

/**
 * @Param
    none
 * @Returns
    none
 * @Description
   Disable the interrupt, arm the WWDT by reading back the WDTCON0 register
 * clear the WWDT and enable the interrupt.
 * @Example
    WWDT_TimerClear();
 */
void WWDT_TimerClear(void);

/**
 * @Param
    none
 * @Returns
   High --> WWDT reset has not occurred. 
 * Low  --> WWDT reset has  occurred.
 * @Description
    Returns the status of whether the WWDT reset has occurred or not.
 * @Example
    if(WWDT_TimeOutStatusGet())
 */
bool WWDT_TimeOutStatusGet(void);

/**
 * @Param
    none
 * @Returns
   High --> WWDT window violation reset has not occurred. 
 * Low  --> WWDT window violation reset has  occurred.
 * @Description
    Returns the status of, whether the WWDT window violation 
 *  reset has occurred or not.
 * @Example
    if(WWDT_WindowViolationStatusGet())
 */
bool WWDT_WindowViolationStatusGet(void);  

#endif	/* WATCHDOG_H */
/**
 End of File
*/