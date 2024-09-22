# LED toggle with switch control

Toggle LED-1, 2 and 3 at 2sec, 5sec and 10sec respectively. Use a PWM to generate the delay. Use a switch to Freeze/Un-Freeze toggling.

# Creator Schematic

![Untitled](LED%20toggle%20with%20switch%20control%20fffd051c359e81f990edc18e2f2f005d/Untitled.png)

# Component Configurations

![Untitled](LED%20toggle%20with%20switch%20control%20fffd051c359e81f990edc18e2f2f005d/Untitled%201.png)

![Untitled](LED%20toggle%20with%20switch%20control%20fffd051c359e81f990edc18e2f2f005d/Untitled%202.png)

![Untitled](LED%20toggle%20with%20switch%20control%20fffd051c359e81f990edc18e2f2f005d/Untitled%203.png)

# Pin Configurations

![Untitled](LED%20toggle%20with%20switch%20control%20fffd051c359e81f990edc18e2f2f005d/Untitled%204.png)

# Firmware

```c
#include "project.h"

static uint16_t var_2 = 0, var_5 = 0, var_10 = 0;
static uint8_t flag = 0;

CY_ISR(isrbutton)
{
    var_2++;
    var_5++;
    var_10++;
    
    if(var_2 == 2)
    {
        var_2=0;
        Pin_1_Write(~Pin_1_Read());
    }
    
    if(var_5 == 5)
    {
        var_5=0;
        Pin_2_Write(~Pin_2_Read());
    }
    
    if(var_10 == 10)
    {
        var_10=0;
        Pin_3_Write(~Pin_3_Read());
    }
    
    PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
}
    
    
CY_ISR(isrbutton1)
{
    if (flag==0)
    {
        PWM_1_Stop();
        flag = 1;
        Pin_4_ClearInterrupt();
    }
    else
    {
        PWM_1_Start();
        flag = 0;
        Pin_4_ClearInterrupt();
    }
    
}

int main(void)
{
    CyGlobalIntEnable;
    
    PWM_1_Start();
    isr_1_StartEx(isrbutton);
    isr_2_StartEx(isrbutton1);
    
    for(;;)
    {
        
    }
    
}
```

**— END**