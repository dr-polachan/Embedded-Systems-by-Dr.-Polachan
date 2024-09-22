# ADC Streaming via UART

> Control ADC Streaming via UART using a switch. In this project we are taking in a digital input and performing ADC on this signal, this output signal is to be transmitted over a UART Channel. But this transmission should occur only when the switch is pressed. This is implemented using the steps shown below…
> 

# Schematic

![Untitled](ADC%20Streaming%20via%20UART%20fffd051c359e817d823fe02528e1fcb7/Untitled.png)

                                        

![Untitled](ADC%20Streaming%20via%20UART%20fffd051c359e817d823fe02528e1fcb7/Untitled%201.png)

                                                                         

# PSoC Firmware

```c
#include "project.h"

uint16_t result; 
uint8_t sendData[2];

int flag = 0;
CY_ISR( Pin_Switch_Handler )
{
    //toggling the LED
    
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
    Pin_LED_Write(~Pin_LED_Read());
    //if(Pin_LED_Read() == 1)
    //    UART_1_Start();
    //else
    //    UART_1_Stop();
        
        
    //clear the pin interrupt
    Pin_Switch_ClearInterrupt();
    
}

int main(void)
{
    
    CyGlobalIntEnable;  //Enable global interrupts. 
    isr_1_StartEx(Pin_Switch_Handler);
    
    UART_1_Start(); flag=0;
    ADC_Start();
  
    // Place your initialization/startup code here (e.g. MyInst_Start()) 

    while(1)
    {
       //  Place your application code here. 
        ADC_StartConvert();
        if(ADC_IsEndConversion(ADC_WAIT_FOR_RESULT)==1)
        {
            result=ADC_GetResult16(0);          
        }
        
       sendData[0]=(result>>8) & 0x00FF;
       sendData[1]=(result) & 0x00FF;
        
        //for(int j=0;j<2;j++)
        UART_1_UartPutChar(0xFF);
        UART_1_UartPutChar(0xAA);
        UART_1_UartPutChar(sendData[0]);
        UART_1_UartPutChar(sendData[1]);
        UART_1_UartPutChar(0xFF);
        UART_1_UartPutChar(0xFF);      
    }
}
```

# Bridge Control Panel

![Untitled](ADC%20Streaming%20via%20UART%20fffd051c359e817d823fe02528e1fcb7/Untitled%202.png)

```csharp
RX8 [H = FF AA] x x [T= FF FF]
```

**— END**