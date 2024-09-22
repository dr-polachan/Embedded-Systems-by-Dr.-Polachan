# UART-based PWM Control

> Controls the brightness of an LED via UART.  Uses a GPIO to freeze the control.
> 

# Schematic

                                                                                                                                

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled.png)

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled%201.png)

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled%202.png)

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled%203.png)

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled%204.png)

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled%205.png)

![Untitled](UART-based%20PWM%20Control%20fffd051c359e8142b595dc5016de0d6d/Untitled%206.png)

# Firmware (Python)

```python
import serial
import time
# Open serial port (Replace 'COM6' with the COM port associated with the kit)
ser = serial.Serial('COM14', baudrate=115200, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE)
for i in range(255):
    my_hex = hex(i)[2:].zfill(2)
    # Convert hexadecimal string to bytes
    my_bytes = bytes.fromhex(my_hex)
    # Transmit variable over serial port
    ser.write(my_bytes)
    time.sleep(0.1)
    
# Close serial port
ser.close()
```

# Firmware (PSoC)

```c
#include "project.h"

CY_ISR (my_isr)
{
    uint8_t var;
    var = UART_UartGetByte(); 
    UART_SpiUartClearRxBuffer();
    /*if(var == 0x01)
    {
        Pin_LED_Write(1);
    }
    else
    {
        Pin_LED_Write(0);        
    }*/
     PWM_1_WriteCompare(var);
    
    // Clear the interrupt
    UART_ClearRxInterruptSource(UART_INTR_RX_ALL);
    
}
CY_ISR(my_isr_2)
{
    UART_Stop();
    Pin_1_ClearInterrupt();
}
int main()
{
    CyGlobalIntEnable;

    /* Start SCB (UART mode) operation */
    UART_Start();
    PWM_1_Start();
    /* Link to ISR */
    isr_1_StartEx(my_isr);
    isr_2_StartEx(my_isr_2);
    
    for (;;)
    {

    }
}
```

**— END**