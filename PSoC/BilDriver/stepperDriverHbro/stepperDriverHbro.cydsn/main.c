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



void forward();
void backward();
void left();
void right();
void speed();

int hastighed = 800;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
       
        
                
                
                
            
        
        
    }
    
    PWM_1_Stop();
}

/* [] END OF FILE */




void speed(int hast)
{
    PWM_1_WriteCompare(hast);
}


void backward()
{
    sleep_Write(1);
      dir1_Write(1);
      dir2_Write(0);
    
    for(int x = 0; x < 400; x++)
    {
      step_Write(1);
      
      CyDelayUs(hastighed);
      step_Write(0);
      
    }
    
      sleep_Write(0);
      dir1_Write(0);
      dir2_Write(0);
      sleep_Write(0);
}


void forward()
{
    sleep_Write(1);
    dir1_Write(0);
    dir2_Write(1);

    for(int x = 0; x < 400; x++)
        {
          step_Write(1);
          
          CyDelayUs(hastighed);
          step_Write(0);
          
        }
        
          
          dir1_Write(0);
          dir2_Write(0);
          sleep_Write(0);
}

void left()
{
      sleep_Write(1);
      dir1_Write(0);
        dir2_Write(0);
      
    
      for(int x = 0; x < 100; x++)
        {
          step_Write(1);
          
          CyDelayUs(hastighed);
          step_Write(0);
          
        }
        
          
          dir1_Write(0);
          dir2_Write(0);
          sleep_Write(0);
}

void right()
{
     sleep_Write(1);
      dir1_Write(1);
    dir2_Write(1);
      

      for(int x = 0; x < 100; x++)
        {
          step_Write(1);
          
          CyDelayUs(hastighed);
          step_Write(0);
          
        }
        
          
          dir1_Write(0);
          dir2_Write(0);
          sleep_Write(0);
}