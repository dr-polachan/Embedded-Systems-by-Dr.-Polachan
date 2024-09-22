# PWM Freq and Duty-Cycle Control

> Control the PWM frequency and duty-cycle from the code. Freeze the PWM when a switch is pressed.
> 

# Schematic

                                                                                                                                

![Untitled](Untitled%2031.png)

![Untitled](Untitled%2032.png)

![Untitled](Untitled%2033.png)

![Untitled](Untitled%2034.png)

![Untitled](Untitled%2035.png)

![Untitled](Untitled%2036.png)

![Untitled](Untitled%2037.png)

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