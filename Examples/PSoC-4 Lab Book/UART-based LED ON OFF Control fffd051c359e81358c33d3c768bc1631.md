# UART-based LED ON/OFF Control

> Python program that transfers two bytes of data to PSoC. At PSoC, turns ON/OFF LED-1 based on the content in byte-1. Turns ON/OFF LED-2 based on the content in byte-2
> 

# Schematic

![Untitled](Untitled%2016.png)

                                                                                                                                   Overview of Schematic

                                                                                                 

![Untitled](Untitled%2017.png)

                                                                                                                          UART CONFIGURATIONS

![Untitled](Untitled%2018.png)

                                                                                                                        UART ADVANCED CONFIGURATION

![Untitled](Untitled%2019.png)

![Untitled](Untitled%2020.png)

                               

![Untitled](Untitled%2021.png)

![Untitled](Untitled%2022.png)

![Untitled](Untitled%2023.png)

# Firmware (Python)

```python
serialPort= serial.Serial('COM5', baudrate=115200, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE)
for i in range(10):
    # Write to serial port
    serialPort.write(b'\x01')
    serialPort.write(b'\x01')
    time.sleep(1)
    serialPort.write(b'\x00')
    serialPort.write(b'\x00')
    time.sleep(1)
    
    print("looping")
serialPort.close()
```

# Firmware (PSoC)

```c
#include "project.h"

CY_ISR(my_isr)
{  // CyDelay(100);
    uint8_t var,var2;
    var = UART_1_UartGetByte();
    var2= UART_1_UartGetByte();
    
    if(var == 0x01)
    {
        Pin_LED_Write(1);
    }

    else
    {
    Pin_LED_Write(0);
    }
    if(var2 == 0x01)
    {
        Pin_LED2_Write(0);
    }

    else
    {
    Pin_LED2_Write(1);
    }
    
// Clear the interrupt
    UART_1_SpiUartClearRxBuffer();
    UART_1_ClearRxInterruptSource(UART_1_INTR_RX_ALL);
}
int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    /* Link to ISR */
    isr_1_StartEx(my_isr);

    for(;;)
    {
        /* Place your application code here. */
    }
}
```

**— END**