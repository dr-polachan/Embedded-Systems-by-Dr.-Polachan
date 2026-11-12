
Author: Kurian Polachan, Ph.D.
Date: 12th Nov 2026

| Modifier   | Example                     | Purpose                                                      |
| ---------- | --------------------------- | ------------------------------------------------------------ |
| `const`    | `const int x = 10;`         | Read-only variable                                           |
| `signed`   | `signed int x;`             | Signed integer type                                          |
| `unsigned` | `unsigned int x;`           | Unsigned integer type                                        |
| `volatile` | `volatile uint32_t status;` | Value may change unexpectedly (e.g., hardware register, ISR) |
| `static`   | `static int counter;`       | Static storage duration                                      |
| `extern`   | `extern int counter;`       | Variable defined in another source file                      |

#### A) Const variable

A variable declared using the `const` keyword indicates to both **other programmers** and the **compiler** that its value is intended to remain constant throughout the program and must not be modified after initialization. The C compiler enforces this rule by generating a compile-time error if the program attempts to change the variable.

**Example:**
```c
const int8_t MCU_ID = 12;    // Declare a constant variable
```

Once initialized, the value of `MCU_ID` cannot be modified anywhere in the program. For example, the following statements are not permitted:

```c
MCU_ID = 1;              // Error
MCU_ID = MCU_ID + 1;     // Error
MCU_ID++;                // Error
```

The C language does not specify where a `const` variable must be stored. Depending on the compiler and its optimization settings, a `const` variable may be stored in Flash (ROM), RAM, a CPU register.

In embedded systems, however, `const` variables are often placed in Flash memory** to conserve RAM. This is a common compiler optimization, but it is not guaranteed by the C language standard.

#### B) Signed and unsigned variable

When declaring an integer variable, the programmer must decide whether the variable needs to store **both positive and negative numbers** or **only non-negative numbers**. The C language provides signed and unsigned integer data types for this purpose.

**Example:**
```c
int8_t  temperature = -20;      // Signed 8-bit integer
uint8_t batteryLevel = 85;      // Unsigned 8-bit integer
```

The ranges of these data types are:

|Data Type|Size|Range|
|---|---|---|
|`int8_t`|8 bits|-128 to +127|
|`uint8_t`|8 bits|0 to 255|

#### C) Volatile variable

The **volatile** keyword tells the compiler that a variable's value may change unexpectedly due to events outside the control of the currently executing program. Therefore, the compiler must perform a fresh read whenever the variable is accessed.

**What happens if** `**volatile**` **is not used?**

```c
uint8_t buttonPressed = 0;

while (buttonPressed == 0)
{
    /* Wait until the button is pressed */
}
```

The compiler notices that `buttonPressed` is initialized to `0` and is never modified within the `while` loop. It may therefore assume that its value will always remain `0` and optimize the loop.

Conceptually, the compiler may generate code equivalent to:

```c
if (buttonPressed == 0)
{
    while (1)
    {
        /* Infinite loop */
    }
}
```

Now, even if an Interrupt Service Routine (ISR) changes `buttonPressed` to `1`, the CPU may never check its value again. As a result, the loop continues indefinitely.

**Solution: Use the** `**volatile**` **keyword.**


```c
volatile uint8_t buttonPressed = 0;

while (buttonPressed == 0)
{
    /* Wait until the button is pressed */
}
```

**How does** `**volatile**` **help?**

When a variable is declared as `volatile`, the compiler knows that its value can change unexpectedly. It must therefore generate code to read the variable again on every loop iteration instead of assuming that its value remains unchanged.

**Common Applications in Embedded Systems**

1) Variables shared between the main program and an ISR**

```c
volatile uint8_t uartDataReceived = 0;

CY_ISR(UART_RX_ISR)
{
    uartDataReceived = 1;
}
```

The main program can wait for the interrupt as shown below:

```c
while (uartDataReceived == 0)
{
    /* Wait for UART data */
}
```

2) **Memory-mapped hardware registers**
Hardware peripherals such as GPIOs, timers, UARTs, ADCs, and SPI controllers update their status registers independently of the CPU. These registers should therefore be accessed using `volatile` pointers.

```c
volatile uint32_t *GPIO_STATUS = (uint32_t *)0x40010000;

if (*GPIO_STATUS & 0x01)
{
    /* GPIO pin is HIGH */
}
```

3) **Other applications**
- Variables modified by Direct Memory Access (DMA).  
- Variables shared between multiple processors or execution contexts.

#### D) Static variable

A variable declared using the `static` keyword has a **lifetime that extends throughout the entire execution of the program**. Unlike a normal local variable, which is created when a function is called and destroyed when the function returns, a `static` variable is created only once and retains its value between successive function calls.

**Example:**

```c
void IncrementCounter(void)
{
    static uint8_t counter = 0;
    counter++;
    printf("Counter = %d\n", counter);
}
```

Suppose `IncrementCounter()` is called three times.

```
IncrementCounter();
IncrementCounter();
IncrementCounter();
```

The output will be:
```text
Counter = 1
Counter = 2
Counter = 3
```

Notice that the value of `counter` is preserved between function calls.

Now consider the same function without the `static` keyword.

```c
void IncrementCounter(void)
{
    uint8_t counter = 0;
    counter++;
    printf("Counter = %d\n", counter);
}
```

Again, suppose the function is called three times.

```
IncrementCounter();
IncrementCounter();
IncrementCounter();
```

The output will be:

```text
Counter = 1
Counter = 1
Counter = 1
```

This is because a normal local variable is created every time the function is called and destroyed when the function returns. Consequently, `counter` is initialized to zero during every function call.

When architecting a C program, `static` variables are useful whenever a function needs to remember information from previous calls. 

#### D) Extern variable

A variable declared using the `extern` keyword indicates to the **compiler** that the variable is **defined in another source file**. The `extern` declaration informs the compiler about the variable's name and data type without allocating additional memory for it.

In large C programs, multiple source files often need to access the same global variable. Rather than creating separate copies of the variable, one source file defines the variable, while other source files declare it using the `extern` keyword.

**Example:** Suppose the project consists of two source files.

```c
// main.c
#include <stdint.h>
uint8_t systemMode = 0;      // Variable definition
int main(void)
{
    systemMode = 1;
    while(1)
    {
    }
}
```

```c
// display.c
#include <stdint.h>
extern uint8_t systemMode;   // Variable declaration
void DisplayMode(void)
{
    printf("Mode = %d\n", systemMode);
}
```

In this example, the variable `systemMode` is **defined only once** in `main.c`. The `extern` declaration in `display.c` informs the compiler that the variable exists elsewhere. Both source files access the **same memory location**.

If `extern` is omitted and the variable is declared normally,

```c
uint8_t systemMode;
```

inside `display.c`, a second global variable is created, resulting in multiple definitions of the same variable. During linking, this typically produces an error similar to:

```text
multiple definition of 'systemMode'
```

The correct approach is therefore to define the variable only once and declare it as `extern` wherever it is needed.

**- END**
