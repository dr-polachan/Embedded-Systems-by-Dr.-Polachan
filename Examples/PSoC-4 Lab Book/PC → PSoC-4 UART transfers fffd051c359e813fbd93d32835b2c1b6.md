# PC → PSoC-4 UART transfers

Code example demonstrate transfer of bytes from PC to PSoC-4 via UART. The information in the bytes are used to turn ON/OFF an LED in PSoC-4

# Python-Code

```python
import serial
import time
# Open serial port (Replace 'COM6' with the COM port associated with the kit)
ser = serial.Serial('COM6', baudrate=115200, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE)
for i in range(10):
    # Write to serial port
    ser.write(b'\x01')
    time.sleep(1)
    ser.write(b'\x00')
    time.sleep(1)
    print("looping")
# Close serial port
ser.close()
```

# PSoC-Creator Code

```c
#include <project.h>

CY_ISR (my_isr)
{
    uint8_t var;
    var = UART_UartGetByte(); 
    UART_SpiUartClearRxBuffer();
    if(var == 0x01)
    {
        Pin_LED_Write(1);
    }
    else
    {
        Pin_LED_Write(0);        
    }
    
    // Clear the interrupt
    UART_ClearRxInterruptSource(UART_INTR_RX_ALL);
    
}
int main()
{
    CyGlobalIntEnable;

    /* Start SCB (UART mode) operation */
    UART_Start();

    /* Link to ISR */
    isr_1_StartEx(my_isr);
    
    for (;;)
    {

    }
}
```

# PSoC-Creator Schematic

![Untitled](Untitled.png)

![Untitled](Untitled%201.png)

![Untitled](Untitled%202.png)

# PSoC Pin Configuration

![Untitled](Untitled%203.png)

**—END**