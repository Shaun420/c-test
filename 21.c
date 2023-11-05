/*
	PSP-1
	Assignment no. 1
	Shaunak Hawaldar A45
*/
#include <stdio.h>
void main()
{
	int no1 = 0, no2 = 1, temp = 0, i = 0, n = 0;
	printf("Enter the no. of fibonacci numbers to print: \n");
	scanf("%d", &n);
	if(n < 1)
	{
		printf("No. should be greater than 0.\n");
		return;
	}
	while(i < n)
	{
		printf("%d\n", no1);
		temp = no2;
		no2 += no1;
		no1 = temp;
		i++;
		continue;
	}
}
