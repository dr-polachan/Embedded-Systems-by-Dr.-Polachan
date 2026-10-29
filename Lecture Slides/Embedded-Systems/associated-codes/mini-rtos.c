#include "project.h"
#include <stdint.h>

/* System tick: 1 tick = 10 ms */
volatile uint8_t system_tick = 0;

/* Last execution tick for each task */
uint8_t task1_last_run = 0;
uint8_t task2_last_run = 0;

/* Timer ISR: executes every 10 ms */
CY_ISR(TickTimer_ISR)
{
    (void)TickTimer_ReadStatusRegister();
    system_tick++;
}

/* Task 1: Toggle LED1 */
void Task1(void)
{
    LED1_Write(!LED1_Read());
}

/* Task 2: Toggle LED2 */
void Task2(void)
{
    LED2_Write(!LED2_Read());
}

/* Simple Mini-RTOS scheduler */
void Scheduler(void)
{
    /* Run Task 1 every 500 ms */
    if ((uint8_t)(system_tick - task1_last_run) >= 50u)
    {
        task1_last_run = system_tick;
        Task1();
    }

    /* Run Task 2 every 200 ms */
    if ((uint8_t)(system_tick - task2_last_run) >= 20u)
    {
        task2_last_run = system_tick;
        Task2();
    }
}

int main(void)
{
    /* Initialize LEDs */
    LED1_Write(0);
    LED2_Write(0);

    /* Start timer and interrupt */
    TickTimer_Start();
    isr_Tick_StartEx(TickTimer_ISR);

    CyGlobalIntEnable;

    /* Run the scheduler continuously */
    for (;;)
    {
        Scheduler();
    }
}
