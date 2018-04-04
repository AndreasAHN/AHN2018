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

void stepperRight(int stepMode, int status, int hastighed)
{

        
             if(stepMode == 1) //Full mode
            {
                 if(status == 2)//Kører forlæns
                    {
                        //Step 1
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A3_Write(1);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                        

                        

                    }
                    
           
                    
                   if(status == 1) //Kører baglæns
                    {
                        //Step 1
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A3_Write(1);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                        


                    }
                    
            
                    
            }
            else if(stepMode == 2) //Half mode
            {
                
                if(status == 2)//Kører forlæns
                    {
                        //Step 1
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A3_Write(1);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                        
                        //Step 5
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                        
                        //Step 6
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 8
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                                   
                                             


                    }
                    
            
                    
                   if(status == 1) //Kører baglæns
                    {
                        //Step 1
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                        
                        //Step 5
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 6
                        A3_Write(1);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                   
                        //Step 8
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);

                    }
                    
           
                
            }
            else if(stepMode == 3) //wave mode
            {
                 if(status == 2)//Kører forlæns
                    {
                        //Step 1
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                        

                    }
                    
            
                    
                   if(status == 1) //Kører baglæns
                    {
                        //Step 1
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A3_Write(0);
                        A4_Write(0);
                        B3_Write(1);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A3_Write(0);
                        A4_Write(1);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A3_Write(1);
                        A4_Write(0);
                        B3_Write(0);
                        B4_Write(0);
                        CyDelayUs(hastighed);
                        

                    }

                    
            }

}

void resetRight()
{
                        
                    //Reset mod kortslutning
                    A3_Write(0);
                    A4_Write(0);
                    B3_Write(0);
                    B4_Write(0);
}

/* [] END OF FILE */




