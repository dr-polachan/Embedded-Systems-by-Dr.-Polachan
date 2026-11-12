Author: Kurian Polachan, Ph.D.
Date: 12th Nov 2026
#### A) Print "Hello World !!!"
```c
// main.c
#include "project.h" // MCU-Specific
#include <stdio.h>

int main(void)
{
    char txBuf[50];
        
    CyGlobalIntEnable; // MCU-Specific
    UART_Start(); // MCU-Specific

    sprintf(txBuf, "Hello World !!!\r\n");
    UART_PutString(txBuf); // MCU-Specific          

    while (1)
    {
        /* Do nothing */
    }
}
```

#### B) Project Restructuring
```c
// main.c
#include <stdio.h>
#include "hal.h"

int main(void)
{
    char txBuf[50];

    HAL_Init();
    HAL_UART_Init();

    snprintf(txBuf, sizeof(txBuf), "Hello World!!!\r\n");
    HAL_UART_Write(txBuf);

    while (1)
    {
        /* Do nothing */
    }
}
```

```c
// hal.h
#ifndef HAL_H
#define HAL_H

void HAL_Init(void);
void HAL_UART_Init(void);
void HAL_UART_Write(const char *str);

#endif
```

```c
// hal.c 
#include "project.h" // MCU-Specific
#include "hal.h"
void HAL_Init(void)      { CyGlobalIntEnable; } // MCU-Specific
void HAL_UART_Init(void) { UART_Start(); } // MCU-Specific
void HAL_UART_Write(const char *str) { UART_PutString(str); } // MCU-Specific
```

```
// project structure
myProject/
├── Header Files/
│   └── hal.h
└── Source Files/
    ├── hal.c
    └── main.c
```

#### C) Basic Function Call

```c
// main.c
#include <stdio.h>
#include "hal.h"

/* Function to add two numbers */
int8_t AddNumbers(int8_t a, int8_t b)
{
    return a + b;
}

int main(void)
{
    char txBuf[50];
    int8_t sum;

    HAL_Init();
    HAL_UART_Init();

    sum = AddNumbers(10, 20);

    snprintf(txBuf, sizeof(txBuf), "Sum = %d\r\n", sum);
    HAL_UART_Write(txBuf);

    while (1)
    {
        /* Do nothing */
    }
}
```

#### D) Basic Function Call (Project Restructuring)

```c
// main.c
#include <stdio.h>
#include "hal.h"
#include "mathlib.h"

int main(void)
{
    char txBuf[50];
    int8_t sum;

    HAL_Init();
    HAL_UART_Init();

    sum = AddNumbers(10, 20);

    snprintf(txBuf, sizeof(txBuf), "Sum = %d\r\n", sum);
    HAL_UART_Write(txBuf);

    while (1)
    {
        /* Do nothing */
    }
}
```

```c
// mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

#include <stdint.h>

int8_t AddNumbers(int8_t a, int8_t b);

#endif
```

```c
// mathlib.c
#include "mathlib.h"

int8_t AddNumbers(int8_t a, int8_t b)
{
    return a + b;
}
```

```
// project structure
myProject/
├── Header Files/
│   ├── hal.h
│   └── mathlib.h
└── Source Files/
    ├── hal.c
    ├── main.c
    └── mathlib.c
```

**-END**