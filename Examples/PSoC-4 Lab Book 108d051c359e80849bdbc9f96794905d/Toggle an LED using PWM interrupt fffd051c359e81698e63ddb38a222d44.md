# Toggle an LED using PWM interrupt

# Schematic

![Untitled](Turn%20ON%20an%20LED%2030s%20after%20power-up%20fffd051c359e8193a9b6d5f4b36280c8/Untitled.png)

PWM-Settings

![Untitled](Toggle%20an%20LED%20using%20PWM%20interrupt%20fffd051c359e81698e63ddb38a222d44/Untitled.png)

Pin Settings

![Untitled](Turn%20ON%20an%20LED%2030s%20after%20power-up%20fffd051c359e8193a9b6d5f4b36280c8/Untitled%202.png)

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