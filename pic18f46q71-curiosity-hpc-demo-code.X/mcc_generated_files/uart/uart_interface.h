/**
  uart_interface Generated Driver API Header File

  @Company
    Microchip Technology Inc.

  @File Name
    uart_interface.h

  @Summary
    This is the generated driver interface header file for the uart_interface driver.

  @Description
    This file provides common enumerations for uart_interface driver.
    Generation Information :
        Product Revision  :  CCL - 1.8.2
        Device            :  PIC18F47Q43
        Driver Version    :  1.0.0
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.2
        MPLAB             :  Standalone
*/

/*
� [2022] Microchip Technology Inc. and its subsidiaries.

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

#ifndef UART_INTERFACE_H
#define UART_INTERFACE_H
/**
  Section: Included Files
*/
#include <stdbool.h>
#include <stdint.h>
#include <xc.h>
    
/**
  uart_interface

  @Description
    Structure containing the function pointers of uart_interface driver.
 */
struct UART_INTERFACE
{   
    void (*Initialize)(void);
    uint8_t (*Read)(void);
    void (*Write)(uint8_t);
    void (*RxCompleteCallbackRegister)(void (*CallbackHandler)(void));
    void (*TxCompleteCallbackRegister)(void (*CallbackHandler)(void));
    void (*ErrorCallbackRegister)(void (*CallbackHandler)(void));
    void (*FramingErrorCallbackRegister)(void (*CallbackHandler)(void));
    void (*OverrunErrorCallbackRegister)(void (*CallbackHandler)(void));
    void (*ParityErrorCallbackRegister)(void (*CallbackHandler));
    void (*ChecksumErrorCallbackRegister)(void (*CallbackHandler));
    bool (*IsRxReady)(void);
    bool (*IsTxReady)(void);
    bool (*IsTxDone)(void);
};

#endif // end of UART_INTERFACE_H