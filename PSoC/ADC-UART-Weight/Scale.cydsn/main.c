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
#include "project.h"
#include <stdio.h>

CY_ISR_PROTO(ISR_UART_rx_handler);
void handleByteReceived(uint8_t byteReceived);

int x = 0;
uint16_t m8 = 1;
uint16_t m10 = 1;
uint16_t m12 = 1;
uint16_t kali = 1;
uint16_t tara = 0;
uint16_t pre = 1;
int Buffer;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    char uartBuffer[256];

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_uart_rx_StartEx(ISR_UART_rx_handler); //Aktivere interrupt, til taste input
    UART_1_Start(); // Aktivere UART med baudrate på 9600 
    ADC_SAR_1_Start();
    ADC_SAR_1_StartConvert();
    
    UART_1_PutString("Scale application started\r\n");

    for(;;)
    {
        /* Place your application code here. */
        if (ADC_SAR_1_IsEndConversion(ADC_SAR_1_WAIT_FOR_RESULT)) //Venter på hex værdi fra vægten.
        {
            uint16_t result = ((ADC_SAR_1_GetResult16() - pre) * kali) - tara * kali; //Indlæsning af værdier, gange kali på, så vi får ud i gram. Minuser med tara, for at vi få værdi til 0.
            
            if(result > 1000) //Da det er op til 1000 gram. Hvis den visser over, er vi i en minus værdie
                {
                  snprintf(uartBuffer, sizeof(uartBuffer), "ADC result: %d \r\n", result - 65535); //Vi benytter 65535, da vi kører i en 16 bit int. Hvor vi minuser det med result, for at få resultattet i minus.
                    UART_1_PutString(uartBuffer);  
                }
             else //Hvis ikke er vi i plus værdi
                {
                    snprintf(uartBuffer, sizeof(uartBuffer), "ADC result: %d \r\n", result); //Udskriver resultat normalt. Vi benytter %d, for at få konverteret fra hex til decimal.
                    UART_1_PutString(uartBuffer); 
                }
        }
        
        CyDelay(100);
    }
}

CY_ISR(ISR_UART_rx_handler) //Aktiveres ved modtagelse af tasteinput
{
    uint8_t bytesToRead = UART_1_GetRxBufferSize();
    while (bytesToRead > 0) //Indlæser hvis der trykkes på en tast.
    {
        uint8_t byteReceived = UART_1_ReadRxData();
        UART_1_WriteTxData(byteReceived); // echo back
        
        handleByteReceived(byteReceived);
        
        bytesToRead--;
    }
}

void handleByteReceived(uint8_t byteReceived)
{
    char uartBuffer[256]; //Buffer til lagering af hex modtagelse fra ADC. Benyttes til convertering, til output på UART.
    
    switch(byteReceived)
    {
        case 'q' : //Kalibrering indholder lige nu fejl, benyt tara i stedet på W. Arbejde handels stadig på denne.
        {
            if( x == 0) //Til kalibrering med m8, springer videre til m10 ved næste Q
            {
                pre = ADC_SAR_1_GetResult16();
                snprintf(uartBuffer, sizeof(uartBuffer), "Insert Preload is:  %d \r\n", pre);
                UART_1_PutString(uartBuffer);
                CyDelay(1000);
                x = x + 1;
            }
            else if( x == 1) //Til kalibrering med m8, springer videre til m10 ved næste Q
            {
                m8 = ADC_SAR_1_GetResult16();
                snprintf(uartBuffer, sizeof(uartBuffer), "Insert M8 is:  %d \r\n", m8);
                UART_1_PutString(uartBuffer);
                CyDelay(1000);
                x = x + 1;
            }
            else if (x == 2) //Til kalibrering med m10, springer videre til m10 ved næste Q
            {
                m10 = ADC_SAR_1_GetResult16();
                snprintf(uartBuffer, sizeof(uartBuffer), "Insert M10 is:  %d \r\n", m10);
                UART_1_PutString(uartBuffer);
                CyDelay(1000);
              x = x + 1;
            }
            else if (x == 3)//Til kalibrering med m12, springer videre til m10 ved næste Q
            {
              m12 = ADC_SAR_1_GetResult16(); 
                snprintf(uartBuffer, sizeof(uartBuffer), "Insert M12 is:  %d \r\n", m12);
                UART_1_PutString(uartBuffer);
              x = 0;
              kali = ((pre / m8) + (pre / m10) + (pre / m12)) / 3; //Vi laver en samlet regretion, for at få vores konstant til gram.
                snprintf(uartBuffer, sizeof(uartBuffer), "Kali is:  %d \r\n", kali);
                UART_1_PutString(uartBuffer);
                CyDelay(2000);
            }
        }
        break;
        case 'w' : // Benyttes til tara. Så vægten kommer ned på nul. Skal benyttes for vi får output. Lig minimum 250 gram på vægten, før mindre vægt, for at få et præcist output.
        {
                 tara = ADC_SAR_1_GetResult16(); //Tryk W , læser værdie til minus og tara.
                snprintf(uartBuffer, sizeof(uartBuffer), "Tara is:  %d \r\n", tara); //Tryk W og vi indlæser dens vægt.
                UART_1_PutString(uartBuffer);
                CyDelay(1000);
        }
        break;
        default :
        {
            // nothing
        }
        break;
    }
}

/* [] END OF FILE */