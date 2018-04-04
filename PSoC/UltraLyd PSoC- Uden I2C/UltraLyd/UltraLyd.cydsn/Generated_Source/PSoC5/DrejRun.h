/*******************************************************************************
* File Name: DrejRun.h  
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

#if !defined(CY_PINS_DrejRun_H) /* Pins DrejRun_H */
#define CY_PINS_DrejRun_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "DrejRun_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 DrejRun__PORT == 15 && ((DrejRun__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    DrejRun_Write(uint8 value);
void    DrejRun_SetDriveMode(uint8 mode);
uint8   DrejRun_ReadDataReg(void);
uint8   DrejRun_Read(void);
void    DrejRun_SetInterruptMode(uint16 position, uint16 mode);
uint8   DrejRun_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the DrejRun_SetDriveMode() function.
     *  @{
     */
        #define DrejRun_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define DrejRun_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define DrejRun_DM_RES_UP          PIN_DM_RES_UP
        #define DrejRun_DM_RES_DWN         PIN_DM_RES_DWN
        #define DrejRun_DM_OD_LO           PIN_DM_OD_LO
        #define DrejRun_DM_OD_HI           PIN_DM_OD_HI
        #define DrejRun_DM_STRONG          PIN_DM_STRONG
        #define DrejRun_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define DrejRun_MASK               DrejRun__MASK
#define DrejRun_SHIFT              DrejRun__SHIFT
#define DrejRun_WIDTH              1u

/* Interrupt constants */
#if defined(DrejRun__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in DrejRun_SetInterruptMode() function.
     *  @{
     */
        #define DrejRun_INTR_NONE      (uint16)(0x0000u)
        #define DrejRun_INTR_RISING    (uint16)(0x0001u)
        #define DrejRun_INTR_FALLING   (uint16)(0x0002u)
        #define DrejRun_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define DrejRun_INTR_MASK      (0x01u) 
#endif /* (DrejRun__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define DrejRun_PS                     (* (reg8 *) DrejRun__PS)
/* Data Register */
#define DrejRun_DR                     (* (reg8 *) DrejRun__DR)
/* Port Number */
#define DrejRun_PRT_NUM                (* (reg8 *) DrejRun__PRT) 
/* Connect to Analog Globals */                                                  
#define DrejRun_AG                     (* (reg8 *) DrejRun__AG)                       
/* Analog MUX bux enable */
#define DrejRun_AMUX                   (* (reg8 *) DrejRun__AMUX) 
/* Bidirectional Enable */                                                        
#define DrejRun_BIE                    (* (reg8 *) DrejRun__BIE)
/* Bit-mask for Aliased Register Access */
#define DrejRun_BIT_MASK               (* (reg8 *) DrejRun__BIT_MASK)
/* Bypass Enable */
#define DrejRun_BYP                    (* (reg8 *) DrejRun__BYP)
/* Port wide control signals */                                                   
#define DrejRun_CTL                    (* (reg8 *) DrejRun__CTL)
/* Drive Modes */
#define DrejRun_DM0                    (* (reg8 *) DrejRun__DM0) 
#define DrejRun_DM1                    (* (reg8 *) DrejRun__DM1)
#define DrejRun_DM2                    (* (reg8 *) DrejRun__DM2) 
/* Input Buffer Disable Override */
#define DrejRun_INP_DIS                (* (reg8 *) DrejRun__INP_DIS)
/* LCD Common or Segment Drive */
#define DrejRun_LCD_COM_SEG            (* (reg8 *) DrejRun__LCD_COM_SEG)
/* Enable Segment LCD */
#define DrejRun_LCD_EN                 (* (reg8 *) DrejRun__LCD_EN)
/* Slew Rate Control */
#define DrejRun_SLW                    (* (reg8 *) DrejRun__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define DrejRun_PRTDSI__CAPS_SEL       (* (reg8 *) DrejRun__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define DrejRun_PRTDSI__DBL_SYNC_IN    (* (reg8 *) DrejRun__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define DrejRun_PRTDSI__OE_SEL0        (* (reg8 *) DrejRun__PRTDSI__OE_SEL0) 
#define DrejRun_PRTDSI__OE_SEL1        (* (reg8 *) DrejRun__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define DrejRun_PRTDSI__OUT_SEL0       (* (reg8 *) DrejRun__PRTDSI__OUT_SEL0) 
#define DrejRun_PRTDSI__OUT_SEL1       (* (reg8 *) DrejRun__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define DrejRun_PRTDSI__SYNC_OUT       (* (reg8 *) DrejRun__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(DrejRun__SIO_CFG)
    #define DrejRun_SIO_HYST_EN        (* (reg8 *) DrejRun__SIO_HYST_EN)
    #define DrejRun_SIO_REG_HIFREQ     (* (reg8 *) DrejRun__SIO_REG_HIFREQ)
    #define DrejRun_SIO_CFG            (* (reg8 *) DrejRun__SIO_CFG)
    #define DrejRun_SIO_DIFF           (* (reg8 *) DrejRun__SIO_DIFF)
#endif /* (DrejRun__SIO_CFG) */

/* Interrupt Registers */
#if defined(DrejRun__INTSTAT)
    #define DrejRun_INTSTAT            (* (reg8 *) DrejRun__INTSTAT)
    #define DrejRun_SNAP               (* (reg8 *) DrejRun__SNAP)
    
	#define DrejRun_0_INTTYPE_REG 		(* (reg8 *) DrejRun__0__INTTYPE)
#endif /* (DrejRun__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_DrejRun_H */


/* [] END OF FILE */
