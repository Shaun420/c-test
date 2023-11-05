#include <stdio.h>
void main()
{
	int n = 0, i = 0;
	printf("Enter number: ");
	scanf("%d", &n);
	printf("Given number (%d) in binary is: ", n);
	for(i = 31; i >= 0; i--)
	{
		if((n >> i) & 1)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}