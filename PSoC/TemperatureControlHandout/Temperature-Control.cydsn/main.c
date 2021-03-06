/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <stdio.h>
#include "project.h"
#include "PIDControl.h"

static char outputBuffer[256];
static float setPoint = 50; // degrees celcius

#define SAMPLES_PER_SECOND 3
static uint16_t sampleWaitTimeInMilliseconds = 1000 / SAMPLES_PER_SECOND;


uint8 status = 0;
uint8 a,b; 

float temp = 0;


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_1_Enable();
    
    

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    float Kp = 2.0f;
    float Ki = 1.0f/30.0f;
    float Kd = 0.0f;
    float integralMax = 3000;
    float integralMin = -3000;
    float controlSignal = 0;

    float dt = ((float)sampleWaitTimeInMilliseconds) / 1000; // dt is measured in seconds
    PIDControl_init(Kp, Ki, Kd, integralMax, integralMin, dt);
    PIDControl_changeSetPoint(setPoint);

//    UART_1_PutString("Temperature control application started\r\n");

    for(;;)
    {
        /* Place your application code here. */
        float error = setPoint - temp;
        float proportionalPart = 0;
        float integralPart = 0;
        float derivativePart = 0;
        
        
        status = I2C_1_MasterSendStart(0x48, 1);
    
    if (status == I2C_1_MSTR_NO_ERROR)
    {
        a = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
        b = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
        
        if (a > 127)
        {
             temp = ~(a-1);
        }
        else
        {
            temp = ~a;
        }
        if (b > 127)
        {
             temp = temp + 0.5;
        }
        
        I2C_1_MasterSendStop();
        
        
        CyDelay(300);
        
        
        controlSignal = PIDControl_doStep(temp, &proportionalPart, &integralPart, &derivativePart);            
        snprintf(outputBuffer, sizeof(outputBuffer), "%f, %f, %f, %f, %f, %f, %f, %f, %f, %f \r\n", 
                                                      setPoint, temp, error, controlSignal, Kp, Ki, Kd, 
                                                      proportionalPart, integralPart, derivativePart);
    }
//        UART_1_PutString(outputBuffer);

        CyDelay(sampleWaitTimeInMilliseconds);
    }
}

/* [] END OF FILE */
