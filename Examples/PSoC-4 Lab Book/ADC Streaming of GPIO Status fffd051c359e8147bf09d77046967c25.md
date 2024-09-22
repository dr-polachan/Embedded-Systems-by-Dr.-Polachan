# ADC Streaming of GPIO Status

Stream ADC corresponding to the GPIO pin status. Perform the ADC conversion every 1sec (use PWM to generate the delay). Stream GPIO drive status.

# Creator Schematic

![Screenshot_20230427_162700.png](Screenshot_20230427_162700.png)

# Component Configurations

                                             PWM Settings: (Adapt according to input clock)

![Screenshot_20230427_162748.png](Screenshot_20230427_162748.png)

Toggle Button Interrupt settings: (Digital Input with no Hardware Connection, Rising(Or Falling) Edge Interrupt with Dedicated Interrupt)

![Screenshot_20230427_163000.png](Screenshot_20230427_163000.png)

![Screenshot_20230427_162839.png](Screenshot_20230427_162839.png)

SAR ADC Settings: (Set Vref to VDDA, Channels to 1, Mode of said channel to Single)

![Screenshot_20230427_163037.png](Screenshot_20230427_163037.png)

![Screenshot_20230427_163116.png](Screenshot_20230427_163116.png)

UART Config:

![Screenshot_20230427_163757.png](Screenshot_20230427_163757.png)

# Pin Configurations

![Screenshot_20230427_163854.png](Screenshot_20230427_163854.png)

# Firmware

```c
#include "project.h"

uint16_t result; 
uint8_t sendData[2];

CY_ISR (Delay_ISR_Handler){
ADC_SAR_Seq_1_StartConvert();
        if(ADC_SAR_Seq_1_IsEndConversion(ADC_SAR_Seq_1_WAIT_FOR_RESULT)==1)
        {
            result=ADC_SAR_Seq_1_GetResult16(0);          
        }
        
       sendData[0]=(result>>8) & 0x00FF;
       sendData[1]=(result) & 0x00FF;
        UART_1_UartPutChar(0xFF);
        UART_1_UartPutChar(0xAA);
        UART_1_UartPutChar(sendData[0]);
        UART_1_UartPutChar(sendData[1]);
        UART_1_UartPutChar(0xFF);
        UART_1_UartPutChar(0xFF);
        PWM_1_ClearInterrupt(PWM_1_INTR_MASK_TC);
}

int flag = 0;
CY_ISR( Pin_Switch_Handler )
{
    if(flag==0)
    {
        UART_1_Stop();
        flag=1;
    }
    else
    {
        UART_1_Start();
        flag=0;
    }
    LEDPIN_Write(~LEDPIN_Read());
    ButtonPIN_ClearInterrupt();
    
}

int main(void)
{
    
    CyGlobalIntEnable;
    isr_1_StartEx(Pin_Switch_Handler);
    
    UART_1_Start(); flag=0;
    ADC_SAR_Seq_1_Start();
    delayISR_StartEx(Delay_ISR_Handler);
    PWM_1_Start();

    for(;;){}
}
```

**— END**