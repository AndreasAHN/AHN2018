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
#include <stdlib.h>
#include <cydevice.h>//så kan den bedre li at sende

#define slave_1 0x48
uint8 bufferRx1;
uint8 bufferRx2;
char f[36];
uint8 x =0;
/*
CY_ISR(isr_1)
{
   // uint8_t received = UART_1_ReadRxData();
    char received1 = UART_1_GetChar();
   // UART_1_WriteTxData(received);
    UART_1_PutChar(received1);
   
    if (received1 == 'g'){
        UART_1_PutChar(received1);
        x = I2C_1_MasterSendStart(slave_1, 1);
        
        if (I2C_1_MSTR_NO_ERROR == x){
         
            bufferRx1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
            bufferRx2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA);            
            I2C_1_MasterSendStop();
            float j = bufferRx1;                                    //
            snprintf(f, sizeof(f),"Stopped LED: %f\r\n", j);        //den samler tekst strengen med x til en char array; (char array, str af array, det der skal samles
            UART_1_PutString(f);
           
        }
        else{
            UART_1_PutString("Stopped LED\r\n");
        }
    }
   
}
*/
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_1_Start();
   // isr_1_StartEx(isr_1);
    UART_1_Start();
    
    UART_1_PutString("hej");
    for(;;)
    {
        
         x = I2C_1_MasterSendStart(slave_1, 1);
        
        if (I2C_1_MSTR_NO_ERROR == x){
         
            bufferRx1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA);
            bufferRx2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA); 
            
            I2C_1_MasterSendStop();
            uint8 j = bufferRx1; 
            char b[1] = {bufferRx2};
            if (7 >> b[0] == 1){
            //float result = bufferRx1+0.5; (( skal testes
            
           // snprintf(f, sizeof(f),"verdi:  %.1f \r\n", result);        //den samler tekst strengen med x til en char array; (char array, str af array, det der skal samles
           snprintf(f, sizeof(f),"verdi:  %d 0.5 \r\n", j);
                UART_1_PutString(f);
            }
            else{
                snprintf(f, sizeof(f),"verdi:  %d \r\n", j);        //den samler tekst strengen med x til en char array; (char array, str af array, det der skal samles
            UART_1_PutString(f);
            }
            
        }
        else{
            UART_1_PutString("virker ikke\r\n");
            I2C_1_MasterSendStop();                             // fortæller slaven at kommukitationen er slut
        }
        CyDelay(500);
    }
}


