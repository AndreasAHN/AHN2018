/*******************************************************************************
* File Name: MOR.h  
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

#if !defined(CY_PINS_MOR_H) /* Pins MOR_H */
#define CY_PINS_MOR_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "MOR_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 MOR__PORT == 15 && ((MOR__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    MOR_Write(uint8 value);
void    MOR_SetDriveMode(uint8 mode);
uint8   MOR_ReadDataReg(void);
uint8   MOR_Read(void);
void    MOR_SetInterruptMode(uint16 position, uint16 mode);
uint8   MOR_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the MOR_SetDriveMode() function.
     *  @{
     */
        #define MOR_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define MOR_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define MOR_DM_RES_UP          PIN_DM_RES_UP
        #define MOR_DM_RES_DWN         PIN_DM_RES_DWN
        #define MOR_DM_OD_LO           PIN_DM_OD_LO
        #define MOR_DM_OD_HI           PIN_DM_OD_HI
        #define MOR_DM_STRONG          PIN_DM_STRONG
        #define MOR_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define MOR_MASK               MOR__MASK
#define MOR_SHIFT              MOR__SHIFT
#define MOR_WIDTH              1u

/* Interrupt constants */
#if defined(MOR__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in MOR_SetInterruptMode() function.
     *  @{
     */
        #define MOR_INTR_NONE      (uint16)(0x0000u)
        #define MOR_INTR_RISING    (uint16)(0x0001u)
        #define MOR_INTR_FALLING   (uint16)(0x0002u)
        #define MOR_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define MOR_INTR_MASK      (0x01u) 
#endif /* (MOR__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define MOR_PS                     (* (reg8 *) MOR__PS)
/* Data Register */
#define MOR_DR                     (* (reg8 *) MOR__DR)
/* Port Number */
#define MOR_PRT_NUM                (* (reg8 *) MOR__PRT) 
/* Connect to Analog Globals */                                                  
#define MOR_AG                     (* (reg8 *) MOR__AG)                       
/* Analog MUX bux enable */
#define MOR_AMUX                   (* (reg8 *) MOR__AMUX) 
/* Bidirectional Enable */                                                        
#define MOR_BIE                    (* (reg8 *) MOR__BIE)
/* Bit-mask for Aliased Register Access */
#define MOR_BIT_MASK               (* (reg8 *) MOR__BIT_MASK)
/* Bypass Enable */
#define MOR_BYP                    (* (reg8 *) MOR__BYP)
/* Port wide control signals */                                                   
#define MOR_CTL                    (* (reg8 *) MOR__CTL)
/* Drive Modes */
#define MOR_DM0                    (* (reg8 *) MOR__DM0) 
#define MOR_DM1                    (* (reg8 *) MOR__DM1)
#define MOR_DM2                    (* (reg8 *) MOR__DM2) 
/* Input Buffer Disable Override */
#define MOR_INP_DIS                (* (reg8 *) MOR__INP_DIS)
/* LCD Common or Segment Drive */
#define MOR_LCD_COM_SEG            (* (reg8 *) MOR__LCD_COM_SEG)
/* Enable Segment LCD */
#define MOR_LCD_EN                 (* (reg8 *) MOR__LCD_EN)
/* Slew Rate Control */
#define MOR_SLW                    (* (reg8 *) MOR__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define MOR_PRTDSI__CAPS_SEL       (* (reg8 *) MOR__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define MOR_PRTDSI__DBL_SYNC_IN    (* (reg8 *) MOR__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define MOR_PRTDSI__OE_SEL0        (* (reg8 *) MOR__PRTDSI__OE_SEL0) 
#define MOR_PRTDSI__OE_SEL1        (* (reg8 *) MOR__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define MOR_PRTDSI__OUT_SEL0       (* (reg8 *) MOR__PRTDSI__OUT_SEL0) 
#define MOR_PRTDSI__OUT_SEL1       (* (reg8 *) MOR__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define MOR_PRTDSI__SYNC_OUT       (* (reg8 *) MOR__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(MOR__SIO_CFG)
    #define MOR_SIO_HYST_EN        (* (reg8 *) MOR__SIO_HYST_EN)
    #define MOR_SIO_REG_HIFREQ     (* (reg8 *) MOR__SIO_REG_HIFREQ)
    #define MOR_SIO_CFG            (* (reg8 *) MOR__SIO_CFG)
    #define MOR_SIO_DIFF           (* (reg8 *) MOR__SIO_DIFF)
#endif /* (MOR__SIO_CFG) */

/* Interrupt Registers */
#if defined(MOR__INTSTAT)
    #define MOR_INTSTAT            (* (reg8 *) MOR__INTSTAT)
    #define MOR_SNAP               (* (reg8 *) MOR__SNAP)
    
	#define MOR_0_INTTYPE_REG 		(* (reg8 *) MOR__0__INTTYPE)
#endif /* (MOR__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_MOR_H */


/* [] END OF FILE */
