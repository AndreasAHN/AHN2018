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

void stepperLeft(int stepMode, int status, int hastighed)
{

        
             if(stepMode == 1) //Full mode
            {
                 if(status == 1)//Kører forlæns
                    {
                        //Step 1
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                        

                        

                    }
                    
    
                    
                   if(status == 2) //Kører baglæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                        


                    }
                    

            }
            else if(stepMode == 2) //Half mode
            {
                
                if(status == 1)//Kører forlæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                        
                        //Step 6
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 8
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                                   
                                             


                    }

                    
                   if(status == 2) //Kører baglæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 2
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                                    
                        //Step 3
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                   
                        //Step 4
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                        
                        //Step 5
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 6
                        A1_Write(1);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                        //Step 7
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                   
                        //Step 8
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);

                    }
                    

                
            }
            else if(stepMode == 3) //wave mode
            {
                 if(status == 1)//Kører forlæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                        

                    }
                    

                    
                   if(status == 2) //Kører baglæns
                    {
                        //Step 1
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(1);
                        CyDelayUs(hastighed);
                        
                        //Step 2
                        A1_Write(0);
                        A2_Write(0);
                        B1_Write(1);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                                           
                        //Step 3
                        A1_Write(0);
                        A2_Write(1);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                                    
                                                         
                        //Step 4
                        A1_Write(1);
                        A2_Write(0);
                        B1_Write(0);
                        B2_Write(0);
                        CyDelayUs(hastighed);
                        

                    }
                    
                    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
                    
            }

}


void resetLeft()
{
    //Reset mod kortslutning
                    A1_Write(0);
                    A2_Write(0);
                    B1_Write(0);
                    B2_Write(0);
}
/* [] END OF FILE */




