/*
	PSP-1
	Assignment no. 2
	Shaunak Hawaldar A45
*/
#include <stdio.h>

void checkprime(int num)
{
	if(num < 2)
	{
		printf("Given number (%d) is not a prime number.\n", num);
		return;
	}
	for(int i = 2; i < num; i++)
	{
		if((num % i) == 0)
		{
			printf("Given number (%d) is not a prime number.\n", num);
			return;
		}
		continue;
	}
	printf("Given number (%d) is a prime number.\n", num);
}

void main()
{
	/*	Takes a number as input and checks if the number is prime or not.
	*/
	int number = 0;
	printf("Enter a number:");
	scanf("%d", &number);
	checkprime(number);
}
