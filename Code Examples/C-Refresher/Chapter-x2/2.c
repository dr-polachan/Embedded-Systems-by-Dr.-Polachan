// Prepared by Dr. Kurian Polachan
#include <stdio.h>

void main()
{
	int var1 = -10;	
	unsigned var2 = -10;

	printf("%x\n",var1);
	printf("%x\n",var2);

	printf("%d\n",var1);
	printf("%d\n",var2);

	printf("%x\n",var1 >> 5);
	printf("%x\n",var2 >> 5);

	printf("%d\n",var1 >> 5);
	printf("%d\n",var2 >> 5);

}