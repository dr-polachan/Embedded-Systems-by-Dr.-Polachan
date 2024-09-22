# Toggle LEDs at different frequencies using PWM

> Toggle LED-1 and LED-2 at 1s, 1.5s using PWM.
> 

# Schematic

                                                                                                                         

![Untitled](Toggle%20LEDs%20at%20different%20frequencies%20using%20PWM%20fffd051c359e81b4813bf7613df4be20/Untitled.png)

![Untitled](Toggle%20LEDs%20at%20different%20frequencies%20using%20PWM%20fffd051c359e81b4813bf7613df4be20/Untitled%201.png)

![Untitled](Toggle%20LEDs%20at%20different%20frequencies%20using%20PWM%20fffd051c359e81b4813bf7613df4be20/Untitled%202.png)

![Untitled](Toggle%20LEDs%20at%20different%20frequencies%20using%20PWM%20fffd051c359e81b4813bf7613df4be20/Untitled%203.png)

# PSoC Firmware

```c
#include "project.h"
int c = 0;
CY_ISR (my_isr_PWM)
{
  
    if(PWM_1_ReadCounter()%500 == 0)
    c ++;
    if( c % 2 == 0 && c % 4 != 0)
    LED_1_Write(1);
    else if ( c % 4 == 0)
    LED_1_Write(0);
    if(c%3 == 0 && c % 6 != 0)
    LED_2_Write(1);
    else if(c%6 == 0)
    LED_2_Write(0);
    
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    //isr_2_StartEx(my_isr_Button);
    
    LED_2_Write(0);
    LED_1_Write(0);
    LED_3_Write(0);
    PWM_1_Start();
   
    
    isr_1_StartEx(my_isr_PWM);
    isr_3_StartEx(my_isr_PWM);
    for(;;)
    {
        /* Place your application code here. */
        
    }
}

/* [] END OF FILE */
```

**— END**