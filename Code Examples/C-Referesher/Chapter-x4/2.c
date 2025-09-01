
// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() 
{
    int a[3] = {1, 2, 3};
    int b[3] = {22, 3, 2};
    int c[4] = {7, 8, 9, 10};

    int *arrPtr[3];

    arrPtr[0] = a;
    arrPtr[1] = &b[2];
    arrPtr[2] = &c[2];

    printf("1. Array Indexing:\n");
    printf("arrPtr[0]+2 = %d\n", *(arrPtr[0]+2));
    printf("arrPtr[1]-1 = %d\n", *(arrPtr[1]-1));
    printf("arrPtr[2]-2 = %d\n", *(arrPtr[2]-2));
    
    return 0;
}
