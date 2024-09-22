# LED ON/OFF control using switch

> For the first 30s after power-up, when a button is pressed, toggle an LED. Stop LED toggling after 30s.
> 

# Schematic

Paste screenshots of the PSoC-Creator Schematic and every component settings below.

![Untitled](Untitled%208.png)

![Untitled](Untitled%209.png)

![Untitled](Untitled%2010.png)

![Untitled](Untitled%2011.png)

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
CY_ISR_PROTO(my_isr_code);
CY_ISR_PROTO(my_isr_code2);
int flag=0;
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    //Pin_1_Write(1);
    PWM_1_Start();
    isr_1_StartEx(my_isr_code);
    isr_2_StartEx(my_isr_code2);
    
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}
CY_ISR(my_isr_code)
{
    flag=1;
  //  Pin_1_Write(~Pin_1_Read());
   // PWM_1_Stop();
}
CY_ISR(my_isr_code2)
{
    if(flag==0)
    {
    Pin_3_Write(~Pin_3_Read());
    Pin_2_ClearInterrupt();
    }
}
/* [] END OF FILE */
```

**— END**