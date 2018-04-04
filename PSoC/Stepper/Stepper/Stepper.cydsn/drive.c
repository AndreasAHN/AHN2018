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
#define fart 1900

void runForward()
{
  int x;
    
    for(x = 0; x < 680; x = x + 1)
    {
        resetLeft();
        resetRight();
        stepperLeft(2, 1, fart);
        stepperRight(2, 1, fart);
    }
 }
/* [] END OF FILE */


void runBackward()
{
  int x;
    
    for(x = 0; x < 680; x = x + 1)
    {
        resetLeft();
        resetRight();
        stepperLeft(2, 2, fart);
        stepperRight(2, 2, fart);
    }
 }

void turnLeft()
{
  int x;
    
    for(x = 0; x < 824; x = x + 1)
    {
        resetLeft();
        resetRight();
        stepperLeft(2, 1, fart);
        stepperRight(2, 2, fart);
    }
 }


void turnRight()
{
  int x;
    
    for(x = 0; x < 880; x = x + 1)
    {
        resetLeft();
        resetRight();
        stepperLeft(2, 2, fart);
        stepperRight(2, 1, fart);
    }
 }