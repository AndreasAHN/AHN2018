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
#include <stdlib.h>


void afstand();

int motor = 0;
int drej = 0;

uint16 counts = 0; 
int  feet   = 0; 
uint16 i      = 0; 

char f[36];


CY_ISR(UART_1_Rx_Handler)
{
    uint8_t received = UART_1_ReadRxData();
    UART_1_WriteTxData(received);
    
        
    if (received == 'a')
    {
        UART_1_PutString("\n Drejer til venstre \r \n");
        drej = 1;
       
    }
    else if (received == 'd')
    {
        UART_1_PutString("\n Drejer til hoejre \r \n");
       drej = 2;
    }  
    else if (received == 'w')
    {
        UART_1_PutString("\n Fremad \r \n");
        motor = 1;
        
        
    }
    else if (received == 'x')
    {
        UART_1_PutString("\n Tilbage af \r \n");
        motor = 2;
        
    }
    else if (received == 's')
    {
        UART_1_PutString("\nMotor Stoppet \r \n");
        motor = 0;
    }
    else if (received == 'z')
    {
        UART_1_PutString("\n \r \n");
        
        CyDelay(250);
         LED_Write(1);
        
        afstand();
        snprintf(f, sizeof(f),"verdi:  %d \r\n", feet);
        UART_1_PutString(f);
        CyDelay(250);
        LED_Write(0);
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
     VCC_Write(1); 
    
    Counter_Start();
    
    for(;;)
    {
        
        if (motor == 0)
        {
            MOR_Write(1);
            CyDelay(500);
            
        }
        else if (motor == 2)
        {
            motorMode_Write(0);
            MOR_Write(0);
            CyDelay(500);
        }
        else if (motor == 1)
        {
            motorMode_Write(1);
            MOR_Write(0);
            CyDelay(500);
        }
        
        
         if (drej == 2)
        {
            D_Write(0);
            DrejRun_Write(0);
            
            CyDelay(500);
            
            drej = 0;
        }
        else if (drej ==1)
        {
            D_Write(1);
            DrejRun_Write(0);
            
            CyDelay(500);
            
            drej = 0;
        }
        else if (drej == 0)
        {
            DrejRun_Write(1);
        }
        
        UART_1_PutString("\n \r \n");
        
        CyDelay(250);
         LED_Write(1);
        
        afstand();
        snprintf(f, sizeof(f),"verdi:  %d \r\n", feet);
        UART_1_PutString(f);
        CyDelay(250);
        LED_Write(0);
    }
    
    
    
}


void afstand()
  {
	    uint16 counts = 0; // value to store results from the counter
        int  feet = 0; 
 
        Enable_Write(0); 
        Sonic_Sensor_Write(1);   //Output the sensor pulse 


        CyDelayUs(10); //wait for the sensor pulse to finish 


        Sonic_Sensor_Write(0); //shut off the sensor pulse
        Enable_Write(1); 
 
        Sonic_Sensor_Read(); //receive return pulse 

        CyDelay(50); // wait for the maximum value of the return pulse 

        counts = Counter_ReadCounter();// read counter value 

        feet = counts * 0.0001717; //convert pulse width to feet, to convert to meters, multiply by 0.0001717 instead. 

        CyDelayUs(10);

        if (feet < 30 ) 
            { 
               
                LED_Write(1); 
                 
                
            } 
             
             else 
            { 
          
                LED_Write(0); 
             } 
                
              Enable_Write(0);// reset the counter 


	  return;
  }

/* [] END OF FILE */
