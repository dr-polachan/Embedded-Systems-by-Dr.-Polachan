# Binary Counter with LED Display

> Increment the LED status from 000→001…111 by pressing a switch.
> 

# Schematic

![schem.png](Binary%20Counter%20with%20LED%20Display%20fffd051c359e81eb94e6ff47f41e3784/schem.png)

                                                                                                                                

![1.png](Binary%20Counter%20with%20LED%20Display%20fffd051c359e81eb94e6ff47f41e3784/1.png)

![2.png](Binary%20Counter%20with%20LED%20Display%20fffd051c359e81eb94e6ff47f41e3784/2.png)

![3.png](Binary%20Counter%20with%20LED%20Display%20fffd051c359e81eb94e6ff47f41e3784/3.png)

![4.png](Binary%20Counter%20with%20LED%20Display%20fffd051c359e81eb94e6ff47f41e3784/4.png)

# Firmware (PSoC)

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

int var = 0;
CY_ISR(arrg)
{
    var++;
    if(var>7)
    var = 0;
    Pin_in_ClearInterrupt();
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    isr_1_StartEx(arrg);    
    
    while(1)
    {
       
        
    Pin_1_Write((var>>0)&0X01);    
    Pin_2_Write((var>>1)&0X01);  
    Pin_3_Write((var>>2)&0X01);  
       
    }
}

/* [] END OF FILE */
```

**— END**