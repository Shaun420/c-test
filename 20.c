/*
	PSP-1
	Assignment no. 5
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <math.h>
#include <time.h>
void main()
{
	int original = 0;
	printf("Enter a number to check armstrong number: ");
	scanf("%d", &original);
	time_t t1 = clock();
	if(original < 0)
	{
		printf("Number should be greater than or equal to 0.\n");
		return;
	}
	if(original == 0 || original == 1)
	{
		printf("Given number (%d) is armstrong number.\n", original);
		return;
	}
	int x = original, y = 0;
	int n = floor(log10(original)) + 1;
	while(x > 0)
	{
		y += powf(x % 10, n);
		x = x / 10;
		continue;
	}
	if(original == y)
	{
		printf("Given number (%d) is armstrong number.\n", original);
		return;
	}
	else
	{
		printf("Given number (%d) is not armstrong number.\n", original);
		return;
	}
	printf("Time taken: %ld\n", (clock() - t1));
}