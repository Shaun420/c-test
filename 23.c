/*
	PSP-1
	Assignment no. 10
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
void main()
{
	int x = 0, i = 0;
	char binaryNum[32];
	printf("Enter a number to print in binary: ");
	scanf("%d", &x);
	time_t t1 = clock();
	while(x > 0) {
		binaryNum[i] = x % 2;
		x = x / 2;
		i++;
	}
	for(int j = i - 1; j >= 0; j--)
	{
		printf("%d", binaryNum[j]);
	}
	printf("\n");
	printf("Time taken: %ld\n", (clock() - t1));
}