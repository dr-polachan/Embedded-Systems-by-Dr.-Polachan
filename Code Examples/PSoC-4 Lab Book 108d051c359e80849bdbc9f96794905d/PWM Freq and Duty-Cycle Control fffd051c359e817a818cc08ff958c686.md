# PWM Freq and Duty-Cycle Control

> Control the PWM frequency and duty-cycle from the code. Freeze the PWM when a switch is pressed.
> 

# Schematic

                                                                                                                                

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled.png)

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled%201.png)

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled%202.png)

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled%203.png)

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled%204.png)

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled%205.png)

![Untitled](PWM%20Freq%20and%20Duty-Cycle%20Control%20fffd051c359e817a818cc08ff958c686/Untitled%206.png)

# Firmware (PSoC)

```c
#include "project.h"
CY_ISR(isrB)
    {
       
        PWM_1_Stop();
        
     }
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();
    PWM_1_WriteCompare(250);
    PWM_1_WriteCounter(1000);
    isr_1_StartEx(isrB);
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

**— END**