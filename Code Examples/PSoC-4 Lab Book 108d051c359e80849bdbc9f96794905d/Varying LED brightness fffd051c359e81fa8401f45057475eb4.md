# Varying LED brightness

Vary LED brightness from 0 to 100% in steps of 10%. The step interval should be 1second. The interval should be generated using PWM. Do not use software delay.

# Creator Schematic

![Screenshot (10).png](Varying%20LED%20brightness%20fffd051c359e81fa8401f45057475eb4/Screenshot_(10).png)

# Component Configurations

                                             

![Screenshot (11).png](Varying%20LED%20brightness%20fffd051c359e81fa8401f45057475eb4/Screenshot_(11).png)

# Pin Configurations

![Screenshot (12).png](Varying%20LED%20brightness%20fffd051c359e81fa8401f45057475eb4/Screenshot_(12).png)

# Firmware

```c
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();
    uint16 PWMcompare = 1;

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        PWMcompare = PWMcompare +100 ;
        if(PWMcompare >=1000)
            PWMcompare =1;
        PWM_1_WriteCompare(PWMcompare);
        
        CyDelay(1000);
    }
        
    
}

/* [] END OF FILE */
```

**— END**