/**
  TMR1 Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    tmr1.h

  @Summary
    This is the generated header file for the TMR1 driver

  @Description
    This header file provides APIs for driver for TMR1.
    Generation Information :
        Driver Version    :  3.0.0
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

#ifndef TMR1_H
#define TMR1_H

#include <stdbool.h>
#include <stdint.h>
#include "timer_interface.h"


/**
 @ingroup timer0_driver
 @struct TMR_INTERFACE
 @brief This is an instance of TMR_INTERFACE for Timer module
 */
extern const struct TMR_INTERFACE Timer1;

/**
 * @brief This API initializes the Timer module.
 *        This routine must be called before any other Timer routines.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     while(1)
 *     {   
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Initialize(void);


/**
 * @brief This function starts Timer
 *        Timer-0 should be initialized with Timer1_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Start(void);

/**
 * @brief This function stops Timer
 *        Timer-0 should be initialized with Timer1_Initialize() before calling this API.
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
 *         Timer1_Stop();
 *     }
 * }
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Stop(void);

/**
 * @brief This function reads the 16-bits from TMR1 register.
 *        Timer should be initialized with Timer1_Initialize() before calling this API.
 * @param void.
 * @return 16-bit data from TMR1 register.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer1_Read() == 0x8000)
 *         {
 *             //do something
 *         }
 *     }
 * }
 * @endcode
 */
uint16_t Timer1_Read(void);

/**
 * @brief This function writes 16-bit value to TMR1 register.
 *        Timer should be initialized with Timer1_Initialize() before calling this API.
 * @param 16-bit value to be written to TMR1 register.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         if(Timer1_Read() == 0x0)
 *         {
 *             Timer1_Write(0x8000)
 *         }
 *     }
 * }
 * @endcode
 */
void Timer1_Write(size_t timerVal);

/**
 * @brief This function loads 8 bit value to TMR1 register.
 *        Timer should be initialized with Timer1_Initialize() before calling this API.
 * @param void.
 * @return void.
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *     
 *     while(1)
 *     {
 *         if(some_condition)
 *         {
 *             //Change the period value of TMR1
 *             Timer1_Reload();
 *         }
 *     }
 * }
 * @endcode
 */
void Timer1_Reload(void);


/**
 * @brief This function starts the single pulse acquisition in TMR1 gate operation.
 *        This function must be used when the TMR1 gate is enabled.
 * @param void.
 * @return void.
 *
 * @code
 * uint16_t xVal;
 *   uint16_t yVal;
 *
 *   // enable TMR1 singlepulse mode
 *   Timer1_StartSinglePulseAcquistion();
 *
 *   // check TMR1 gate status
 *   if(Timer1_CheckGateValueStatus()== 0)
 *       xVal = Timer1_Read();
 *
 *   // wait untill gate interrupt occured
 *   while(TMR1GIF == 0)
 *   {
 *   }
 *
 *   yVal = Timer1_Read();
 * @endcode
 */

void Timer1_StartSinglePulseAcquisition(void);

/**
  @Summary
    Check the current state of Timer1 gate.

  @Description
    This function reads the TMR1 gate value and return it.
    This function must be used when the TMR1 gate is enabled.

  @Preconditions
    Initialize  the TMR1 with gate enable before calling this function.

  @Param
    None

  @Returns
    None

  @Example
    <code>
    uint16_t xVal;
    uint16_t yVal;

    // enable TMR1 singlepulse mode
    Timer1_StartSinglePulseAcquistion();

    // check TMR1 gate status
    if(Timer1_CheckGateValueStatus()== 0)
        xVal = Timer1_Read();

    // wait untill gate interrupt occured
    while(TMR1IF == 0)
    {
    }

    yVal = Timer1_Read();
    </code>
*/
uint8_t Timer1_CheckGateValueStatus(void);


/**
 * @brief Setter function for Timer overflow Callback.
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
 *     Timer1_Initialize();
 *     Timer1_OverflowCallbackRegister(customOverflowCallback);
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *
 *     while(1)
 *     {
 *     }
 * }
 * @endcode
 */
 void Timer1_OverflowCallbackRegister(void (* CallbackHandler)(void));

/**
 * @brief This function performs tasks to be executed on timer overflow event
 * @param void
 * @return void
 *
 * @code
 * void main(void)
 * {
 *     Timer1_Initialize();
 *     //Start timer if it is not already started
 *     Timer1_Start();
 *
 *     while(1)
 *     {
 *         Timer1_Tasks();
 *     }
 * }
 * @endcode
 */
void Timer1_Tasks(void);

/**
  @Summary
    Boolean routine to poll or to check for the overflow flag on the fly.

  @Description
    This function is called to check for the timer overflow flag.
    This function is usd in timer polling method.

  @Preconditions
    Initialize  the TMR1 module before calling this routine.

  @Param
    None

  @Returns
    true - timer overflow has occured.
    false - timer overflow has not occured.

  @Example
    <code>
    while(1)
    {
        // check the overflow flag
        if(Timer1_HasOverflowOccured())
        {
            // Do something else...

            // clear the TMR1 interrupt flag
            TMR1IF = 0;

            // Reload the TMR1 value
            Timer1_Reload();
        }
    }
    </code>
*/
bool Timer1_HasOverflowOccured(void);


/**
  @Summary
    Timer Gate Interrupt Service Routine

  @Description
    Timer Gate Interrupt Service Routine is called by the Interrupt Manager.
    User can write the code in this function.

  @Preconditions
    Initialize  the TMR1 module with gate interrupt before calling this isr.

  @Param
    None

  @Returns
    None

  @Example
    None
*/
void Timer1_GateISR(void);

#endif // TMR1_H