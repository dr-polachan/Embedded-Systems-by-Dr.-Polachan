/*******************************************************************************
* File Name: led.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_led_H) /* Pins led_H */
#define CY_PINS_led_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "led_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 led__PORT == 15 && ((led__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    led_Write(uint8 value);
void    led_SetDriveMode(uint8 mode);
uint8   led_ReadDataReg(void);
uint8   led_Read(void);
void    led_SetInterruptMode(uint16 position, uint16 mode);
uint8   led_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the led_SetDriveMode() function.
     *  @{
     */
        #define led_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define led_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define led_DM_RES_UP          PIN_DM_RES_UP
        #define led_DM_RES_DWN         PIN_DM_RES_DWN
        #define led_DM_OD_LO           PIN_DM_OD_LO
        #define led_DM_OD_HI           PIN_DM_OD_HI
        #define led_DM_STRONG          PIN_DM_STRONG
        #define led_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define led_MASK               led__MASK
#define led_SHIFT              led__SHIFT
#define led_WIDTH              1u

/* Interrupt constants */
#if defined(led__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in led_SetInterruptMode() function.
     *  @{
     */
        #define led_INTR_NONE      (uint16)(0x0000u)
        #define led_INTR_RISING    (uint16)(0x0001u)
        #define led_INTR_FALLING   (uint16)(0x0002u)
        #define led_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define led_INTR_MASK      (0x01u) 
#endif /* (led__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define led_PS                     (* (reg8 *) led__PS)
/* Data Register */
#define led_DR                     (* (reg8 *) led__DR)
/* Port Number */
#define led_PRT_NUM                (* (reg8 *) led__PRT) 
/* Connect to Analog Globals */                                                  
#define led_AG                     (* (reg8 *) led__AG)                       
/* Analog MUX bux enable */
#define led_AMUX                   (* (reg8 *) led__AMUX) 
/* Bidirectional Enable */                                                        
#define led_BIE                    (* (reg8 *) led__BIE)
/* Bit-mask for Aliased Register Access */
#define led_BIT_MASK               (* (reg8 *) led__BIT_MASK)
/* Bypass Enable */
#define led_BYP                    (* (reg8 *) led__BYP)
/* Port wide control signals */                                                   
#define led_CTL                    (* (reg8 *) led__CTL)
/* Drive Modes */
#define led_DM0                    (* (reg8 *) led__DM0) 
#define led_DM1                    (* (reg8 *) led__DM1)
#define led_DM2                    (* (reg8 *) led__DM2) 
/* Input Buffer Disable Override */
#define led_INP_DIS                (* (reg8 *) led__INP_DIS)
/* LCD Common or Segment Drive */
#define led_LCD_COM_SEG            (* (reg8 *) led__LCD_COM_SEG)
/* Enable Segment LCD */
#define led_LCD_EN                 (* (reg8 *) led__LCD_EN)
/* Slew Rate Control */
#define led_SLW                    (* (reg8 *) led__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define led_PRTDSI__CAPS_SEL       (* (reg8 *) led__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define led_PRTDSI__DBL_SYNC_IN    (* (reg8 *) led__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define led_PRTDSI__OE_SEL0        (* (reg8 *) led__PRTDSI__OE_SEL0) 
#define led_PRTDSI__OE_SEL1        (* (reg8 *) led__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define led_PRTDSI__OUT_SEL0       (* (reg8 *) led__PRTDSI__OUT_SEL0) 
#define led_PRTDSI__OUT_SEL1       (* (reg8 *) led__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define led_PRTDSI__SYNC_OUT       (* (reg8 *) led__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(led__SIO_CFG)
    #define led_SIO_HYST_EN        (* (reg8 *) led__SIO_HYST_EN)
    #define led_SIO_REG_HIFREQ     (* (reg8 *) led__SIO_REG_HIFREQ)
    #define led_SIO_CFG            (* (reg8 *) led__SIO_CFG)
    #define led_SIO_DIFF           (* (reg8 *) led__SIO_DIFF)
#endif /* (led__SIO_CFG) */

/* Interrupt Registers */
#if defined(led__INTSTAT)
    #define led_INTSTAT            (* (reg8 *) led__INTSTAT)
    #define led_SNAP               (* (reg8 *) led__SNAP)
    
	#define led_0_INTTYPE_REG 		(* (reg8 *) led__0__INTTYPE)
#endif /* (led__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_led_H */


/* [] END OF FILE */
