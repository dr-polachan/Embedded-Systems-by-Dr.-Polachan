// Prepared by Dr. Kurian Polachan
#include <stdio.h>

void main()
{
	int var1;    
    float var2;

    var1 = 1/2;
    var2 = 1/2;
    printf("%d %f\n", var1, var2);

    var1 = 1.0/2;
    var2 = 1.0/2;
    printf("%d %f\n", var1, var2);
    
    var2 = 1.2;
    var1 = var2;
    printf("%d %f\n", var1, var2);

    printf("size of var1 = %d bytes and var2 = %d bytes", sizeof(var1), sizeof(var2));    
}