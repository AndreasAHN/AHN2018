/* ========================================
 *
 *  Stepper.h
 *
 *  Created: 13-09-2017 22:42:53
 *  Author: Andreas Hervert Nielsen
 * 
 * ========================================
 */

#include "project.h"
#include <stdio.h>
#include <CyLib.h>

int status = 0;
unsigned long hastighed = 1;
char ledStatus = 0;
int stepMode = 0;
int step = 0;



CY_ISR(UART_1_Rx_Handler)
{
    uint8_t received = UART_1_ReadRxData();
    UART_1_WriteTxData(received);
    
        
    if (received == 'a')
    {
        UART_1_PutString("\nMotor Fremad \r \n");
        status = 1;
        LED_Write(1);
    }
    else if (received == 'd')
    {
        UART_1_PutString("\nMotor Tilbage \r \n");
        status = 2;
        LED_Write(1);
    }
    else if (received == 's')
    {
        UART_1_PutString("\nMotor Stoppet \r \n");
        status = 0;
        LED_Write(0);
    }
    else if (received == 'q')
    {
        UART_1_PutString("\nMotor mode: Half mode \r \n");
        stepMode = 2;
    }
    else if (received == 'e')
    {
        UART_1_PutString("\nMotor mode: Full mode \r \n");
        stepMode = 1;
    }
    else if (received == 'w')
    {
        UART_1_PutString("\nMotor mode: wave mode \r \n");
        stepMode = 3;
    }
    else if (received == 'z')
    {
        UART_1_PutString("\nTager en enkelt omgang, ved naeste start. \r \n");
        step = 1;
    }
    else if (received == '1')
    {
        UART_1_PutString("\nMotor hastighed: Snegl \r \n");
        hastighed = 18;
    }
    else if (received == '2')
    {
        UART_1_PutString("\nMotor hastighed: Skildpade \r \n");
        hastighed = 16;
    }
    else if (received == '3')
    {
        UART_1_PutString("\nMotor hastighed: Mus \r \n");
        hastighed = 14;
    }
    else if (received == '4')
    {
        UART_1_PutString("\nMotor hastighed: Elephant \r \n");
        hastighed = 12;
    }
    else if (received == '5')
    {
        UART_1_PutString("\nMotor hastighed: Hare \r \n");
        hastighed = 10;
    }
    else if (received == '6')
    {
        UART_1_PutString("\nMotor hastighed: Hund \r \n");
        hastighed = 8;
    }
    else if (received == '7')
    {
        UART_1_PutString("\nMotor hastighed: Hjort \r \n");
        hastighed = 6;
    }
    else if (received == '8')
    {
        UART_1_PutString("\nMotor hastighed: Hest \r \n");
        hastighed = 4;
    }
    else if (received == '9')
    {
        UART_1_PutString("\nMotor hastighed: Tiger \r \n");
        hastighed = 2;
    }
    else if (received == '0')
    {
        UART_1_PutString("\nMotor hastighed: Leopard \r \n");
        hastighed = 1;
    }
    else
    {
        UART_1_PutString("\n \n \nHELP1: Du kan brug 1 til 9 og 0 for hastigheder. \r \n"); 
        UART_1_PutString("HELP2: Q og E og W for half, full og wave mode. \r \n");
        UART_1_PutString("HELP3: z for at tage en enkel omgang. \r \n");
        UART_1_PutString("HELP4: A og D er for fremad og bakgear. \r \n \n \n");
    }
}    



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    isr_UART_1_RX_StartEx(UART_1_Rx_Handler);
    UART_1_Start();
    UART_1_PutString("Application started\r\n");
    LED_Write(0);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    for(;;)
    {
        
        //Reset mod kortslutning
        A1_Write(0);
        A2_Write(0);
        B1_Write(0);
        B2_Write(0);
        
             if(stepMode == 1) //Full mode
            {
                 while(status == 1)//Kører forlæns
                    {
                        //Step 1
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        //Step 2
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                                           
                        //Step 3
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        ledStatus = ! ledStatus;
                        LED_Write(ledStatus);
                        
                        if(step == 1)
                        {
                          status = 0;   
                        }
                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    
                   while(status == 2) //Kører baglæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        //Step 2
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                                                           
                        //Step 3
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        ledStatus = ! ledStatus;
                        LED_Write(ledStatus);
                        
                        if(step == 1)
                        {
                          status = 0; 
                          step = 0;
                        }
                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    
            }
            else if(stepMode == 2) //Half mode
            {
                
                while(status == 1)//Kører forlæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                                    
                        //Step 2
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                                    
                        //Step 3
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                   
                        //Step 4
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                        
                        //Step 6
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                        //Step 7
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                        //Step 8
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelay(hastighed);
                                   
                                             
                        ledStatus = ! ledStatus;
                        LED_Write(ledStatus);
                        
                        if(step == 1)
                        {
                          status = 0;
                            step = 0;
                        }
                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    
                   while(status == 2) //Kører baglæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                                    
                        //Step 2
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelay(hastighed);
                                    
                        //Step 3
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                                   
                        //Step 4
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                        //Step 6
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                        //Step 7
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                   
                        //Step 8
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        ledStatus = ! ledStatus;
                        LED_Write(ledStatus);
                        
                        if(step == 1)
                        {
                          status = 0;   
                            step = 0;
                        }
                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                
            }
            else if(stepMode == 3) //wave mode
            {
                 while(status == 1)//Kører forlæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        //Step 2
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                                           
                        //Step 3
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                        
                        ledStatus = ! ledStatus;
                        LED_Write(ledStatus);
                        
                        if(step == 1)
                        {
                          status = 0;   
                            step = 0;
                        }
                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    
                   while(status == 2) //Kører baglæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelay(hastighed);
                        
                        //Step 2
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelay(hastighed);
                                                           
                        //Step 3
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelay(hastighed);
                        
                        ledStatus = ! ledStatus;
                        LED_Write(ledStatus);
                        
                        if(step == 1)
                        {
                          status = 0;   
                            step = 0;
                        }
                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    
            }
    }
    
    
    
}

/* [] END OF FILE */
