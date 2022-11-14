/**
  Generated Interrupt Manager Header File

  @Company:
    Microchip Technology Inc.

  @File Name:
    interrupt.h

  @Summary:
    This is the Interrupt Manager file generated

  @Description:
    This header file provides implementations for global interrupt handling.
    For individual peripheral handlers please see the peripheral driver for
    all modules selected in the GUI.
    Generation Information :
        Driver Version    :  2.12
    The generated drivers are tested against the following:
        Compiler          :  XC8 v2.20 or later
        MPLAB 	          :  MPLABX v5.45
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

#ifndef INTERRUPT_H
#define INTERRUPT_H

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will enable high priority global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptHighEnable();
 */
#define INTERRUPT_GlobalInterruptHighEnable() (INTCON0bits.GIE = 1)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will disable high priority global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptHighDisable();
 */
#define INTERRUPT_GlobalInterruptHighDisable() (INTCON0bits.GIE = 0)

/**
 * @Param
    none
 * @Returns
    0 - Global Interrupt Disabled
    1 - Global Interrupt Enabled
 * @Description
    This macro will return the global interrupt enable high bit status.
 * @Example
    INTERRUPT_GlobalInterruptHighStatus();
 */
#define INTERRUPT_GlobalInterruptHighStatus() (INTCON0bits.GIE)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will enable low priority global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptLowEnable();
 */
#define INTERRUPT_GlobalInterruptLowEnable() (INTCON0bits.GIEL = 1)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    This macro will disable low priority global interrupts.
 * @Example
    INTERRUPT_GlobalInterruptLowDisable();
 */
#define INTERRUPT_GlobalInterruptLowDisable() (INTCON0bits.GIEL = 0)

/**
 * @Param
    none
 * @Returns
    0 - Global Interrupt Disabled
    1 - Global Interrupt Enabled
 * @Description
    This macro will return the global interrupt enable low bit status.
 * @Example
    INTERRUPT_GlobalInterruptLowStatus();
 */
#define INTERRUPT_GlobalInterruptLowStatus() (INTCON0bits.GIEL)

/**
 * @Param
    none
 * @Returns
    none
 * @Description
    Initializes PIC18 peripheral interrupt priorities; enables/disables priority vectors; Initializes External Interrupt
 * @Example
    INTERRUPT_Initialize();
 */
void INTERRUPT_Initialize (void);

/**
  @Summary
    Clears the interrupt flag for INT0

  @Description
    This routine clears the interrupt flag for the external interrupt, INT0.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void INT0_ISR(void)
    {
        // User Area Begin->code

        // User Area End->code
        EXT_INT0_InterruptFlagClear();
    }
    </code>

*/
#define EXT_INT0_InterruptFlagClear()       (PIR1bits.INT0IF = 0)

/**
  @Summary
    Clears the interrupt enable for INT0

  @Description
    This routine clears the interrupt enable for the external interrupt, INT0.
    After calling this routine, external interrupts on this pin will not be serviced by the 
    interrupt handler, INT0.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Changing the external interrupt edge detect from negative to positive
    <code>
    // clear the interrupt enable
    EXT_INT0_InterruptDisable();
    // change the edge
    EXT_INT0_risingEdgeSet();
    // clear the interrupt flag and re-enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
#define EXT_INT0_InterruptDisable()     (PIE1bits.INT0IE = 0)

/**
  @Summary
    Sets the interrupt enable for INT0

  @Description
    This routine sets the interrupt enable for the external interrupt, INT0.
    After calling this routine, external interrupts on this pin will be serviced by the 
    interrupt handler, INT0.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT0_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
#define EXT_INT0_InterruptEnable()       (PIE1bits.INT0IE = 1)

/**
  @Summary
    Sets the edge detect of the external interrupt to negative edge.

  @Description
    This routine set the edge detect of the extern interrupt to negative edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a high to low level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle negative edge interrupts
    <code>
    // set the edge
    EXT_INT0_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
#define EXT_INT0_risingEdgeSet()          (INTCON0bits.INT0EDG = 1)

/**
  @Summary
    Sets the edge detect of the external interrupt to positive edge.

  @Description
    This routine set the edge detect of the extern interrupt to positive edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a low to high level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT0_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT0_InterruptFlagClear();
    EXT_INT0_InterruptEnable();
    </code>

*/
#define EXT_INT0_fallingEdgeSet()          (INTCON0bits.INT0EDG = 0)
/**
  @Summary
    Clears the interrupt flag for INT1

  @Description
    This routine clears the interrupt flag for the external interrupt, INT1.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void INT1_ISR(void)
    {
        // User Area Begin->code

        // User Area End->code
        EXT_INT1_InterruptFlagClear();
    }
    </code>

*/
#define EXT_INT1_InterruptFlagClear()       (PIR6bits.INT1IF = 0)

/**
  @Summary
    Clears the interrupt enable for INT1

  @Description
    This routine clears the interrupt enable for the external interrupt, INT1.
    After calling this routine, external interrupts on this pin will not be serviced by the 
    interrupt handler, INT1.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Changing the external interrupt edge detect from negative to positive
    <code>
    // clear the interrupt enable
    EXT_INT1_InterruptDisable();
    // change the edge
    EXT_INT1_risingEdgeSet();
    // clear the interrupt flag and re-enable the interrupt
    EXT_INT1_InterruptFlagClear();
    EXT_INT1_InterruptEnable();
    </code>

*/
#define EXT_INT1_InterruptDisable()     (PIE6bits.INT1IE = 0)

/**
  @Summary
    Sets the interrupt enable for INT1

  @Description
    This routine sets the interrupt enable for the external interrupt, INT1.
    After calling this routine, external interrupts on this pin will be serviced by the 
    interrupt handler, INT1.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT1_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT1_InterruptFlagClear();
    EXT_INT1_InterruptEnable();
    </code>

*/
#define EXT_INT1_InterruptEnable()       (PIE6bits.INT1IE = 1)

/**
  @Summary
    Sets the edge detect of the external interrupt to negative edge.

  @Description
    This routine set the edge detect of the extern interrupt to negative edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a high to low level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle negative edge interrupts
    <code>
    // set the edge
    EXT_INT1_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT1_InterruptFlagClear();
    EXT_INT1_InterruptEnable();
    </code>

*/
#define EXT_INT1_risingEdgeSet()          (INTCON0bits.INT1EDG = 1)

/**
  @Summary
    Sets the edge detect of the external interrupt to positive edge.

  @Description
    This routine set the edge detect of the extern interrupt to positive edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a low to high level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT1_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT1_InterruptFlagClear();
    EXT_INT1_InterruptEnable();
    </code>

*/
#define EXT_INT1_fallingEdgeSet()          (INTCON0bits.INT1EDG = 0)
/**
  @Summary
    Clears the interrupt flag for INT2

  @Description
    This routine clears the interrupt flag for the external interrupt, INT2.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    <code>
    void INT2_ISR(void)
    {
        // User Area Begin->code

        // User Area End->code
        EXT_INT2_InterruptFlagClear();
    }
    </code>

*/
#define EXT_INT2_InterruptFlagClear()       (PIR10bits.INT2IF = 0)

/**
  @Summary
    Clears the interrupt enable for INT2

  @Description
    This routine clears the interrupt enable for the external interrupt, INT2.
    After calling this routine, external interrupts on this pin will not be serviced by the 
    interrupt handler, INT2.

  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Changing the external interrupt edge detect from negative to positive
    <code>
    // clear the interrupt enable
    EXT_INT2_InterruptDisable();
    // change the edge
    EXT_INT2_risingEdgeSet();
    // clear the interrupt flag and re-enable the interrupt
    EXT_INT2_InterruptFlagClear();
    EXT_INT2_InterruptEnable();
    </code>

*/
#define EXT_INT2_InterruptDisable()     (PIE10bits.INT2IE = 0)

/**
  @Summary
    Sets the interrupt enable for INT2

  @Description
    This routine sets the interrupt enable for the external interrupt, INT2.
    After calling this routine, external interrupts on this pin will be serviced by the 
    interrupt handler, INT2.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT2_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT2_InterruptFlagClear();
    EXT_INT2_InterruptEnable();
    </code>

*/
#define EXT_INT2_InterruptEnable()       (PIE10bits.INT2IE = 1)

/**
  @Summary
    Sets the edge detect of the external interrupt to negative edge.

  @Description
    This routine set the edge detect of the extern interrupt to negative edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a high to low level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle negative edge interrupts
    <code>
    // set the edge
    EXT_INT2_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT2_InterruptFlagClear();
    EXT_INT2_InterruptEnable();
    </code>

*/
#define EXT_INT2_risingEdgeSet()          (INTCON0bits.INT2EDG = 1)

/**
  @Summary
    Sets the edge detect of the external interrupt to positive edge.

  @Description
    This routine set the edge detect of the extern interrupt to positive edge.  
    After this routine is called the interrupt flag will be set when the external 
    interrupt pins level transitions from a low to high level.
 
  @Preconditions
    None.

  @Returns
    None.

  @Param
    None.

  @Example
    Setting the external interrupt to handle positive edge interrupts
    <code>
    // set the edge
    EXT_INT2_risingEdgeSet();
    // clear the interrupt flag and enable the interrupt
    EXT_INT2_InterruptFlagClear();
    EXT_INT2_InterruptEnable();
    </code>

*/
#define EXT_INT2_fallingEdgeSet()          (INTCON0bits.INT2EDG = 0)

/**
   Section: External Interrupt Handlers
 */

/**
  @Summary
    Callback function for EXT_INT0 - INT0

  @Description
    Allows for a specific callback function to be called in the INT0 ISR.
    It also allows for a non-specific interrupt handler to be called at runtime.
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    void INT0_CallBack();

*/
void INT0_CallBack(void);

/**
  @Summary
    Interrupt Handler Setter for EXT_INT0 - INT0 pin

  @Description
    Allows selecting an interrupt handler for EXT_INT0 - INT0 at application runtime
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    INTERRUPT_Initializer();
    INT0_SetInterruptHandler(MyInterruptHandler);

*/
void INT0_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for EXT_INT0 - INT0 pin

  @Description
    This is the dynamic interrupt handler to be used together with the INT0_SetInterruptHandler() method.
    This handler is called every time the INT0 ISR is executed and allows any function to be registered at runtime. 
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    INT0_SetInterruptHandler(INT0_InterruptHandler);

*/
extern void (*INT0_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for EXT_INT0 - INT0 pin

  @Description
    This is a predefined interrupt handler to be used together with the INT0_SetInterruptHandler() method.
    This handler is called every time the INT0 ISR is executed. 
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    INT0_SetInterruptHandler(INT0_DefaultInterruptHandler);

*/
void INT0_DefaultInterruptHandler(void);

/**
  @Summary
    Callback function for EXT_INT1 - INT1

  @Description
    Allows for a specific callback function to be called in the INT1 ISR.
    It also allows for a non-specific interrupt handler to be called at runtime.
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    void INT1_CallBack();

*/
void INT1_CallBack(void);

/**
  @Summary
    Interrupt Handler Setter for EXT_INT1 - INT1 pin

  @Description
    Allows selecting an interrupt handler for EXT_INT1 - INT1 at application runtime
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    INTERRUPT_Initializer();
    INT1_SetInterruptHandler(MyInterruptHandler);

*/
void INT1_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for EXT_INT1 - INT1 pin

  @Description
    This is the dynamic interrupt handler to be used together with the INT1_SetInterruptHandler() method.
    This handler is called every time the INT1 ISR is executed and allows any function to be registered at runtime. 
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    INT1_SetInterruptHandler(INT1_InterruptHandler);

*/
extern void (*INT1_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for EXT_INT1 - INT1 pin

  @Description
    This is a predefined interrupt handler to be used together with the INT1_SetInterruptHandler() method.
    This handler is called every time the INT1 ISR is executed. 
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    INT1_SetInterruptHandler(INT1_DefaultInterruptHandler);

*/
void INT1_DefaultInterruptHandler(void);

/**
  @Summary
    Callback function for EXT_INT2 - INT2

  @Description
    Allows for a specific callback function to be called in the INT2 ISR.
    It also allows for a non-specific interrupt handler to be called at runtime.
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    void INT2_CallBack();

*/
void INT2_CallBack(void);

/**
  @Summary
    Interrupt Handler Setter for EXT_INT2 - INT2 pin

  @Description
    Allows selecting an interrupt handler for EXT_INT2 - INT2 at application runtime
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    InterruptHandler function pointer.

  @Example
    INTERRUPT_Initializer();
    INT2_SetInterruptHandler(MyInterruptHandler);

*/
void INT2_SetInterruptHandler(void (* InterruptHandler)(void));

/**
  @Summary
    Dynamic Interrupt Handler for EXT_INT2 - INT2 pin

  @Description
    This is the dynamic interrupt handler to be used together with the INT2_SetInterruptHandler() method.
    This handler is called every time the INT2 ISR is executed and allows any function to be registered at runtime. 
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    INT2_SetInterruptHandler(INT2_InterruptHandler);

*/
extern void (*INT2_InterruptHandler)(void);

/**
  @Summary
    Default Interrupt Handler for EXT_INT2 - INT2 pin

  @Description
    This is a predefined interrupt handler to be used together with the INT2_SetInterruptHandler() method.
    This handler is called every time the INT2 ISR is executed. 
    
  @Preconditions
    Interrupt Manager intializer called

  @Returns
    None.

  @Param
    None.

  @Example
    INTERRUPT_Initializer();
    INT2_SetInterruptHandler(INT2_DefaultInterruptHandler);

*/
void INT2_DefaultInterruptHandler(void);

#endif  // INTERRUPT_H
/**
 End of File
*/
