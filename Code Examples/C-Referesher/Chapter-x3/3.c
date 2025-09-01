// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() 
{
    int i;

    // --- Using while loop ---
    i = 0;   
    printf("while loop:\n");
    while (i <= 5) 
    {   
        printf("i = %d\n", i);
        i++;   
    }

    printf("\n");

    // --- Using for loop ---
    printf("for loop:\n");
    for (i = 0; i <= 5; i++) 
    {   
        printf("i = %d\n", i);
    }

    return 0;
}
