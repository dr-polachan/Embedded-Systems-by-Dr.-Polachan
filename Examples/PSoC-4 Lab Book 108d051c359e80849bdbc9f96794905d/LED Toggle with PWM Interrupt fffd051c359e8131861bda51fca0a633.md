# LED Toggle with PWM Interrupt

Toggle LED-1, 2 and 3 at 1sec, 10sec and 15sec respectively. Use a PWM to generate the delay. 

# Creator Schematic

                                                      

![Untitled](LED%20Toggle%20with%20PWM%20Interrupt%20fffd051c359e8131861bda51fca0a633/Untitled.png)

# Component Configurations

![Untitled](LED%20Toggle%20with%20PWM%20Interrupt%20fffd051c359e8131861bda51fca0a633/Untitled%201.png)

![Untitled](LED%20Toggle%20with%20PWM%20Interrupt%20fffd051c359e8131861bda51fca0a633/Untitled%202.png)

                                             

![Untitled](LED%20Toggle%20with%20PWM%20Interrupt%20fffd051c359e8131861bda51fca0a633/Untitled%203.png)

# Pin Configurations

![Untitled](LED%20Toggle%20with%20PWM%20Interrupt%20fffd051c359e8131861bda51fca0a633/Untitled%204.png)

![Untitled](LED%20Toggle%20with%20PWM%20Interrupt%20fffd051c359e8131861bda51fca0a633/Untitled%205.png)

# Firmware

```c
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

CY_ISR(my_isr);

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_1_StartEx(my_isr);
    PWM_1_Start();

    for(;;)
    {
        /* Place your application code here. */
    }
}
CY_ISR(my_isr)
{
    static uint16_t count1=0;
    static uint16_t count2=0;
    static uint16_t count3=0;

    
    
    count1++;
    if(count1 == 1)
    {
        count1 = 0;
        Pin_Led_1_Write(! Pin_Led_1_Read());
        
    }
    
    count2++;
     if(count2 == 10)
    {
        count2 = 0;
        Pin_Led_2_Write(! Pin_Led_2_Read());
       
        
    }
    
    count3++;
     if(count3 == 15)
    {
        count3 = 0;
        Pin_Led_3_Write(! Pin_Led_3_Read()); 
        
        
    }
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
 
}
    
/* [] END OF FILE */
```

**— END**