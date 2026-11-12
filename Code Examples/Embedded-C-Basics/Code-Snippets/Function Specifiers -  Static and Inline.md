Author: Kurian Polachan, Ph.D.
Date: 12th Nov 2026

#### A) Normal function declaration

Function Declaration
```c
// mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

#include <stdint.h>

int8_t AddNumbers(int8_t a, int8_t b);

#endif
```

Function Definition
```c
// mathlib.c
#include "mathlib.h"

int8_t AddNumbers(int8_t a, int8_t b)
{
    return a + b;
}
```

Usage in Main Code
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

    while (1);
}
```

#### B) Static Function Declaration

Function Declaration
```c
// mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

#include <stdint.h>

static int8_t AddNumbers(int8_t a, int8_t b);

#endif
```

Function Definition
```c
// mathlib.c
#include "mathlib.h"

int8_t AddNumbers(int8_t a, int8_t b)
{
    return a + b;
}
```

Exposing AddNumbers() in main.c ?
```c
// mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

#include <stdint.h>

static int8_t AddNumbers(int8_t a, int8_t b);
int8_t XAddNumbers(int8_t a, int8_t b);

#endif
```

```c
// mathlib.c
#include "mathlib.h"

int8_t AddNumbers(int8_t a, int8_t b)
{
    return a + b;
}

int8_t XAddNumbers(int8_t a, int8_t b)
{
	return AddNumbers(a, b);    
}
```

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

    sum = XAddNumbers(10, 20);

    snprintf(txBuf, sizeof(txBuf), "Sum = %d\r\n", sum);
    HAL_UART_Write(txBuf);

    while (1);
}

```

main.c indirectly calls the static function using another function XAddNumbers which is declared as a normal function.
#### C) Inline Function Declaration

Inline Function Declaration
```c
// mathlib.h
#ifndef MATHLIB_H
#define MATHLIB_H

#include <stdint.h>

inline int8_t AddNumbers(int8_t a, int8_t b);

#endif
```

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

    while (1);
}
```

If the function is declared as inline, the compiler may simply replace sum = AddNumbers(10, 20) with sum = 10+20. There is no function call involved; The CPU never jumps to another function -> saves time.

"May" - It is at the discretion of the compiler to perform the action of replacement. If the function has only few lines of code, the compiler may decide to make it inline otherwise it will skip to save program memory

**- END**
