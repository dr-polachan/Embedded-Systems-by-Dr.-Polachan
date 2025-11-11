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

static QueueHandle_t adcQueue;

typedef struct {
    uint16 index;     // sample index
    uint16 sample;    // 12-bit ADC sample (dummy)
} adc_msg_t;


void adc_task()
{
    adc_msg_t msg_adc;
    uint16 counter=0;
    
    while(1)
    {
        msg_adc.index = counter; counter++;
        msg_adc.sample = (uint16_t)(rand() & 0x0FFF);

                
        xQueueSend(adcQueue, &msg_adc, portMAX_DELAY);
        
        vTaskDelay(pdMS_TO_TICKS(100));     
    }
}

void uart_task()
{
    while(1)
    {
        adc_msg_t msg_rcv;
        char str[100];

        if (xQueueReceive(adcQueue, &msg_rcv, portMAX_DELAY) == pdTRUE)
        {
            sprintf(str, "ADC %d %d\r\n", msg_rcv.index, msg_rcv.sample);
            UART_PutString(str);  
        }         
        
        vTaskDelay(pdMS_TO_TICKS(100)); 
    }    
}


int main(void)
{
    CyGlobalIntEnable;
        
    UART_Start();
    UART_ClearTxBuffer();
    
    FreeRTOS_Start();
    
    /* Create queue to hold up to 32 adc_msg_t items */
    adcQueue = xQueueCreate(32, sizeof(adc_msg_t));
    
    xTaskCreate(adc_task, "ADC Task", 200, NULL, 5, NULL);
    xTaskCreate(uart_task, "UART_Task", 200, NULL, 5, NULL);
    
    vTaskStartScheduler();

    while(1)
    {
    }
}