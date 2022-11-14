/**
  TMR0 Generated Driver API Header File
 
  @Company
    Microchip Technology Inc.
 
  @File Name
    tmr0.h
 
  @Summary
    This is the generated header file for the TMR0 driver
 
  @Description
    This header file provides APIs for driver for TMR0.
    Generation Information :
        Driver Version    :  2.01
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.31
        MPLAB             :  MPLAB X v5.45
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

#ifndef TMR0_H
#define TMR0_H

/**
 * @brief This file contains API prototypes and other datatypes for Timer-0 module.
 * @defgroup timer0_driver  Timer 0
 * @{
 */

#include <stdint.h>
#include <stdbool.h>
#include "timer_interface.h"


/**
 @ingroup timer0_driver
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for Timer-0 module
 */
extern const struct TMR_INTERFACE Timer0;

/**
 * @ingroup timer0_driver
 * @brief This API initializes the Timer-0 module.
 *        This routine must be called before any other Timer-0 routines.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {   
 *         Timer0_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer0_Initialize(void);

/**
 * @ingroup timer0_driver
 * @brief This function starts Timer-0.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer0_Start();
 *     
 *     while(1)
 *     {
 *         Timer0_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer0_Start(void);

/**
 * @ingroup timer0_driver
 * @brief This function stops Timer-0.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void customAppCallback(void)
 * {
 *     static uint8_t counter;
 *     if(counter++ == 10)
 *     {
 *         counter = 0;
 *         //Stop timer after 10 timeouts
 *         Timer0_Stop();
 *     }
 * }
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {
 *         Timer0_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer0_Stop(void);

/**
 * @ingroup timer0_driver
 * @brief This function reads the 8 bits from TMRTMR0 register.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param void.
 * @return 8-bit data from TMRTMR0 register.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer0_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer0_Read() == 0x80)
 *         {
 *             //do something
 *         }
 *     }
 * }
 * @endcode
 */
uint8_t Timer0_Read(void);

/**
 * @ingroup timer0_driver
 * @brief This function writes 8-bit value to TMRTMR0 register.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param 8-bit value to be written to TMRTMR0 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {
 *         if(Timer0_Read() == 0x0)
 *         {
 *             Timer0_Write(0x80)
 *         }
 *     }
 * }
 * @endcode
 */
void Timer0_Write(size_t timerVal);

/**
 * @ingroup timer0_driver
 * @brief This function loads 8 bit value to TMRTMR0H register.
 *        Timer-0 should be initialized with Timer0_Initialize() before calling this API.
 * @param 8-bit value to be written to TMRTMR0H register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             //Change the period value of TMR0
 *             Timer0_Reload(0x80);
 *         }
 *     }
 * }
 * @endcode
 */
void Timer0_Reload(uint8_t periodVal);


/**
 * @ingroup timer0_driver
 * @brief Setter function for Timer-0 overflow Callback.
 * @param CallbackHandler - Pointer to custom Callback.
 * @return void
 *
 * @code
 * void customOverflowCallback(void)
 * {
 *    //Custom ISR code
 * }
 *
 * void main(void)
 * {
 *     Timer0_Initialize();
 *     Timer0_OverflowCallbackRegister(customOverflowCallback);
 *
 *     while(1)
 *     {
 *     }
 * }
 * @endcode
 */
 void Timer0_OverflowCallbackRegister(void (* CallbackHandler)(void));


/**
 * @}
 */
#endif //TMR0_H
