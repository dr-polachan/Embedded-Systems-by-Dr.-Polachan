/*
 ============================================================================
 Name        : FreeRTOS Example Project
 Author      : Dr. Kurian Polachan
 Description : Example project demonstrating basic FreeRTOS multitasking using
               UART and LED tasks. The LED toggles periodically, and the UART
               task sends a "Live n" message every second.
               
 Acknowledgment:
 This code builds upon and makes use of the structure, conventions, and examples
 from the open-source project:
     https://github.com/Karthik23tala/Embedded-C-Lab-Book
 maintained by Karthik T. and contributors.

 License     : For educational and research use. Attribution required.
 ============================================================================
*/

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

void led_task()
{
    while(1)
    {        
        uint8 led_state = !led_Read();  
        led_Write(led_state);              
        vTaskDelay(250); 
    }
}

void uart_task()
{
    uint16 counter = 1;    
    char msg[32];            

    while (1)
    {
        sprintf(msg, "Live %d\r\n", counter);
        UART_PutString(msg);

        counter++; 

        vTaskDelay(pdMS_TO_TICKS(1000)); 
    }
}


int main(void)
{
    CyGlobalIntEnable;
        
    UART_Start();
    UART_ClearTxBuffer();
    
    FreeRTOS_Start();
    
    xTaskCreate(led_task, "LED_Task", 200, NULL, 5, NULL);
    xTaskCreate(uart_task, "UART_Task", 200, NULL, 5, NULL);
    
    vTaskStartScheduler();

    while(1)
    {
    }
}