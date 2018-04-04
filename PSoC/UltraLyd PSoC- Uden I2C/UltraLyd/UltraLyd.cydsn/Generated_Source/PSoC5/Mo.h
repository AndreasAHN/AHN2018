/*******************************************************************************
* File Name: Mo.h  
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

#if !defined(CY_PINS_Mo_H) /* Pins Mo_H */
#define CY_PINS_Mo_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Mo_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Mo__PORT == 15 && ((Mo__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Mo_Write(uint8 value);
void    Mo_SetDriveMode(uint8 mode);
uint8   Mo_ReadDataReg(void);
uint8   Mo_Read(void);
void    Mo_SetInterruptMode(uint16 position, uint16 mode);
uint8   Mo_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Mo_SetDriveMode() function.
     *  @{
     */
        #define Mo_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Mo_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Mo_DM_RES_UP          PIN_DM_RES_UP
        #define Mo_DM_RES_DWN         PIN_DM_RES_DWN
        #define Mo_DM_OD_LO           PIN_DM_OD_LO
        #define Mo_DM_OD_HI           PIN_DM_OD_HI
        #define Mo_DM_STRONG          PIN_DM_STRONG
        #define Mo_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Mo_MASK               Mo__MASK
#define Mo_SHIFT              Mo__SHIFT
#define Mo_WIDTH              1u

/* Interrupt constants */
#if defined(Mo__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Mo_SetInterruptMode() function.
     *  @{
     */
        #define Mo_INTR_NONE      (uint16)(0x0000u)
        #define Mo_INTR_RISING    (uint16)(0x0001u)
        #define Mo_INTR_FALLING   (uint16)(0x0002u)
        #define Mo_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Mo_INTR_MASK      (0x01u) 
#endif /* (Mo__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Mo_PS                     (* (reg8 *) Mo__PS)
/* Data Register */
#define Mo_DR                     (* (reg8 *) Mo__DR)
/* Port Number */
#define Mo_PRT_NUM                (* (reg8 *) Mo__PRT) 
/* Connect to Analog Globals */                                                  
#define Mo_AG                     (* (reg8 *) Mo__AG)                       
/* Analog MUX bux enable */
#define Mo_AMUX                   (* (reg8 *) Mo__AMUX) 
/* Bidirectional Enable */                                                        
#define Mo_BIE                    (* (reg8 *) Mo__BIE)
/* Bit-mask for Aliased Register Access */
#define Mo_BIT_MASK               (* (reg8 *) Mo__BIT_MASK)
/* Bypass Enable */
#define Mo_BYP                    (* (reg8 *) Mo__BYP)
/* Port wide control signals */                                                   
#define Mo_CTL                    (* (reg8 *) Mo__CTL)
/* Drive Modes */
#define Mo_DM0                    (* (reg8 *) Mo__DM0) 
#define Mo_DM1                    (* (reg8 *) Mo__DM1)
#define Mo_DM2                    (* (reg8 *) Mo__DM2) 
/* Input Buffer Disable Override */
#define Mo_INP_DIS                (* (reg8 *) Mo__INP_DIS)
/* LCD Common or Segment Drive */
#define Mo_LCD_COM_SEG            (* (reg8 *) Mo__LCD_COM_SEG)
/* Enable Segment LCD */
#define Mo_LCD_EN                 (* (reg8 *) Mo__LCD_EN)
/* Slew Rate Control */
#define Mo_SLW                    (* (reg8 *) Mo__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Mo_PRTDSI__CAPS_SEL       (* (reg8 *) Mo__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Mo_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Mo__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Mo_PRTDSI__OE_SEL0        (* (reg8 *) Mo__PRTDSI__OE_SEL0) 
#define Mo_PRTDSI__OE_SEL1        (* (reg8 *) Mo__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Mo_PRTDSI__OUT_SEL0       (* (reg8 *) Mo__PRTDSI__OUT_SEL0) 
#define Mo_PRTDSI__OUT_SEL1       (* (reg8 *) Mo__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Mo_PRTDSI__SYNC_OUT       (* (reg8 *) Mo__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Mo__SIO_CFG)
    #define Mo_SIO_HYST_EN        (* (reg8 *) Mo__SIO_HYST_EN)
    #define Mo_SIO_REG_HIFREQ     (* (reg8 *) Mo__SIO_REG_HIFREQ)
    #define Mo_SIO_CFG            (* (reg8 *) Mo__SIO_CFG)
    #define Mo_SIO_DIFF           (* (reg8 *) Mo__SIO_DIFF)
#endif /* (Mo__SIO_CFG) */

/* Interrupt Registers */
#if defined(Mo__INTSTAT)
    #define Mo_INTSTAT            (* (reg8 *) Mo__INTSTAT)
    #define Mo_SNAP               (* (reg8 *) Mo__SNAP)
    
	#define Mo_0_INTTYPE_REG 		(* (reg8 *) Mo__0__INTTYPE)
#endif /* (Mo__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Mo_H */


/* [] END OF FILE */
