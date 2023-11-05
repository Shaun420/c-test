/*
	PSP-1
	Assignment no. 11
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
void main()
{
	int n = 0;
	char c = 'A';
	printf("Enter the no. of rows to print: ");
	scanf("%d", &n);
	for(int i=0; i < n; i++)
	{
		for(int j=n; j >= i; j--)
			printf(" ");

		c = 'A' + i;
		for(int k=0; k < (2*i+1); k++)
			printf("%c", c);

		printf("\n");
	}
}