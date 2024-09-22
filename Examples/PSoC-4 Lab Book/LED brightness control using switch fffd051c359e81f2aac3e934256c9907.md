# LED brightness control using switch

> Control LED intensity via switch. Intensity should increase from 0 to 100% in 10 switch presses.
> 

# Schematic

                                                                                                                         

![Untitled](Untitled%2062.png)

![Untitled](Untitled%2063.png)

![Untitled](Untitled%2064.png)

![Untitled](Untitled%2065.png)

![Untitled](Untitled%2066.png)

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

uint8 var=0;
CY_ISR(isr){
    
    
    var=var+1;
    if(var>8){
        var=0;
    }
    L_SWITCH_ClearInterrupt();
    
    PWM_1_Start();
    PWM_1_WritePeriod(10);
    PWM_1_WriteCompare(var);
   

}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(isr);
    
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

**— END**