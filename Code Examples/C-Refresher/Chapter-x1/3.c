
// Prepared by Dr. Kurian Polachan
#include<stdio.h>
#define display(value) printf("%d\n", value)

void main () 
{

	int var1, var2, var3;
	
	var1 = 1; var2 = 2, var3=0;
    
    display(var1);
	display(var2);
	display(var3);

	display (!var2);
	display (!var3);
		
	display (var1 || var2);
    display (var2 && var3);

}
