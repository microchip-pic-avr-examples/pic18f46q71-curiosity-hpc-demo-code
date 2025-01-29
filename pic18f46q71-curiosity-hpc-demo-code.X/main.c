 /*
 * MAIN Generated Driver File
 * 
 * @file main.c
 * 
 * @defgroup main MAIN
 * 
 * @brief This is the generated driver implementation file for the MAIN driver.
 *
 * @version MAIN Driver Version 1.0.2
 *
 * @version Package Version: 3.1.2
*/

#include "mcc_generated_files/system/system.h"
#include "labs.h"

void checkButtonS1(void);
void nextLab(void);

void main(void) {
    SYSTEM_Initialize();       
    INTERRUPT_TMR0InterruptDisable();                                           // Disable the pre-enabled interrupts of the MCC

    // If using interrupts in PIC18 High/Low Priority Mode you need to enable the Global High and Low Interrupts
    // If using interrupts in PIC Mid-Range Compatibility Mode you need to enable the Global Interrupts
    // Use the following macros to:

    // Enable the Global Interrupts
    //INTERRUPT_GlobalInterruptEnable();

    // Disable the Global Interrupts
    //INTERRUPT_GlobalInterruptDisable();

    // Enable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptEnable();

    // Disable the Peripheral Interrupts
    //INTERRUPT_PeripheralInterruptDisable();    
   
    while (1) {
        checkButtonS1();
        switch (labNumber) {
            case 1: HelloWorld();
                break;
            case 2: Blink();
                break;
            case 3: Rotate();
                break;
            case 4: ADC();
                break;
            case 5: VSR();
                break;
            case 6: PWM();
                break;
            case 7: Timer1();
                break;
            case 8: Interrupt();
                break;
            case 9: SleepWakeUp();
                break;
            case 10: EEPROM();
                break;
        }

        if (switchEvent) {
            nextLab();
        }
    }
}

void checkButtonS1(void) {
    if( CLC1IF ) {
        switchEvent = 1;
        CLC1IF = 0;        
    }
}

void nextLab(void) {
    switchEvent = 0;
    labNumber++;

    if (labNumber > 10) {
        labNumber = 1;
    }
}
/**
 End of File
 */