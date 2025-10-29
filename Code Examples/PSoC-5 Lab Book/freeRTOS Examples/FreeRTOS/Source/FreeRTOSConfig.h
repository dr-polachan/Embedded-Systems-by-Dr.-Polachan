/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *----------------------------------------------------------*/

#include <project.h> // Keep this for PSoC Creator specific defines if needed elsewhere

//#define SYSTEM_SUPPORT_OS         1 // This line is commented out, which is fine

#define configUSE_PREEMPTION        1
#define configUSE_IDLE_HOOK         0 // Keeping as 0 for simplicity, can enable later if needed
#define configMAX_PRIORITIES        ( 6 )
#define configUSE_TICK_HOOK         0 // Keeping as 0 for simplicity
// IMPORTANT: Set configCPU_CLOCK_HZ to your *actual* CPU clock frequency.
// This is critical for the FreeRTOS tick to work correctly.
// Check your PSoC Creator DWR -> Clocks tab -> CPU Clock value.
// Common values are 48MHz or 67MHz for PSoC 5LP.
// For example, if your CPU clock is 67MHz:
#define configCPU_CLOCK_HZ          ( ( unsigned long ) 24000000 ) // <--- CHECK AND SET THIS ACCURATELY!
// Or if 48MHz:
//#define configCPU_CLOCK_HZ          ( ( unsigned long ) 48000000 )


#define configTICK_RATE_HZ          ( ( TickType_t ) 1000 )
// Increased minimal stack size. 100 words (400 bytes) is often too small.
// Using 256 words (1KB) for Cortex-M3 is a safer starting point.
#define configMINIMAL_STACK_SIZE    ( ( unsigned short ) 256 ) // <--- INCREASED STACK SIZE
#define configTOTAL_HEAP_SIZE       ( ( size_t ) ( 32 * 1024 ) )
#define configMAX_TASK_NAME_LEN     ( 12 )
#define configUSE_TRACE_FACILITY    0
#define configUSE_16_BIT_TICKS      0
#define configIDLE_SHOULD_YIELD     0
#define configUSE_CO_ROUTINES       0
#define configUSE_MUTEXES           1

#define configMAX_CO_ROUTINE_PRIORITIES ( 2 )

#define configUSE_COUNTING_SEMAPHORES   1
#define configUSE_ALTERNATIVE_API       0
#define configCHECK_FOR_STACK_OVERFLOW  2   // Changed to 2 for stack overflow detection during development
#define configUSE_RECURSIVE_MUTEXES     1
#define configQUEUE_REGISTRY_SIZE       10
#define configGENERATE_RUN_TIME_STATS   0
#define configUSE_MALLOC_FAILED_HOOK    1   // Changed to 1 to catch malloc failures (e.g., heap exhaustion)

/* Set the following definitions to 1 to include the API function, or zero
to exclude the API function. */

#define INCLUDE_vTaskPrioritySet            1
#define INCLUDE_uxTaskPriorityGet           1
#define INCLUDE_vTaskDelete                 1
#define INCLUDE_vTaskCleanUpResources       0
#define INCLUDE_vTaskSuspend                1
#define INCLUDE_vTaskDelayUntil             1
#define INCLUDE_vTaskDelay                  1
#define INCLUDE_uxTaskGetStackHighWaterMark 1 // Good to keep this for debugging stack usage
#define INCLUDE_eTaskGetState               1

/**
 * Configure the number of priority bits. This is normally
 * __NVIC_PRIO_BITS but PSoC Creator beta 5 contained a larger
 * value for the priority than is implemented in the hardware so
 * set it here to what the data sheet describes.
 */
#define configPRIO_BITS         3         /* 8 priority levels */

/* The lowest priority. */
#define configKERNEL_INTERRUPT_PRIORITY     ( 7 << (8 - configPRIO_BITS) )

/* Priority 5, or 160 as only the top three bits are implemented. */
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY    ( 5 << (8 - configPRIO_BITS) )

#endif /* FREERTOS_CONFIG_H */