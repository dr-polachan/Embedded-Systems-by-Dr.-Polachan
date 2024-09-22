# LED brightness control using IDAC

# Creator Schematic

![Screenshot (47).png](LED%20brightness%20control%20using%20IDAC%20fffd051c359e818aa30ed97787ce978f/Screenshot_(47).png)

# Component Configurations

                                             

![Screenshot (43).png](LED%20brightness%20control%20using%20IDAC%20fffd051c359e818aa30ed97787ce978f/Screenshot_(43).png)

![Screenshot (48).png](LED%20brightness%20control%20using%20IDAC%20fffd051c359e818aa30ed97787ce978f/Screenshot_(48).png)

[https://www.notion.so](https://www.notion.so)

# Pin Configurations

![Screenshot (44).png](LED%20brightness%20control%20using%20IDAC%20fffd051c359e818aa30ed97787ce978f/Screenshot_(44).png)

# Firmware

```c
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
 IDAC7_1_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
        
   for(int i=0;i<=100;i++){
   IDAC7_1_SetValue(i);
   CyDelay(50);
   IDAC7_1_SetPolarity(IDAC7_1_POL_SOURCE);
   IDAC7_1_SetRange(IDAC7_1_RNG_609_6UA);
}
    }
}
```

**— END**