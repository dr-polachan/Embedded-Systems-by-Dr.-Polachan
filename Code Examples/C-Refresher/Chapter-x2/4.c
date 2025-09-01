// Prepared by Dr. Kurian Polachan
#include <stdio.h>
void main()
{
	int var1;    
    float var2 = 1.8;

    // implicit casting
    var1 = var2;    
    printf("%d %f\n", var1, var2);
   
    // explicit casting
    var1 = (int) var2;    
    printf("%d %f\n", var1, var2);

    int x = 10, y = 20;
    float z;

    // implicit casting
    z = x/y; printf("%f\n", z);

    // explicit casting
    z = (float) x/y; printf("%f\n", z);
}