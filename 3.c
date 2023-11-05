#include <stdio.h>
void main()
{
	/*	Test of union in C
	*/
	union numbers
	{
		int i;
		float f;
	} Number1 = {.f = 3.14159};
	Number1.i = 3;
	printf("pi: %d\n", Number1.i);
	Number1.f = 3.14159;
	printf("pi: %f\n", Number1.f);
}