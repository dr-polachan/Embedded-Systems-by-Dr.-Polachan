# LED toggle with PWM interrupt

> Toggle LED-1, 2 and 3 at 1sec, 10sec and 15sec respectively. Use a PWM to generate the delay.
> 

# Creator Schematic

                                              

![Untitled](Untitled%2080.png)

![Untitled](Untitled%2081.png)

# Component Configurations

![Untitled](Untitled%2082.png)

                                             

![Untitled](Untitled%2083.png)

![Untitled](Untitled%2084.png)

# Pin Configurations

![Untitled](Untitled%2085.png)

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

uint16_t var1 = 0;
uint16_t var10 = 0;
uint16_t var15 = 0;

CY_ISR (my_isr) {
    var1++;
    if (var1 == 1) {
        var1 = 0;
        LED1_Write(!LED1_Read());
    }
    
    var10++;
    if (var10 == 10) {
        var10 = 0;
        LED2_Write(!LED2_Read());
    }
    
    var15++;
    if (var15 == 15) {
        var15 = 0;
        LED3_Write(!LED3_Read());
    }
    
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    LED1_Write(0);
    LED2_Write(0);
    LED3_Write(0);
    PWM_1_Start();
    isr_1_StartEx(my_isr);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}
```

**— END**