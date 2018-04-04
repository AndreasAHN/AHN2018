/*******************************************************************************
* File Name: m.h  
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

#if !defined(CY_PINS_m_H) /* Pins m_H */
#define CY_PINS_m_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "m_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 m__PORT == 15 && ((m__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    m_Write(uint8 value);
void    m_SetDriveMode(uint8 mode);
uint8   m_ReadDataReg(void);
uint8   m_Read(void);
void    m_SetInterruptMode(uint16 position, uint16 mode);
uint8   m_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the m_SetDriveMode() function.
     *  @{
     */
        #define m_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define m_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define m_DM_RES_UP          PIN_DM_RES_UP
        #define m_DM_RES_DWN         PIN_DM_RES_DWN
        #define m_DM_OD_LO           PIN_DM_OD_LO
        #define m_DM_OD_HI           PIN_DM_OD_HI
        #define m_DM_STRONG          PIN_DM_STRONG
        #define m_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define m_MASK               m__MASK
#define m_SHIFT              m__SHIFT
#define m_WIDTH              1u

/* Interrupt constants */
#if defined(m__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in m_SetInterruptMode() function.
     *  @{
     */
        #define m_INTR_NONE      (uint16)(0x0000u)
        #define m_INTR_RISING    (uint16)(0x0001u)
        #define m_INTR_FALLING   (uint16)(0x0002u)
        #define m_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define m_INTR_MASK      (0x01u) 
#endif /* (m__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define m_PS                     (* (reg8 *) m__PS)
/* Data Register */
#define m_DR                     (* (reg8 *) m__DR)
/* Port Number */
#define m_PRT_NUM                (* (reg8 *) m__PRT) 
/* Connect to Analog Globals */                                                  
#define m_AG                     (* (reg8 *) m__AG)                       
/* Analog MUX bux enable */
#define m_AMUX                   (* (reg8 *) m__AMUX) 
/* Bidirectional Enable */                                                        
#define m_BIE                    (* (reg8 *) m__BIE)
/* Bit-mask for Aliased Register Access */
#define m_BIT_MASK               (* (reg8 *) m__BIT_MASK)
/* Bypass Enable */
#define m_BYP                    (* (reg8 *) m__BYP)
/* Port wide control signals */                                                   
#define m_CTL                    (* (reg8 *) m__CTL)
/* Drive Modes */
#define m_DM0                    (* (reg8 *) m__DM0) 
#define m_DM1                    (* (reg8 *) m__DM1)
#define m_DM2                    (* (reg8 *) m__DM2) 
/* Input Buffer Disable Override */
#define m_INP_DIS                (* (reg8 *) m__INP_DIS)
/* LCD Common or Segment Drive */
#define m_LCD_COM_SEG            (* (reg8 *) m__LCD_COM_SEG)
/* Enable Segment LCD */
#define m_LCD_EN                 (* (reg8 *) m__LCD_EN)
/* Slew Rate Control */
#define m_SLW                    (* (reg8 *) m__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define m_PRTDSI__CAPS_SEL       (* (reg8 *) m__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define m_PRTDSI__DBL_SYNC_IN    (* (reg8 *) m__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define m_PRTDSI__OE_SEL0        (* (reg8 *) m__PRTDSI__OE_SEL0) 
#define m_PRTDSI__OE_SEL1        (* (reg8 *) m__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define m_PRTDSI__OUT_SEL0       (* (reg8 *) m__PRTDSI__OUT_SEL0) 
#define m_PRTDSI__OUT_SEL1       (* (reg8 *) m__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define m_PRTDSI__SYNC_OUT       (* (reg8 *) m__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(m__SIO_CFG)
    #define m_SIO_HYST_EN        (* (reg8 *) m__SIO_HYST_EN)
    #define m_SIO_REG_HIFREQ     (* (reg8 *) m__SIO_REG_HIFREQ)
    #define m_SIO_CFG            (* (reg8 *) m__SIO_CFG)
    #define m_SIO_DIFF           (* (reg8 *) m__SIO_DIFF)
#endif /* (m__SIO_CFG) */

/* Interrupt Registers */
#if defined(m__INTSTAT)
    #define m_INTSTAT            (* (reg8 *) m__INTSTAT)
    #define m_SNAP               (* (reg8 *) m__SNAP)
    
	#define m_0_INTTYPE_REG 		(* (reg8 *) m__0__INTTYPE)
#endif /* (m__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_m_H */


/* [] END OF FILE */
