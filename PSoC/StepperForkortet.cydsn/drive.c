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
#define hastighed 1500

void runForward()
{
  int x;
    
    for(x = 0; x < 680; x = x + 1)
    {
               
        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                         A3_Write(1);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                        
                        //Step 6
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 8
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(1);
        CyDelayUs(hastighed);
    }
    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    //Reset mod kortslutning
    A3_Write(0);
    A4_Write(0);
    B3_Write(0);
    B4_Write(0);
 }
/* [] END OF FILE */


void runBackward()
{
  int x;
    
    for(x = 0; x < 680; x = x + 1)
    {
         //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                         A3_Write(0);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 6
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                         A3_Write(1);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                   
                        //Step 8
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
    }
    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    //Reset mod kortslutning
    A3_Write(0);
    A4_Write(0);
    B3_Write(0);
    B4_Write(0);
 }

void turnLeft()
{
  int x;
    
    for(x = 0; x < 824; x = x + 1)
    {
         //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                        
                        //Step 6
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(1);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 8
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
        
    }
 }


void turnRight()
{
  int x;
    
    for(x = 0; x < 880; x = x + 1)
    {
        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
        A3_Write(0);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(1);
        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                         A3_Write(0);
        A4_Write(0);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(1);
        B4_Write(0);
        CyDelayUs(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(0);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 6
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(1);
        A4_Write(1);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(0);
        CyDelayUs(hastighed);
                                   
                        //Step 8
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        A3_Write(1);
        A4_Write(0);
        B3_Write(0);
        B4_Write(1);
        CyDelayUs(hastighed);
        
    }
 }