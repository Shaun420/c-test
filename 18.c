/*
	PSP-1
	Assignment no. 7
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
void main()
{
	int x = 0;
	printf("Enter a number to reverse: ");
	scanf("%d", &x);
	time_t t1 = clock();
	if(x < 10)
	{
		printf("Number should be greater than 9.\n");
		return;
	}
	int reverse = 0, digit = 0;
	while(x > 0)
	{
		digit = x % 10;
		reverse = reverse * 10 + digit;
		x = floor(x / 10);
		continue;
	}
	printf("Reversed number is: %d\n", reverse);
   	printf("Time taken: %ld\n", (clock() - t1));
}