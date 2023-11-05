/*
	PSP-1
	Assignment no. 6
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
void main()
{
	int x = 0;
	printf("Enter a number to print sum of digits: ");
	scanf("%d", &x);
	time_t t1 = clock();
	if(x < 0)
	{
		printf("Number should be greater than or equal to 0.\n");
		return;
	}
	int sum = 0;
	while(x > 0)
	{
		sum += (x % 10);
		x = floor(x / 10);
		continue;
	}
	printf("Sum of digits of given number is: %d\n", sum);
	printf("Time taken: %ld\n", (clock() - t1));
}