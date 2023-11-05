/*
	PSP-1
	Assignment no. 8
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
#include <math.h>
void main()
{
	int x = 0, y = 0;
	printf("Enter number x: ");
	scanf("%d", &x);
	printf("Enter number y: ");
	scanf("%d", &y);
	time_t t1 = clock();
	x += y;
	y = x - y;
	x -= y;

	printf("Number x: %d\n", x);
	printf("Number y: %d\n", y);

	printf("Time taken: %ld\n", (clock() - t1));
}