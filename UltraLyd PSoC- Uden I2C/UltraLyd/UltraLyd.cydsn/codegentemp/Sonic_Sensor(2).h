/*******************************************************************************
* File Name: Sonic_Sensor.h  
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

#if !defined(CY_PINS_Sonic_Sensor_H) /* Pins Sonic_Sensor_H */
#define CY_PINS_Sonic_Sensor_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "Sonic_Sensor_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 Sonic_Sensor__PORT == 15 && ((Sonic_Sensor__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    Sonic_Sensor_Write(uint8 value);
void    Sonic_Sensor_SetDriveMode(uint8 mode);
uint8   Sonic_Sensor_ReadDataReg(void);
uint8   Sonic_Sensor_Read(void);
void    Sonic_Sensor_SetInterruptMode(uint16 position, uint16 mode);
uint8   Sonic_Sensor_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the Sonic_Sensor_SetDriveMode() function.
     *  @{
     */
        #define Sonic_Sensor_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define Sonic_Sensor_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define Sonic_Sensor_DM_RES_UP          PIN_DM_RES_UP
        #define Sonic_Sensor_DM_RES_DWN         PIN_DM_RES_DWN
        #define Sonic_Sensor_DM_OD_LO           PIN_DM_OD_LO
        #define Sonic_Sensor_DM_OD_HI           PIN_DM_OD_HI
        #define Sonic_Sensor_DM_STRONG          PIN_DM_STRONG
        #define Sonic_Sensor_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define Sonic_Sensor_MASK               Sonic_Sensor__MASK
#define Sonic_Sensor_SHIFT              Sonic_Sensor__SHIFT
#define Sonic_Sensor_WIDTH              1u

/* Interrupt constants */
#if defined(Sonic_Sensor__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in Sonic_Sensor_SetInterruptMode() function.
     *  @{
     */
        #define Sonic_Sensor_INTR_NONE      (uint16)(0x0000u)
        #define Sonic_Sensor_INTR_RISING    (uint16)(0x0001u)
        #define Sonic_Sensor_INTR_FALLING   (uint16)(0x0002u)
        #define Sonic_Sensor_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define Sonic_Sensor_INTR_MASK      (0x01u) 
#endif /* (Sonic_Sensor__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define Sonic_Sensor_PS                     (* (reg8 *) Sonic_Sensor__PS)
/* Data Register */
#define Sonic_Sensor_DR                     (* (reg8 *) Sonic_Sensor__DR)
/* Port Number */
#define Sonic_Sensor_PRT_NUM                (* (reg8 *) Sonic_Sensor__PRT) 
/* Connect to Analog Globals */                                                  
#define Sonic_Sensor_AG                     (* (reg8 *) Sonic_Sensor__AG)                       
/* Analog MUX bux enable */
#define Sonic_Sensor_AMUX                   (* (reg8 *) Sonic_Sensor__AMUX) 
/* Bidirectional Enable */                                                        
#define Sonic_Sensor_BIE                    (* (reg8 *) Sonic_Sensor__BIE)
/* Bit-mask for Aliased Register Access */
#define Sonic_Sensor_BIT_MASK               (* (reg8 *) Sonic_Sensor__BIT_MASK)
/* Bypass Enable */
#define Sonic_Sensor_BYP                    (* (reg8 *) Sonic_Sensor__BYP)
/* Port wide control signals */                                                   
#define Sonic_Sensor_CTL                    (* (reg8 *) Sonic_Sensor__CTL)
/* Drive Modes */
#define Sonic_Sensor_DM0                    (* (reg8 *) Sonic_Sensor__DM0) 
#define Sonic_Sensor_DM1                    (* (reg8 *) Sonic_Sensor__DM1)
#define Sonic_Sensor_DM2                    (* (reg8 *) Sonic_Sensor__DM2) 
/* Input Buffer Disable Override */
#define Sonic_Sensor_INP_DIS                (* (reg8 *) Sonic_Sensor__INP_DIS)
/* LCD Common or Segment Drive */
#define Sonic_Sensor_LCD_COM_SEG            (* (reg8 *) Sonic_Sensor__LCD_COM_SEG)
/* Enable Segment LCD */
#define Sonic_Sensor_LCD_EN                 (* (reg8 *) Sonic_Sensor__LCD_EN)
/* Slew Rate Control */
#define Sonic_Sensor_SLW                    (* (reg8 *) Sonic_Sensor__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define Sonic_Sensor_PRTDSI__CAPS_SEL       (* (reg8 *) Sonic_Sensor__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define Sonic_Sensor_PRTDSI__DBL_SYNC_IN    (* (reg8 *) Sonic_Sensor__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define Sonic_Sensor_PRTDSI__OE_SEL0        (* (reg8 *) Sonic_Sensor__PRTDSI__OE_SEL0) 
#define Sonic_Sensor_PRTDSI__OE_SEL1        (* (reg8 *) Sonic_Sensor__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define Sonic_Sensor_PRTDSI__OUT_SEL0       (* (reg8 *) Sonic_Sensor__PRTDSI__OUT_SEL0) 
#define Sonic_Sensor_PRTDSI__OUT_SEL1       (* (reg8 *) Sonic_Sensor__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define Sonic_Sensor_PRTDSI__SYNC_OUT       (* (reg8 *) Sonic_Sensor__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(Sonic_Sensor__SIO_CFG)
    #define Sonic_Sensor_SIO_HYST_EN        (* (reg8 *) Sonic_Sensor__SIO_HYST_EN)
    #define Sonic_Sensor_SIO_REG_HIFREQ     (* (reg8 *) Sonic_Sensor__SIO_REG_HIFREQ)
    #define Sonic_Sensor_SIO_CFG            (* (reg8 *) Sonic_Sensor__SIO_CFG)
    #define Sonic_Sensor_SIO_DIFF           (* (reg8 *) Sonic_Sensor__SIO_DIFF)
#endif /* (Sonic_Sensor__SIO_CFG) */

/* Interrupt Registers */
#if defined(Sonic_Sensor__INTSTAT)
    #define Sonic_Sensor_INTSTAT            (* (reg8 *) Sonic_Sensor__INTSTAT)
    #define Sonic_Sensor_SNAP               (* (reg8 *) Sonic_Sensor__SNAP)
    
	#define Sonic_Sensor_0_INTTYPE_REG 		(* (reg8 *) Sonic_Sensor__0__INTTYPE)
#endif /* (Sonic_Sensor__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_Sonic_Sensor_H */


/* [] END OF FILE */
