#include <stdio.h>

int max(int a, int b)
{
	return (a > b) ? a : b;
}

void main()
{
	/*	Takes three numbers from user as input,
		returns the maximum number using maximum function.
	*/
	int a=0, b=0, c=0;
	printf("Enter number 1:");
	scanf("%d", &a);
	printf("Enter number 2:");
	scanf("%d", &b);
	printf("Enter number 3:");
	scanf("%d", &c);
	a = max(a, b);
	a = max(a, c);
	printf("Maximum number is: %d\n", a);
}
