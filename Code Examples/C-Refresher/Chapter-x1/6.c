
// Prepared by Dr. Kurian Polachan
#include<stdio.h>
#define display(value) printf("%d\n", value);

void main () 
{

	int var1, var2, var3, var4;
	
	var1 = 1; var2 = 2; var3 = 2;
	display(var1 > var2 ? 3 : var3);

	var4 = (var2 <= var2) ? var2 : var1;
	display(var4);
	
}
