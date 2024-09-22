# PC ↔ PSoC UART transfers

# Python-Code

```python
import serial
import time

# Open serial port
ser = serial.Serial('COM6', baudrate=115200, parity=serial.PARITY_NONE, stopbits=serial.STOPBITS_ONE)

# controlling LED on PSoC
for i in range(2):
    # Write to serial port
    ser.write(b'\x01')    
    time.sleep(1)
    ser.write(b'\x00')
    time.sleep(1)
    print("looping")

# reading data bytes from PSoC
data_valid = False
for i in range(50):        
    # read from serial port with header = 0xAA 0xFF and tail = 0xFF 0xFF    
    while (ser.read() != b'\xAA' ):
        pass   
    if(ser.read() == b'\xFF'):
        data = ser.read().hex();        
        tail = ser.read();
        tail_2 = ser.read();        
        if ( tail == b'\xFF' and tail_2 == b'\xFF'):
            data_valid = True    
    # print the data if header and tail matches
    if(data_valid == True):
        print(data)
        data_valid = False    

# Close serial port
ser.close()
```

Installing Pyserial. Go to Spyder (Python IDE) terminal and type **!pip install pyserial**

# PSoC-Creator Code

> Change the variable **data** with the values you want to send (e.g., waveform bytes)
> 

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
    
    // format of arrData = <header-1><header-2><data><tail-1><tail-2>
    uint8_t arrData[10] = {0xAA, 0xFF, 0x00, 0xFF, 0xFF}; 
    uint8_t data = 0x04;
    for (;;)
    {
        data = data + 1;
        arrData[2] = data;
        UART_SpiUartPutArray(arrData, 5);
        CyDelay(1000);
        
        
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