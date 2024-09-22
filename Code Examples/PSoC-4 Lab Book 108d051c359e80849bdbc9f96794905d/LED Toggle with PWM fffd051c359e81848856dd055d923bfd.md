# LED Toggle with PWM

We are given three LEDs, each of them toggling at the rate of 1 sec, 1.5 sec, 1.75 sec respectively.

The clock frequency is set at 1 KHz and the respective Period and Compare values of the PWMs are as follows

- PWM_1 : Period = 2000   Compare = 1000
- PWM_2 : Period = 3000   Compare = 1500
- PWM_3 : Period = 3500   Compare = 1750

We have assumed a duty cycle of 50 % and the time with which the LED is ON is calculated using $T_{ON} = \frac{Compare}{Freq_{CK}}$. 

# Schematic

![lab1.png](LED%20Toggle%20with%20PWM%20fffd051c359e81848856dd055d923bfd/lab1.png)

## Pin Placement

![lab2.png](LED%20Toggle%20with%20PWM%20fffd051c359e81848856dd055d923bfd/lab2.png)

## Drive Mode

![lab3.png](LED%20Toggle%20with%20PWM%20fffd051c359e81848856dd055d923bfd/lab3.png)

**Note:** All the Pins will have the same configuration as illustrated above.

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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();
    PWM_2_Start();
    PWM_3_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

**— END**