# UART-based bootloader

> UART bootloader and bootloadable projects with PSoC-4
> 

# Schematic (Bootloader)

![bootloader.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloader.png)

![uart_1.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/uart_1.png)

![uart_2.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/uart_2.png)

![bootloadersch.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloadersch.png)

![bootloaderpins.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloaderpins.png)

# Schematic (Bootloadable)

![bootloadable_2.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloadable_2.png)

![clock.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/clock.png)

![pwm.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/pwm.png)

![bootloadableschem.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloadableschem.png)

![bootloadable_pins.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloadable_pins.png)

# Firmware (Bootloader)

```c
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    Bootloader_1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

# Firmware (Bootloadable)

```c
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    PWM_1_Start();

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

# Bootloading Method

Build and Program Bootloader project. This creates a bootloader program in PSOC-4. Then build the bootloadable project and program it by using bootloader host. 

![bootloaderhost.png](UART-based%20bootloader%20fffd051c359e81fd8203e41e670e41e0/bootloaderhost.png)

**— END**