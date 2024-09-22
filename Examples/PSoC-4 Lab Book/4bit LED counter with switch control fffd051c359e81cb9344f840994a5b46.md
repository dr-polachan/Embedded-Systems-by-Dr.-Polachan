# 4bit LED counter with switch control

# Creator Schematic

                                              

![Untitled](Untitled%2071.png)

# Component Configurations

![Untitled](Untitled%2072.png)

![Untitled](Untitled%2073.png)

                                             

# Pin Configurations

![Untitled](Untitled%2074.png)

# Firmware

```c
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    uint8_t stage1 = 1;
    uint8_t stage2 = 1;
    uint8_t count = 0;
    uint8_t leds_on = 0;
    
    LED_1_Write(1);
                LED_2_Write(1);
                LED_3_Write(1);
                LED_4_Write(1);
    

    for (;;)
    {
        stage1 = SW_Read();
        CyDelay(100);
        stage2 = SW_Read();

        if (stage1 == 0 && stage2 == 1)
        {
            count++; // Increment count on switch press

            if (count > 16) // Reset count when it exceeds 16
            {
                count = 0;
                leds_on = 0;
            }

            if (count == 1)
            {
                leds_on = 1;
                LED_1_Write(0);
            }
            else if (count == 2)
            {
                LED_1_Write(1);
                LED_2_Write(0);
            }
            else if (count == 3)
            {
                LED_2_Write(0);
                LED_1_Write(0);
                LED_3_Write(1);
                LED_4_Write(1);
            }
            else if (count == 4)
            {
                LED_1_Write(1);
                LED_2_Write(1);
                LED_3_Write(0);
                LED_4_Write(1);
            }
            else if (count == 5)
            {
                LED_3_Write(0);
                LED_1_Write(0);
                LED_2_Write(1);
                LED_4_Write(1);
            }
            else if (count == 6)
            {
                LED_2_Write(0);
                LED_3_Write(0);
                LED_1_Write(1);
                LED_4_Write(1);
            }
            else if (count == 7)
            {
                LED_1_Write(0);
                LED_2_Write(0);
                LED_3_Write(0);
                LED_4_Write(1);
            }
            else if (count == 8)
            {
                LED_4_Write(0);
                LED_1_Write(1);
                LED_2_Write(1);
                LED_3_Write(1);
            }
            else if (count == 9)
            {
                LED_1_Write(0);
                LED_2_Write(1);
                LED_3_Write(1);
                LED_4_Write(0);
            }
            else if (count == 10)
            {
                LED_1_Write(1);
                LED_2_Write(0);
                LED_3_Write(1);
                LED_4_Write(0);
            }
            else if (count == 11)
            {
                 LED_1_Write(0);
                LED_2_Write(0);
                LED_3_Write(1);
                LED_4_Write(0);
            }
            else if (count == 12)
            {
                 LED_1_Write(1);
                LED_2_Write(1);
                LED_3_Write(0);
                LED_4_Write(0);
            }
            else if (count == 13)
            {
                 LED_1_Write(0);
                LED_2_Write(1);
                LED_3_Write(0);
                LED_4_Write(0);
            }
            else if (count == 14)
            {
                 LED_1_Write(1);
                LED_2_Write(0);
                LED_3_Write(0);
                LED_4_Write(0);
            }
            else if (count == 15)
            {
                 LED_1_Write(0);
                LED_2_Write(0);
                LED_3_Write(0);
                LED_4_Write(0);
            }
            else // count == 0 or count == 16
            {
                LED_1_Write(1);
                LED_2_Write(1);
                LED_3_Write(1);
                LED_4_Write(1);
            }

            stage1 = stage2 = 0; // Reset switch state
            CyDelay(10); // Wait for
            
        }
    }
}
```

**— END**