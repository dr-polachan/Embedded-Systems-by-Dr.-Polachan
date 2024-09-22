# Toggle an LED using PWM interrupt

# Schematic

![Untitled](Untitled%204.png)

PWM-Settings

![Untitled](Untitled%207.png)

Pin Settings

![Untitled](Untitled%206.png)

# Firmware

```c
#include "project.h"

CY_ISR (my_isr)
{
		// toggline the LED
    Pin_LED_Write(~Pin_LED_Read());    

		// clearing the PWM interrupt
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    PWM_1_Start();
    
    isr_1_StartEx(my_isr);

    for(;;)
    {
        /* Place your application code here. */
    }
}
```

**—END**