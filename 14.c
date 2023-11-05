/*
	PSP-1
	Assignment no. 3
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
void main()
{
	int x = 0;
	printf("Enter a number to check palindrome number:\n");
	scanf("%d", &x);
	if(x < 0)
	{
		printf("Number should be greater than or equal to 0.\n");
		return;
	}
	time_t t1 = clock();
	int n = snprintf(0,0,"%+d",x)-1;
	// printf("n: %d\n", n);
	char a[n];
	sprintf(a, "%d", x);
	// printf("a: %s\n", a);
	for(int i = 0; i < n; i++)
	{
		if(a[i] != a[n-1-i])
		{
			printf("Given number is not palindrome number.\n");
			return;
		}
	}
	printf("Given number is palindrome number.\n");
	printf("Time taken: %ld\n", (clock() - t1));
}