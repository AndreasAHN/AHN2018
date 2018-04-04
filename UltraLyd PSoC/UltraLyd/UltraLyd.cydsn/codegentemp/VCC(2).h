/*******************************************************************************
* File Name: VCC.h  
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

#if !defined(CY_PINS_VCC_H) /* Pins VCC_H */
#define CY_PINS_VCC_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "VCC_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 VCC__PORT == 15 && ((VCC__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    VCC_Write(uint8 value);
void    VCC_SetDriveMode(uint8 mode);
uint8   VCC_ReadDataReg(void);
uint8   VCC_Read(void);
void    VCC_SetInterruptMode(uint16 position, uint16 mode);
uint8   VCC_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the VCC_SetDriveMode() function.
     *  @{
     */
        #define VCC_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define VCC_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define VCC_DM_RES_UP          PIN_DM_RES_UP
        #define VCC_DM_RES_DWN         PIN_DM_RES_DWN
        #define VCC_DM_OD_LO           PIN_DM_OD_LO
        #define VCC_DM_OD_HI           PIN_DM_OD_HI
        #define VCC_DM_STRONG          PIN_DM_STRONG
        #define VCC_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define VCC_MASK               VCC__MASK
#define VCC_SHIFT              VCC__SHIFT
#define VCC_WIDTH              1u

/* Interrupt constants */
#if defined(VCC__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in VCC_SetInterruptMode() function.
     *  @{
     */
        #define VCC_INTR_NONE      (uint16)(0x0000u)
        #define VCC_INTR_RISING    (uint16)(0x0001u)
        #define VCC_INTR_FALLING   (uint16)(0x0002u)
        #define VCC_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define VCC_INTR_MASK      (0x01u) 
#endif /* (VCC__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define VCC_PS                     (* (reg8 *) VCC__PS)
/* Data Register */
#define VCC_DR                     (* (reg8 *) VCC__DR)
/* Port Number */
#define VCC_PRT_NUM                (* (reg8 *) VCC__PRT) 
/* Connect to Analog Globals */                                                  
#define VCC_AG                     (* (reg8 *) VCC__AG)                       
/* Analog MUX bux enable */
#define VCC_AMUX                   (* (reg8 *) VCC__AMUX) 
/* Bidirectional Enable */                                                        
#define VCC_BIE                    (* (reg8 *) VCC__BIE)
/* Bit-mask for Aliased Register Access */
#define VCC_BIT_MASK               (* (reg8 *) VCC__BIT_MASK)
/* Bypass Enable */
#define VCC_BYP                    (* (reg8 *) VCC__BYP)
/* Port wide control signals */                                                   
#define VCC_CTL                    (* (reg8 *) VCC__CTL)
/* Drive Modes */
#define VCC_DM0                    (* (reg8 *) VCC__DM0) 
#define VCC_DM1                    (* (reg8 *) VCC__DM1)
#define VCC_DM2                    (* (reg8 *) VCC__DM2) 
/* Input Buffer Disable Override */
#define VCC_INP_DIS                (* (reg8 *) VCC__INP_DIS)
/* LCD Common or Segment Drive */
#define VCC_LCD_COM_SEG            (* (reg8 *) VCC__LCD_COM_SEG)
/* Enable Segment LCD */
#define VCC_LCD_EN                 (* (reg8 *) VCC__LCD_EN)
/* Slew Rate Control */
#define VCC_SLW                    (* (reg8 *) VCC__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define VCC_PRTDSI__CAPS_SEL       (* (reg8 *) VCC__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define VCC_PRTDSI__DBL_SYNC_IN    (* (reg8 *) VCC__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define VCC_PRTDSI__OE_SEL0        (* (reg8 *) VCC__PRTDSI__OE_SEL0) 
#define VCC_PRTDSI__OE_SEL1        (* (reg8 *) VCC__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define VCC_PRTDSI__OUT_SEL0       (* (reg8 *) VCC__PRTDSI__OUT_SEL0) 
#define VCC_PRTDSI__OUT_SEL1       (* (reg8 *) VCC__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define VCC_PRTDSI__SYNC_OUT       (* (reg8 *) VCC__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(VCC__SIO_CFG)
    #define VCC_SIO_HYST_EN        (* (reg8 *) VCC__SIO_HYST_EN)
    #define VCC_SIO_REG_HIFREQ     (* (reg8 *) VCC__SIO_REG_HIFREQ)
    #define VCC_SIO_CFG            (* (reg8 *) VCC__SIO_CFG)
    #define VCC_SIO_DIFF           (* (reg8 *) VCC__SIO_DIFF)
#endif /* (VCC__SIO_CFG) */

/* Interrupt Registers */
#if defined(VCC__INTSTAT)
    #define VCC_INTSTAT            (* (reg8 *) VCC__INTSTAT)
    #define VCC_SNAP               (* (reg8 *) VCC__SNAP)
    
	#define VCC_0_INTTYPE_REG 		(* (reg8 *) VCC__0__INTTYPE)
#endif /* (VCC__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_VCC_H */


/* [] END OF FILE */
