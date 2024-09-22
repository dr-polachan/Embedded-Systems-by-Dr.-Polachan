# LED control with double tap

Turn ON an LED if a button is pressed two times within an interval of 1 seconds.

# Creator Schematic

![2023-05-01 11_15_06-MT2022152 - PSoC Creator 4.4  [C__..._PSoC Creator_MT2022152_Lab Exam.cydsn_TopD.png](2023-05-01_11_15_06-MT2022152_-_PSoC_Creator_4.4__C__..._PSoC_Creator_MT2022152_Lab_Exam.cydsn_TopD.png)

# Component Configurations

                                             

![2023-05-01 11_19_56-MT2022152 - PSoC Creator 4.4  [C__..._PSoC Creator_MT2022152_Lab Exam.cydsn_TopD.png](2023-05-01_11_19_56-MT2022152_-_PSoC_Creator_4.4__C__..._PSoC_Creator_MT2022152_Lab_Exam.cydsn_TopD.png)

# Pin Configurations

![2023-05-01 11_16_04-MT2022152 - PSoC Creator 4.4  [C__..._sanka_Documents_PSoC Creator_MT2022152_Lab.png](2023-05-01_11_16_04-MT2022152_-_PSoC_Creator_4.4__C__..._sanka_Documents_PSoC_Creator_MT2022152_Lab.png)

# Firmware

```c
#include "project.h"

uint32_t flag = 0;

CY_ISR(button_isr_handler)
{
    if (flag == 1){
        Pin_1_Write(0);
        PWM_Stop();
    }
    if (flag == 0){
        flag = 1;
        PWM_Start();
    }
    
    Pin_Button_ClearInterrupt(); /* Clear button interrupt */
}

CY_ISR(pwm_isr_handler)
{
    flag = 0;
    PWM_Stop();
    PWM_ClearInterrupt(PWM_INTR_MASK_TC); /* Clear PWM interrupt */
}

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    
    isr_Button_StartEx(button_isr_handler);
    isr_Button_ClearPending();
    
    isr_PWM_StartEx(pwm_isr_handler);
    isr_PWM_ClearPending();
    
    Pin_1_Write(1);
    
    for(;;)
    {
        /* Place your application code here. */
    }
}

/* [] END OF FILE */
```

**— END**