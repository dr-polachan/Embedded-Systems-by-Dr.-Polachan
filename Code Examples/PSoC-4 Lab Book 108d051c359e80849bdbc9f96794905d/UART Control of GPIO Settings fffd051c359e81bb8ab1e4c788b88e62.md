# UART Control of GPIO Settings

> Control the GPIO settings via UART
> 

# Schematic

                                                                                                                         

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled.png)

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%201.png)

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%202.png)

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%203.png)

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%204.png)

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%205.png)

# PSoC Firmware

```c
/* ========================================
 * Written by Prashanth Jonna (IMT2019507)
 * for ESD Lab Exam
 * Copyright IIIT-B, 2023
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/

#include "project.h"

CY_ISR(my_isr)

{  
    
    /* Create two 8 bit variables to hold the UART Data */
    uint8_t byte_1;
    uint8_t byte_2;
    
    /* Read the Data into the variables */
    byte_1 = UART_1_UartGetByte();
    byte_2 = UART_1_UartGetByte();
    
    /* If the first UART byte is 1, configure the GPIO to Resistive Pull-up Mode
    If the first byte is 0, configure the GPIO to Strong Drive
    0x02u is the value corresponding to Resistive Pull-up Mode
    0x06u is the value corresponding to Strong Drive Mode 
    These values can be found in the PSoC GPIO Drive mode section of the API */
   
    if(byte_1 == 0x01)
    {
        Pin_LED_SetDriveMode(0x02u);
    }
    else
    {
        Pin_LED_SetDriveMode(0x06u);
    }
    
    /* If second UART byte is 1, turn on the LED, 
    if it is zero, turn it off */
    
    if(byte_2 == 0x01)
    {
        Pin_LED_Write(1);
    }
    else
    {
        Pin_LED_Write(0);
    }
    
    UART_1_SpiUartClearRxBuffer();
    UART_1_ClearRxInterruptSource(UART_1_INTR_RX_ALL);

}

int main(void)
{
    
    /* Enable global interrupts. */
    CyGlobalIntEnable; 

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_1_Start();
    
    /* Link to ISR */
    isr_1_StartEx(my_isr);

    for(;;)
    {
    /* Place your application code here. */
    }
    
} 

/* End of code */
```

# Python Code

```python
# This code is written by Prashanth Jonna (IMT2019507) 
# as part of ESD Lab Exam, IIIT-B, 2023

# Description : This code randomly generates two bytes of data, each having a value of 0 or 1 and sends it over to PSoC via UART

import serial
import random
import time

# open serial port
ser = serial.Serial(
    port='COM4',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=0)

# Flush the serial data in channel
ser.flush()

while (True):
  
  # Randomly generate 2 bytes having value 0 or 1
  byte_1 = random.randint(0,1)
  byte_2 = random.randint(0,1)

  # Send the data through the UART port
  ser.write(byte_1.to_bytes(1, 'big')) 
  ser.write(byte_2.to_bytes(1, 'big')) 

  # To know the Drive Mode and LED value set by the randomly generated data
  if(byte_1 == 1):
    temp_str = " (Resistive Pull-Up Mode)";
  else:
    temp_str = " (Strong Drive Mode)";
  
  if(byte_2 == 1):
    temp_str_1 = " (Led ON)";
  else:
    temp_str_1 = " (Led OFF)";

  # Print out the bytes sent through UART
  print("---------------------------------")
  print("First Byte sent : " + str(byte_1) + temp_str) 
  print("Second Byte sent : " + str(byte_2) + temp_str_1)
  
  time.sleep(5)

ser.close() # Close the serial port
```

# Python Code (for Resistive Pull-Up, LED ON)

```python
# This code is written by Prashanth Jonna (IMT2019507) 
# as part of ESD Lab Exam, IIIT-B, 2023

# Description : This code generates two bytes of data - {1,1} corresponding to {Resistive pull up, Led ON} and sends it over to PSoC via UART

import serial
import random
import time

# open serial port
ser = serial.Serial(
    port='COM4',\
    baudrate=115200,\
    parity=serial.PARITY_NONE,\
    stopbits=serial.STOPBITS_ONE,\
    bytesize=serial.EIGHTBITS,\
        timeout=0)

# Flush the serial data in channel
ser.flush()

byte_1 = 1 # Resistive Pull up Drive mode
byte_2 = 1 # Set LED ON 

# Send the data through the UART port
ser.write(byte_1.to_bytes(1, 'big')) 
ser.write(byte_2.to_bytes(1, 'big')) 

ser.close() # Close the serial port
```

### Code Terminal Output :

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%206.png)

# Results

All the four possible combinations (00,11,01,10) and their results have been displayed below,

Please observe the last line on the terminal to know the drive mode and the Led value set randomly by the PC

- Picture showing LED-ON with resistive pull-up drive mode.

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%207.png)

- Picture showing LED-ON with strong drive-mode

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%208.png)

- Picture showing LED-OFF with strong drive-mode

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%209.png)

- Picture showing LED-OFF with resistive pull up drive-mode

![Untitled](UART%20Control%20of%20GPIO%20Settings%20fffd051c359e81bb8ab1e4c788b88e62/Untitled%2010.png)

**— END**