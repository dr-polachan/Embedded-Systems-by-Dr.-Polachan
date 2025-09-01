
// Prepared by Dr. Kurian Polachan
#include<stdio.h>
#define display(value) printf("%d\n", value)

void main () 
{

	int var1, var2, var3;
	
	var1 = 1;
	
	var2 = ++var1;
	display(var1);
	display(var2);
	
	var3 = var1++;
	display(var1);
	display(var3);	
}
