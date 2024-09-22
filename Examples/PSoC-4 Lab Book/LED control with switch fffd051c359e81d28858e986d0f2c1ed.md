# LED control with switch

> Turn ON an LED if a button is pressed two times within an interval of 1 seconds.
> 

# Creator Schematic

![Untitled](Untitled%2086.png)

# Component Configurations

                                             

![Untitled](Untitled%2087.png)

![Untitled](Untitled%2088.png)

![Untitled](Untitled%2089.png)

![Untitled](Untitled%2090.png)

# Pin Configurations

![Untitled](Untitled%2091.png)

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

CY_ISR(my_isr_1);
CY_ISR(my_isr_2);
int flag;
int main(void)
{
    CyGlobalIntEnable; 
    /* Enable global interrupts. */
    LED_Pin_Write(1);
    
    isr_1_StartEx(my_isr_1);
    isr_2_StartEx(my_isr_2);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
    
}
CY_ISR(my_isr_1)  //GPIO_ISR
{
    
    if(flag == 1)
    {
        LED_Pin_Write(0);
        flag = 0;
        PWM_1_Stop();
       
    }
    
    if(flag == 0)
    {
    flag = 1;
    PWM_1_Start();
    }
    //m = PWM_1_ReadCounter();
    /*int y;
    y = PWM_1_ReadCounter();
    i = y;*/
    isr_ClearInterrupt();
};

CY_ISR(my_isr_2) //PWM_ISR
{   
    /*
    uint32_t counter_value = PWM_1_ReadCounter();
    if(counter_value - i<1000)
    {
    LED_Pin_Write(!LED_Pin_Read());// Toggle LED
    isr_ClearInterrupt();
    }
    else
    {
    LED_Pin_Write(0);
    isr_ClearInterrupt();
    }*/
    flag = 0;
    PWM_1_Stop();
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
}

/* [] END OF FILE */
```

**— END**