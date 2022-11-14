/**
 * 
 * @file nvm.h
 *
 * @defgroup nvm_driver  Non Volatile Memory
 *
 * @brief This file contains API prototypes and other datatypes for NVM driver.
 *
 * @version NVM Driver Version 2.0.0
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

#ifndef NVM_H
#define NVM_H

#include <xc.h>

/**
 * @ingroup nvm_driver
 * @def PROGMEM_PAGE_SIZE
 * This macro contains the size of a Flash page in bytes.
 */
#define PROGMEM_PAGE_SIZE          (512U)

/**
 * @ingroup nvm_driver
 * @def PROGMEM_SIZE
 * This macro contains the size of Flash in bytes.
 */
#define PROGMEM_SIZE               (0x010000U)

/**
 * @ingroup nvm_driver
 * @def BUFFER_RAM_START_ADDRESS
 * This macro contains the starting address of buffer RAM.
 */
#define BUFFER_RAM_START_ADDRESS   (0x1500U)

/**
 * @ingroup nvm_driver
 * @def EEPROM_START_ADDRESS
 * This macro contains the starting address of EEPROM.
 */
#define EEPROM_START_ADDRESS       (0x380000U)

/**
 * @ingroup nvm_driver
 * @def EEPROM_SIZE
 * This macro contains the size of EEPROM in bytes.
 */
#define EEPROM_SIZE                (256U)

/**
 * @ingroup nvm_driver
 * @def UNLOCK_KEY
 * This macro contains the unlock key required for NVM operations.
 */
#define UNLOCK_KEY                 (0xAA55U)

/**
 * @ingroup nvm_driver
 * @brief Datatypes for NVM address and data.
 */
typedef uint8_t flash_data_t;
typedef uint24_t flash_address_t;
typedef uint8_t eeprom_data_t;
typedef uint24_t eeprom_address_t;

/**
 * @ingroup nvm_driver
 * @enum nvm_status_t
 * @brief This enumeration contains return codes for NVM driver APIs.
 */
typedef enum
{
    NVM_OK, /**<0 - NVM operation is successful*/
    NVM_ERROR /**<1 - NVM operation is failed*/
} nvm_status_t;

/**
 * @ingroup nvm_driver
 * @brief This API initializes the NVM driver. 
 * @param none
 * @return none
 */
void NVM_Initialize(void);

/**
 * @ingroup nvm_driver
 * @brief This API checks if NVM is busy with read/write/erase command.
 * @param none
 * @retval true if NVM operation is going on
 * @retval false if NVM operation is not going on
 */
bool NVM_IsBusy(void);

/**
 * @ingroup nvm_driver
 * @brief This API returns the status of last NVM operation.
 * @param none
 * @retval NVM_OK if NVM operation is successful
 * @retval NVM_ERROR if NVM operation is failed
 */
nvm_status_t NVM_StatusGet(void);

/**
 * @ingroup nvm_driver
 * @brief This API clears the NVM error status.
 * @param none
 * @return none
 */
void NVM_StatusClear(void);

/**
 * @ingroup nvm_driver
 * @brief This API sets the unlock keys required to perform any Erase or Write operations on Flash and EEPROM.
 * @param [in] unlockKey - unlock key value as specified in device datasheet 
 * @return none
 */
void NVM_UnlockKeySet(uint16_t unlockKey);

/**
 * @ingroup nvm_driver
 * @brief This API clears the previously configured unlock keys.
 * @param none 
 * @return none
 */
void NVM_UnlockKeyClear(void);

/**
 * @ingroup nvm_driver
 * @brief This API reads a byte from given address of Flash.
 * @param [in] address - Address of Flash location from which data to be read
 * @return Byte read from given Flash address
 */
flash_data_t FLASH_Read(flash_address_t address);

/**
 * @ingroup nvm_driver
 * @brief This API reads one entire Flash row (page) from given starting address (address of first byte location) of the row.
 *      The size of the buffer must be one Flash row and the address must be aligned on the row boundary.
 *      @ref FLASH_ErasePageAddressGet() must be used to obtain the starting address of row.
 *      This is non portable API thus may not be supported by all 8-bit PIC & AVR devices. 
 * @param [in] address -  Starting address of Flash row to be read 
 * @param [out] *dataBuffer - Buffer to hold the data read from given Flash row
 *                           If data is to be read in buffer RAM, then array of address BUFFER_RAM_START_ADDRESS must be used
 * @return Status of Flash row read operation as described in @ref nvm_status_t
 */
nvm_status_t FLASH_RowRead(flash_address_t address, flash_data_t *dataBuffer);

/**
 * @ingroup nvm_driver
 * @brief This API writes a word at given Flash address.
 *        This is non portable API thus may not be supported by all 8-bit PIC & AVR devices.
 * @pre Flash location should erased before writing.
 *      Unlock key should be set using @ref NVM_UnlockKeySet() API if key was cleared before. 
 *      AoU: "Address Qualifiers" must be configured to "Require" under
 *           "Project Properties -> XC8 Compiler -> Optimizations".
 * @param [in] address - Address of Flash location at which data to be written
 * @param [in] data - Word to be written
 * @return Status of Flash write operation as described in @ref nvm_status_t
 */
nvm_status_t FLASH_Write(flash_address_t address, uint16_t data);

/**
 * @ingroup nvm_driver
 * @brief This API writes one Flash row (page) from given starting address (address of first byte location) of the row. 
 *        The size of the input buffer must be one Flash row and the address must be aligned on the row boundary.
 *        @ref FLASH_ErasePageAddressGet() must be used to obtain the starting address of row.
 * @pre Flash row must be erased before calling this function.
 *      Unlock key should be set using @ref NVM_UnlockKeySet() API if key was cleared before.
 *      AoU: "Address Qualifiers" must be configured to "Require" under
 *           "Project Properties -> XC8 Compiler -> Optimizations".
 * @param [in] address - Starting address of Flash row to be written
 * @param [in] *dataBuffer - Pointer to a buffer which holds the data to be written
 *                          If data is already available in buffer RAM, then array of address BUFFER_RAM_START_ADDRESS must be used  
 * @return Status of Flash row write operation as described in @ref nvm_status_t
 */
nvm_status_t FLASH_RowWrite(flash_address_t address, flash_data_t *dataBuffer);

/**
 * @ingroup nvm_driver
 * @brief This API erases one Flash page containing given address.
 * @pre Unlock key should be set using @ref NVM_UnlockKeySet() API if key was cleared before.
 *      AoU: "Address Qualifiers" must be configured to "Require" under
 *           "Project Properties -> XC8 Compiler -> Optimizations".
 * @param [in] address - Any address in the Flash page to be erased 
 * @return Status of Flash page erase operation as described in @ref nvm_status_t
 */
nvm_status_t FLASH_PageErase(flash_address_t address);

/**
 * @ingroup nvm_driver
 * @brief This API returns the starting address (address of first byte location) of the page containing given Flash address.
 * @param [in] address - Flash address for which page starting address to be obtained
 * @return Starting address of the page which contains given Flash address
 */
flash_address_t FLASH_ErasePageAddressGet(flash_address_t address);

/**
 * @ingroup nvm_driver
 * @brief This API returns the offset from starting address (address of first byte location) of the page.
 * @param [in] address - Flash address for which offset from starting address of the page to be obtained
 * @return Offset of given address from starting address of the page.
 */
uint16_t FLASH_ErasePageOffsetGet(flash_address_t address);

/**
 * @ingroup nvm_driver
 * @brief This API reads one byte from given EEPROM address.
 * @param [in] address - Address of EEPROM location to be read
 * @return Byte read from given EEPROM address
 */
eeprom_data_t EEPROM_Read(eeprom_address_t address);

/**
 * @ingroup nvm_driver
 * @brief This API writes one byte to given EEPROM address.
 *      Application must check NVM busy status using @ref NVM_IsBusy() API to know if EEPROM write operation is completed.  
 *      @ref NVM_ErrorStatusGet() API can be used to know the EEPROM Write operation result.
 * @pre Unlock key should be set using @ref NVM_UnlockKeySet() API if key was cleared before. 
 *      AoU: "Address Qualifiers" must be configured to "Require" under
 *           "Project Properties -> XC8 Compiler -> Optimizations".
 * @param [in] address - Address of EEPROM location to be written
 * @param [in] data - Byte to be written to given EEPROM location
 * @return none
 */
void EEPROM_Write(eeprom_address_t address, eeprom_data_t data);

#endif //NVM_H