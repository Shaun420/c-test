#include <stdio.h>

void main()
{
	/*	Takes three numbers from user as input,
		returns the maximum number using ternary operator.
	*/
	int a=0, b=0, c=0;
	printf("Enter number 1:");
	scanf("%d", &a);
	printf("Enter number 2:");
	scanf("%d", &b);
	printf("Enter number 3:");
	scanf("%d", &c);
	int m = (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
	printf("Maximum number is: %d\n", m);
}
