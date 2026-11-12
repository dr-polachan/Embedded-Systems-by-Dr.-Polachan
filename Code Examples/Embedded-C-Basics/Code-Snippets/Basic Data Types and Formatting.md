Author: Kurian Polachan, Ph.D.
Date: 12th Nov 2026

#### A) 
```c
// main.c
#include <stdio.h>
#include <stdint.h>
#include "hal.h"

int main(void)
{
    char txBuf[50];

    int8_t   var8;
    int16_t  var16;
    int32_t  var32;
    float    varFloat;
    double   varDouble;
    char     varChar;

    HAL_Init();
    HAL_UART_Init();

    snprintf(txBuf, sizeof(txBuf), "int8_t  = %zu bytes\r\n", sizeof(var8));
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "int16_t = %zu bytes\r\n", sizeof(var16));
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "int32_t = %zu bytes\r\n", sizeof(var32));
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "float   = %zu bytes\r\n", sizeof(varFloat));
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "double  = %zu bytes\r\n", sizeof(varDouble));
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "char    = %zu bytes\r\n", sizeof(varChar));
    HAL_UART_Write(txBuf);

    while (1)
    {
        /* Do nothing */
    }
}
```

Program Output
```
int8_t  = 1 bytes
int16_t = 2 bytes
int32_t = 4 bytes
float   = 4 bytes
double  = 8 bytes
char    = 1 bytes
```

#### B) 
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

    sum = AddNumbers(10, 55);
    char VarChar = '7';

	snprintf(txBuf, sizeof(txBuf),"Sum = %d, %x, %c\r\n",sum, sum, sum);
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf),"Var = %c, %d\r\n",VarChar, VarChar);
    HAL_UART_Write(txBuf);

    while (1)
    {
        /* Do nothing */
    }
}
```

#### C)

```c
// main.c
#include <stdio.h>
#include "hal.h"

int main(void)
{
    char txBuf[50];

    int8_t var8 = -10;
    uint8_t var8u = -10;

    HAL_Init();
    HAL_UART_Init();

    snprintf(txBuf, sizeof(txBuf), "var8 = %d, var8u = %u\r\n", var8, var8u);
    HAL_UART_Write(txBuf);
    
    snprintf(txBuf, sizeof(txBuf), "var8 = %x, var8u = %x\r\n", var8, var8u);
    HAL_UART_Write(txBuf);    

    while (1)
    {
        /* Do nothing */
    }
}
```

Output
```
var8 = -10
var8u = 246
var8 = fffffff6
var8u = f6

```

#### D)

```c
// main.c
#include <stdio.h>
#include "hal.h"

int main(void)
{
    char txBuf[50];
    
    HAL_Init();
    HAL_UART_Init();
    
    int8_t var8 = -10;
    
    snprintf(txBuf, sizeof(txBuf), "var8 >> 5 = %x\r\n", var8 >> 5);
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "var8 >> 5 = %d\r\n", var8 >> 5);
    HAL_UART_Write(txBuf);

	uint8_t var8u = -10;
	
    snprintf(txBuf, sizeof(txBuf), "var8u >> 5 = %x\r\n", var8u >> 5);
    HAL_UART_Write(txBuf);

    snprintf(txBuf, sizeof(txBuf), "var8u >> 5 = %u\r\n", var8u >> 5);
    HAL_UART_Write(txBuf);

    while (1)
    {
        /* Do nothing */
    }
}
```

Output
```
var8 >> 5 = ffffffff
var8 >> 5 = -1
var8u >> 5 = 7
var8u >> 5 = 7
```

#### E)
```c

#include <stdio.h>
#include "hal.h"

int main(void)
{
    char txBuf[50];

    int16_t var16;
    float varFloat = 1.2;

    HAL_Init();
    HAL_UART_Init();

    var16 = varFloat;
    snprintf(txBuf, sizeof(txBuf), "%d\r\n", var16);
    HAL_UART_Write(txBuf);

    var16 = (int16_t)varFloat;
    snprintf(txBuf, sizeof(txBuf), "%d\r\n", var16);
    HAL_UART_Write(txBuf);
	
	var16 = (int16_t)(varFloat*10);
    snprintf(txBuf, sizeof(txBuf), "%d\r\n", var16);
    HAL_UART_Write(txBuf);
       
    
    varFloat = 1/2;    
    var16 = (int16_t) (varFloat*10);
    snprintf(txBuf, sizeof(txBuf), "%d\r\n", var16);
    HAL_UART_Write(txBuf);
    
    varFloat = 1.0/2;    
    var16 = (int16_t) (varFloat*10);
    snprintf(txBuf, sizeof(txBuf), "%d\r\n", var16);
    HAL_UART_Write(txBuf);
    
    varFloat = (float) 1/2;    
    var16 = (int16_t) (varFloat*10);
    snprintf(txBuf, sizeof(txBuf), "%d\r\n", var16);
    HAL_UART_Write(txBuf);
        
}
```

Program Output
```
1
1
12
0
5
0
```

#### F)

```c
#include <stdio.h>
#include "hal.h"

int main(void)
{
    char txBuf[50];

    uint8_t var8_1 = 100;
	uint8_t var8_2	= 124;
	uint8_t var8_3;
	
    HAL_Init();
    HAL_UART_Init();
	
	var8_3 = var8_1 * var8_2;
	snprintf(txBuf, sizeof(txBuf), "result   = %d\r\n", var8_3);
    HAL_UART_Write(txBuf);

	var8_3 = (var8_1 * var8_2)/80;
	snprintf(txBuf, sizeof(txBuf), "result   = %d\r\n", var8_3);
    HAL_UART_Write(txBuf);
	       
}
```

Program Output

```
result   = 112
result   = 155
```

**-END**