/*
	PSP-1
	Assignment no. 4
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
void main()
{
	int x = 0;
	printf("Enter a number to print factorial: ");
	scanf("%d", &x);
	time_t t1 = clock();
	if(x < 0)
	{
		printf("Number should be greater than or equal to 0.\n");
		return;
	}
	if(x == 0 || x == 1)
	{
		printf("%d! = 1.\n", x);
		return;
	}
	int factorial = 1;
	for(int i = x; i >= 1; i--)
	{
		factorial *= i;
		continue;
	}
	printf("%d! = %d\n", x, factorial);
	printf("Time taken: %ld\n", (clock() - t1));
}