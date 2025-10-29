# FreeRTOS - LED Toggle

# Objective

To toggle the LED on the PSoC 5 board but through the `xTaskCreate()` function in FreeRTOS and also display the respective string through UART on Tera Term.

# Working

In this lab exercise, one task named `led_task()` is created using `xTaskCreate()` function in which the LED pin is toggled infinitely under the `while(1)` super loop. Also within this while loop, there is an if condition defined on led state which prints the string as per the appropriate state of the LED i.e., LED ON or LED OFF.

# PSoC-Schematic

<img width="865" height="516" alt="image" src="https://github.com/user-attachments/assets/7b1b7d21-5a90-425a-87af-fd6405667c15" />

<img width="900" height="693" alt="image" src="https://github.com/user-attachments/assets/3ee049ea-d1b3-466d-94d4-b8d28f58fcd5" />

<img width="865" height="661" alt="image" src="https://github.com/user-attachments/assets/9369deca-6771-4202-ad30-c92fe5a6a38a" />

# Pin Assignment

<img width="775" height="283" alt="image" src="https://github.com/user-attachments/assets/16e1d9b1-106b-4eb7-9b4d-9c88177b6eaa" />

Here Pin P2[1] is fixed on the PSoC board itself for LED. In case you want to use any external LED or display unit, assign the appropriate GPIO for the same.

# PSoC-Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "project.h"
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"
#include "queue.h"
#include "semphr.h"

extern void FreeRTOS_Start();

void led_task(void *ptr){
    while(1){
        uint8_t led_state = !led_Read();  // Toggle state
        led_Write(led_state);             // Write to LED pin
        if(led_state)
            UART_PutString("LED ON\r\n");
        else
            UART_PutString("LED OFF\r\n");
        vTaskDelay(1000); // Delay 1 second (1000 ticks)
    }
}

int main(void)
{
    CyGlobalIntEnable;
    FreeRTOS_Start();
    UART_Start();
    UART_ClearTxBuffer();
    xTaskCreate(led_task, "LED_UART_Task", 200, NULL, 5, NULL);
    vTaskStartScheduler();

    for(;;) { }
}
```

Note: All the header, C files as well as `FreeRTOS.c` and `FreeRTOSConfig.h` need to be included for all the projects implemented through the FreeRTOS.

# Results (Tera Term)

To view the results in Tera Term, set the baud rate to 115200 bps in Tera Term -> Serial -> Serial Port -> Speed.

Note: Change the baud rate to the same used in the schematic for every lab wherever UART component is used in the Top Design.

<img width="530" height="555" alt="image" src="https://github.com/user-attachments/assets/af22e164-89a3-44bd-b7f9-14b4e2e9b558" />

<img width="412" height="251" alt="image" src="https://github.com/user-attachments/assets/0a6e9edd-7e30-4159-a065-3d7ea877a1b0" />

**— END**
