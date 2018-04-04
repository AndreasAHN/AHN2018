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

/* [] END OF FILE */
#include "I2C_sensor.h" //Andreas I2C til ultralyd sensor bib

/*

//TIL I2C sensor

#define initiateSensor 0b11100000
#define writeRange 0b01010001
#define readRange 0b11100001

#define slave_rx 0xE0
#define slave_tx 0x51


uint8 bufferRx1;
uint8 bufferRx2;
uint8 bufferTx1;
uint8 bufferTx2;
char f[36];
uint8 x =0;

uint8 statusI2C = 0;
float message = 0;



//Til arduino sensoren
uint16 counts = 0; 
float  feet   = 0; 
uint16 i      = 0; 



void ultraDelay()
{
    
}


void ultraTrigger()
{
    
    
    
    //bufferTx1 = 0b01010001;
        
        statusI2C = I2C_1_MasterSendStart(slave_rx, 1); //kontroler om slaven lm75 er klar til at komminuker
        
        
        //kvis I2C er klar  til at komminuker
        if (statusI2C == I2C_1_MSTR_NO_ERROR)
        {
            bufferRx1 = I2C_1_MasterReadByte(I2C_1_ACK_DATA);  //Modtager de 
            bufferRx2 = I2C_1_MasterReadByte(I2C_1_NAK_DATA);
            
            I2C_1_MasterSendStop();     //fortæller slave at den skal stoppe med at sende information
             
            if((bufferRx1 == slave_rx )      //Initiate a write at the sensor address 
            {
                message = bufferRx2;               //Beskeden bliver overført fra buffer. 
                //UART_1_PutString("Temp: ");
                //writeTempToUART(temp);            //Sender temp
            }
            else
            {
                message = bufferRx1;
                //UART_1_PutString("Temp: ");
                //writeTempToUART(temp);             //Sender temp uden halve grader
            }
     
            CyDelay(50);
            
            if((bufferRx1 == slave_rx )      //Initiate a write at the sensor address 
            {
                message = bufferRx2;               //Beskeden bliver overført fra buffer. 
                //UART_1_PutString("Temp: ");
                //writeTempToUART(temp);            //Sender temp
            }
            else
            {
                message = bufferRx1;
                //UART_1_PutString("Temp: ");
                //writeTempToUART(temp);             //Sender temp uden halve grader
            }
            
            }
        
         else{                                                  //kvis I2C ikke er klar  til at komminuker
            UART_1_PutString("virker ikke\r\n");
            I2C_1_MasterSendStop();                             // fortæller slaven at kommukitationen er slut
        }
 }



float ultraEcho()
{
    float distance = 0;
    
    
    return distance;
}




void afstand()
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

        if (feet < 1.0 ) 
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
*/