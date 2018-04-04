/*******************************************************************************
* File Name: motorMode.h  
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

#if !defined(CY_PINS_motorMode_H) /* Pins motorMode_H */
#define CY_PINS_motorMode_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "motorMode_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 motorMode__PORT == 15 && ((motorMode__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    motorMode_Write(uint8 value);
void    motorMode_SetDriveMode(uint8 mode);
uint8   motorMode_ReadDataReg(void);
uint8   motorMode_Read(void);
void    motorMode_SetInterruptMode(uint16 position, uint16 mode);
uint8   motorMode_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the motorMode_SetDriveMode() function.
     *  @{
     */
        #define motorMode_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define motorMode_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define motorMode_DM_RES_UP          PIN_DM_RES_UP
        #define motorMode_DM_RES_DWN         PIN_DM_RES_DWN
        #define motorMode_DM_OD_LO           PIN_DM_OD_LO
        #define motorMode_DM_OD_HI           PIN_DM_OD_HI
        #define motorMode_DM_STRONG          PIN_DM_STRONG
        #define motorMode_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define motorMode_MASK               motorMode__MASK
#define motorMode_SHIFT              motorMode__SHIFT
#define motorMode_WIDTH              1u

/* Interrupt constants */
#if defined(motorMode__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in motorMode_SetInterruptMode() function.
     *  @{
     */
        #define motorMode_INTR_NONE      (uint16)(0x0000u)
        #define motorMode_INTR_RISING    (uint16)(0x0001u)
        #define motorMode_INTR_FALLING   (uint16)(0x0002u)
        #define motorMode_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define motorMode_INTR_MASK      (0x01u) 
#endif /* (motorMode__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define motorMode_PS                     (* (reg8 *) motorMode__PS)
/* Data Register */
#define motorMode_DR                     (* (reg8 *) motorMode__DR)
/* Port Number */
#define motorMode_PRT_NUM                (* (reg8 *) motorMode__PRT) 
/* Connect to Analog Globals */                                                  
#define motorMode_AG                     (* (reg8 *) motorMode__AG)                       
/* Analog MUX bux enable */
#define motorMode_AMUX                   (* (reg8 *) motorMode__AMUX) 
/* Bidirectional Enable */                                                        
#define motorMode_BIE                    (* (reg8 *) motorMode__BIE)
/* Bit-mask for Aliased Register Access */
#define motorMode_BIT_MASK               (* (reg8 *) motorMode__BIT_MASK)
/* Bypass Enable */
#define motorMode_BYP                    (* (reg8 *) motorMode__BYP)
/* Port wide control signals */                                                   
#define motorMode_CTL                    (* (reg8 *) motorMode__CTL)
/* Drive Modes */
#define motorMode_DM0                    (* (reg8 *) motorMode__DM0) 
#define motorMode_DM1                    (* (reg8 *) motorMode__DM1)
#define motorMode_DM2                    (* (reg8 *) motorMode__DM2) 
/* Input Buffer Disable Override */
#define motorMode_INP_DIS                (* (reg8 *) motorMode__INP_DIS)
/* LCD Common or Segment Drive */
#define motorMode_LCD_COM_SEG            (* (reg8 *) motorMode__LCD_COM_SEG)
/* Enable Segment LCD */
#define motorMode_LCD_EN                 (* (reg8 *) motorMode__LCD_EN)
/* Slew Rate Control */
#define motorMode_SLW                    (* (reg8 *) motorMode__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define motorMode_PRTDSI__CAPS_SEL       (* (reg8 *) motorMode__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define motorMode_PRTDSI__DBL_SYNC_IN    (* (reg8 *) motorMode__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define motorMode_PRTDSI__OE_SEL0        (* (reg8 *) motorMode__PRTDSI__OE_SEL0) 
#define motorMode_PRTDSI__OE_SEL1        (* (reg8 *) motorMode__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define motorMode_PRTDSI__OUT_SEL0       (* (reg8 *) motorMode__PRTDSI__OUT_SEL0) 
#define motorMode_PRTDSI__OUT_SEL1       (* (reg8 *) motorMode__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define motorMode_PRTDSI__SYNC_OUT       (* (reg8 *) motorMode__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(motorMode__SIO_CFG)
    #define motorMode_SIO_HYST_EN        (* (reg8 *) motorMode__SIO_HYST_EN)
    #define motorMode_SIO_REG_HIFREQ     (* (reg8 *) motorMode__SIO_REG_HIFREQ)
    #define motorMode_SIO_CFG            (* (reg8 *) motorMode__SIO_CFG)
    #define motorMode_SIO_DIFF           (* (reg8 *) motorMode__SIO_DIFF)
#endif /* (motorMode__SIO_CFG) */

/* Interrupt Registers */
#if defined(motorMode__INTSTAT)
    #define motorMode_INTSTAT            (* (reg8 *) motorMode__INTSTAT)
    #define motorMode_SNAP               (* (reg8 *) motorMode__SNAP)
    
	#define motorMode_0_INTTYPE_REG 		(* (reg8 *) motorMode__0__INTTYPE)
#endif /* (motorMode__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_motorMode_H */


/* [] END OF FILE */
