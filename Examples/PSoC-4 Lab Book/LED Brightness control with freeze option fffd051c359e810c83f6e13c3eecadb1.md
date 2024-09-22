# LED Brightness control with freeze option

> Upon Power-Up, increase the brightness of the LED from 0 to 100% over a period of 30seconds. Within 30 seconds, if you press a GPIO, freeze the LED brightness
> 

# Schematic

![Untitled](Untitled%2012.png)

![Untitled](Untitled%2013.png)

![Untitled](Untitled%2014.png)

![Untitled](Untitled%2015.png)

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

uint8 flag =0;
CY_ISR(my_isr_code){
    flag = 1;
    L_SWITCH_ClearInterrupt();
}
    
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    isr_1_StartEx(my_isr_code);
    uint16 c = 0;
    PWM_1_Start();
    PWM_1_Stop();
    PWM_1_WritePeriod(30000);
    
    PWM_1_WriteCompare(0);
    PWM_1_Start();
    //while(1);
    while(c <= 30000u){
        
        c = c + 10000u;
        CyDelay(5000);
        if(flag == 0){
        PWM_1_Stop();
        PWM_1_WriteCompare(c);
        PWM_1_Start();
        }
    }
                
    
       
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

**— END**