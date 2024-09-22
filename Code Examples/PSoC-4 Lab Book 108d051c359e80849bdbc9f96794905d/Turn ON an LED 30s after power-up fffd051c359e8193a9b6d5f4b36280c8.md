# Turn ON an LED 30s after power-up

# Schematic

![Untitled](Turn%20ON%20an%20LED%2030s%20after%20power-up%20fffd051c359e8193a9b6d5f4b36280c8/Untitled.png)

PWM-Settings

For 30seconds, set the period to 30,000 (note - the clock is 1000Hz).  Enable interrupt on terminal count. 

![Untitled](Turn%20ON%20an%20LED%2030s%20after%20power-up%20fffd051c359e8193a9b6d5f4b36280c8/Untitled%201.png)

Pin Settings

In the pin configuration, select P5.5 as the pin.

![Untitled](Turn%20ON%20an%20LED%2030s%20after%20power-up%20fffd051c359e8193a9b6d5f4b36280c8/Untitled%202.png)

# Firmware

Write “1” to LED to turn it OFF. In the ISR, write “0” to turn the LED ON.  Stop the PWM in the ISR to avoid the PWM from triggering the interrupt again.

```c
#include "project.h"

CY_ISR (my_isr)
{
    Pin_LED_Write(0);        
    PWM_1_Stop();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    Pin_LED_Write(1);
    PWM_1_Start();
    
    isr_1_StartEx(my_isr);
    for(;;)
    {
        /* Place your application code here. */
    }
}
```

**—END**