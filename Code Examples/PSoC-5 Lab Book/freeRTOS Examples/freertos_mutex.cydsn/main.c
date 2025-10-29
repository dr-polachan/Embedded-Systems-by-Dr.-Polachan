/*
 ============================================================================
 Name        : FreeRTOS Project
 Author      : Dr. Kurian Polachan
 Description : Example project demonstrating mutual exclusion (mutex) in FreeRTOS.
               Two concurrent tasks (UART and LED) share access to the UART port.
               A mutex ensures that only one task can write to UART at a time,
               preventing interleaved or corrupted output.

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

static SemaphoreHandle_t uart_mutex = NULL; /* mutex to protect UART */

void led_task()
{
    char msg[50];
    uint16 led_count = 1;

    while(1)
    {   
        uint8 led_state = !led_Read();  
        led_Write(led_state);
        
        if (xSemaphoreTake(uart_mutex, pdMS_TO_TICKS(100)) == pdTRUE)
        {
            sprintf(msg, "LED toggled %d\r\n", led_count);
            UART_PutString(msg);
            xSemaphoreGive(uart_mutex);
        }
        
        vTaskDelay(pdMS_TO_TICKS(500));
        led_count++;
    }
}

void uart_task()
{
    uint16 counter = 1;    
    char msg[50];            

    while (1)
    {               
        if (xSemaphoreTake(uart_mutex, pdMS_TO_TICKS(100)) == pdTRUE)
        {
            sprintf(msg, "Live %d\r\n", counter);
            UART_PutString(msg);  
            xSemaphoreGive(uart_mutex);
        }
        
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
    
    uart_mutex = xSemaphoreCreateMutex();
    
    xTaskCreate(led_task, "LED_Task", 200, NULL, 5, NULL);
    xTaskCreate(uart_task, "UART_Task", 200, NULL, 5, NULL);
    
    vTaskStartScheduler();

    while(1)
    {
    }
}