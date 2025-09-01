
// Prepared by Dr. Kurian Polachan
#include<stdio.h>

void main () 
{

	int var1 = 5, var2 = 6, var3 = 5;

  var1 = var2 = var3;
  printf("%d %d %d",var1, var2, var3);
	
	var1 = var2 == var3;
  printf("%d %d %d",var1, var2, var3);

}
