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
#include <cydevice.h>//så kan den bedre li at sende

#include "getDistance.h" //Mortens beregning bib


float afstand(); //Benyttes til at Arduino Ultra lyd sensoren

void ultraEcho();  //Til at modtage et ekko fra en ultra lyd sensor.

void ultraDelay();  //Til at starte counter på I2C ultra lyd sensoren. Skal benyttes om der sendes eller modtages!!!

void ultraTrigger();  //Til at sende et ekko ud på I2C ultra lyd sensoren




//TIL I2C sensor
#define initiateSensor 0b11100000
#define writeRange 0b01010001
#define readRange 0b11100001
#define slave_rx 0xE0
#define slave_tx 0x51


//Til I2C sensor
uint8 bufferRx1;
uint8 bufferRx2;
uint8 bufferTx1;
uint8 bufferTx2;
uint8 statusI2C = 0;

//I2C variabler
volatile float distance1, distance2 = 0;

//Til terminalen
float message = 0;
char f[256]; //Buffer til at sende string


CY_ISR(UART_1_Rx_Handler) //Kan benyttes til input til terminal, for debugning.
{
    uint8_t received = UART_1_ReadRxData();
    UART_1_WriteTxData(received);
    
        
    if (received == 'a')
    {
        UART_1_PutString("\n Test på input a \r \n");
        
       
    }
    else if (received == 'z')  //Benyttes til at modtage fra en Arduino Ultra lyd sensor.
    {
        UART_1_PutString("\n \n \n \n \nModtager fra Ultralyd arduino sensor \r \n");
        
        float distance = afstand();
        snprintf(f, sizeof(f),"\nVaerdi:  %f fra arduino \r\n \n \n \n \n \n", distance);
        UART_1_PutString(f);
        
        if (distance < 0.05)
        {
            LED_Write(1);
        }
        else
        {
           LED_Write(0);
        }
    }
    else //Skriv dine funktioner her neden for under HELP
    {
        
        
        
        /* //Eksempel på HELP Menu, benyttet fra GFV øvelse tideligere.
        UART_1_PutString("\n \n \nHELP1: Du kan brug 1 til 9 og 0 for hastigheder. \r \n"); 
        UART_1_PutString("HELP2: Q og E og W for half, full og wave mode. \r \n");
        UART_1_PutString("HELP3: z for at tage en enkel omgang. \r \n");
        UART_1_PutString("HELP4: A og D er for fremad og bakgear. \r \n \n \n");
        */
    }
}    



int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    I2C_1_Start();
    isr_UART_1_RX_StartEx(UART_1_Rx_Handler);
    UART_1_Start();
    UART_1_PutString("Application started\r\n");
    Counter_Start();
    
    LED_Write(0);
    VCC_Write(1); //VCC er til arduino sensoren, da den får strøm fra et digital ben, istedet for VCC. #DovenSkab
    
    
    for(;;)
    {
        
        char mode = 0;  //Skriv 1 her, for at vælge sender mode og 1 for modtager. 0 Er både sende og modtage mode.
       UART_1_PutString("Starter forfra \r \n");
    
    
    
        if ( mode == 2)   //Sender mode, hvor den sender ultra lyd signal
        {
           while(0 == Ekko_Read())  //Venter på besked fra den anden PSoC om at må sende et ekko på ultra lyd sensoren.
            {
                UART_1_PutString("Venter \r \n");
            }
            
            ultraDelay(); //Intering til Ultra lyd sensoren

            ultraTrigger(); // Sender ekko ud på ultralyd sensoren
            
            UART_1_PutString("Sender Lyd  \n");
            
            CyDelayUs(100);
            
            UART_1_PutString("Begynder oprydning af buffer til I2C \r \n");
            I2C_1_MasterClearReadBuf();
            I2C_1_MasterClearWriteBuf();
        }
        else if( mode == 1)  //Modtager mode, hvor den får distancen.
        {
            CyDelay(500); //500ms
            
            UART_1_PutString("Trigger. \r \n");
              
            Trigger_Write(1); // Sender et signal til den anden PSoC, om at sende et ekko
            
            ultraDelay(); //Starter counter for ultralyd sensoren

            UART_1_PutString("Modtager Lyd  \n");
            
            CyDelayUs(10); //Venter 10us for at være sikker på at kunne modtage
            
           ultraEcho(); //Modtager lyden
           UART_1_PutString("Lyd modtaget \r \n");
        
            Trigger_Write(0);
        
           snprintf(f, sizeof(f),"test1 modtager afstand:  %f \r\n", distance1);
           UART_1_PutString(f);
            snprintf(f, sizeof(f),"test2 modtager afstand:  %f \r\n", distance2);
           UART_1_PutString(f);

           UART_1_PutString("Begynder oprydning af buffer til I2C \r \n");
         
            I2C_1_MasterClearReadBuf();
            I2C_1_MasterClearWriteBuf();
        }
        else //Sende og modtage mode
        {
            CyDelay(500); //500ms
            
            UART_1_PutString("Trigger. \r \n");
              
            Trigger_Write(1); // Sender et signal til den anden PSoC, om at sende et ekko
            
            ultraDelay(); //Starter counter for ultralyd sensoren
            
            ultraTrigger(); // Sender ekko ud på ultralyd sensoren

            UART_1_PutString("Modtager Lyd  \n");
            
            //CyDelayUs(10); //Venter 10us for at være sikker på at kunne modtage
            
           ultraEcho(); //Modtager lyden
           UART_1_PutString("Lyd modtaget \r \n");
        
            Trigger_Write(0);
        
           snprintf(f, sizeof(f),"test1 modtager afstand:  %f \r\n", distance1);
           UART_1_PutString(f);
            snprintf(f, sizeof(f),"test2 modtager afstand:  %f \r\n", distance2);
           UART_1_PutString(f);

           UART_1_PutString("Begynder oprydning af buffer til I2C \r \n");
         
            I2C_1_MasterClearReadBuf();
            I2C_1_MasterClearWriteBuf();
        }
        
        
            
            
    }
}





void ultraDelay()  //Starter UltraLyd sensoren og får den til at counte, til den får en puls.
{
    statusI2C = I2C_1_MasterSendStart(slave_tx, 0); //kontroler om slaven lm75 er klar til at komminuker
    
    
    if(statusI2C == I2C_1_MSTR_NO_ERROR) //Hvis ingen fejl, send beskeden.
    {
        I2C_1_MasterWriteByte(initiateSensor); 
    }
}


void ultraTrigger()  //Sender et ultra lyd signal ud.
{
    statusI2C = I2C_1_MasterSendStart(slave_tx, 0); //kontroler om slaven lm75 er klar til at komminuker

    if(statusI2C == I2C_1_MSTR_NO_ERROR)  //Hvis ingen fejl, send beskeden.
    {
        I2C_1_MasterWriteByte(writeRange); 
    }     
 }



void ultraEcho() //Benyttes til at hente distancen fra Ultralyd sensoren
{
    statusI2C = I2C_1_MasterSendStart(slave_rx, 1); //kontroler om slaven lm75 er klar til at komminuker
        
        //kvis I2C er klar  til at komminuker
        if (statusI2C == I2C_1_MSTR_NO_ERROR)
        {
            bufferRx1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA);  //Modtager 
            bufferRx2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
            
            I2C_1_MasterSendStop();     //fortæller slave at den skal stoppe med at sende information
             
            if(bufferRx1 == slave_rx )      //Initiate a write at the sensor address 
            {
                message = bufferRx2;               //Beskeden bliver overført fra buffer. 
            }
            else
            {
                UART_1_PutString("Kunne ikke overfoerer fra buffer1");
            }
                
            distance1 = message;
            
                   
            CyDelay(50);
            
            bufferRx1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA);  //Modtager de 
            bufferRx2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
            
            if(bufferRx2 == slave_rx )      //Initiate a write at the sensor address 
            {
                message = bufferRx2;               //Beskeden bliver overført fra buffer. 
            }
            else
            {
                UART_1_PutString("Kunne ikke overfoerer fra buffer2");
            }
            
            distance2 = message;
            //Funktionen under, var tænkt til at samle distance, ikke sikkert den bliver nødvendig.
            //distance = (bufferRx2[0] * 256 + bufferRx2[1] * 512 + bufferRx2[2] * 1024 + bufferRx2[3] * 2048 + bufferRx2[4] * 4096 + bufferRx2[5] * 8192 + bufferRx2[6] * 16384 + bufferRx2[7] * 32768 + bufferRx2[8] * 65536) + distance;
            
        }
         else
        {                                                  //kvis I2C ikke er klar  til at komminuker
            UART_1_PutString("virker ikke\r\n");
            I2C_1_MasterSendStop();                             // fortæller slaven at kommukitationen er slut
        }
    
        snprintf(f, sizeof(f),"verdi1:  %f \r\n", distance1); //Skriver den første del af distance ud
        UART_1_PutString(f);
        
            snprintf(f, sizeof(f),"verdi2:  %f \r\n", distance2); //Skriver den anden del af distance ud
        UART_1_PutString(f);

}




float afstand()  //!!!!!!!!!!!!!Benyttes kun til Arduino sensoren!!!!!!!!!!!!!!
  {
	    uint16 counts = 0; // value to store results from the counter
        float  feet = 0; 
    
 
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
         
        Enable_Write(0);// reset the counter 
            
        snprintf(f, sizeof(f),"verdi:  %f \r\n", feet); //Sætter værdierne ud, har allerede oversat feet til meter ved konstanten tideligere.
        UART_1_PutString(f);
        
        return feet;

	 
  }