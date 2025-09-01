
// Prepared by Dr. Kurian Polachan
#include <stdio.h>

int main() {
    
    char word[] = "APPLE";

    char *ptr;

    ptr = word;
    printf("*ptr  : %c\n", *ptr);   
    printf("*(ptr+1)  : %c\n", *(ptr+1));   

    char *words[] = {"APPLE", "BANANA", "CHERRY", "DATE"};

    char **ptr2;
    ptr2 = words; 

    printf("*ptr2  : %s\n", *ptr2);     
    printf("*(ptr2 + 1) : %s\n", *(ptr2 + 1)); 
    printf("*(ptr2 + 2) : %s\n", *(ptr2 + 2)); 

    return 0;
}
