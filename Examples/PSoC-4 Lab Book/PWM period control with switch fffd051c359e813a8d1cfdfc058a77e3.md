# PWM period control with switch

# Schematic

![Untitled](Untitled%2070.png)

# PSoC Firmware

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
int var=0;

CY_ISR(Switch_LED_Handler)
{   
    var++;
    if(var>7)
    var=0;
    Switch_LED_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(Switch_LED_Handler);
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    Pin_1_Write(~((var>>0)&0x01));
    Pin_2_Write(~((var>>1)&0x01));
    Pin_3_Write(~((var>>2)&0x01)); 
    }
}

/* [] END OF FILE */
```

**— END**