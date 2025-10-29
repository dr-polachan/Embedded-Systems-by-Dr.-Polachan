/*
 ============================================================================
 Name        : FreeRTOS Project
 Author      : Dr. Kurian Polachan
 Description : Example project demonstrating task synchronization using a binary
               semaphore in FreeRTOS. The UART task produces a signal once every
               second by giving a semaphore, while the LED task waits (takes)
               that semaphore to toggle an LED. This ensures one LED toggle per
               "Live n" message, illustrating task-to-task synchronization.

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

static SemaphoreHandle_t led_sem = NULL;  // Binary semaphore handle

void led_task()
{
    while(1)
    {   
        /* Block indefinitely until semaphore is given */
        if (xSemaphoreTake(led_sem, portMAX_DELAY) == pdTRUE)
        {
            uint8 led_state = !led_Read();  
            led_Write(led_state);              
        }        
        
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
                
        xSemaphoreGive(led_sem);

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
    
    led_sem = xSemaphoreCreateBinary();

    
    xTaskCreate(led_task, "LED_Task", 200, NULL, 5, NULL);
    xTaskCreate(uart_task, "UART_Task", 200, NULL, 5, NULL);
    
    vTaskStartScheduler();

    while(1)
    {
    }
}