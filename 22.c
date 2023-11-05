/*
	PSP-1
	Assignment no. 9
	Shaunak Hawaldar A45
*/
#include <stdio.h>
#include <time.h>
void main()
{
	int A[3][4] =
	{
		{1, 2, 5, 6},
		{0, -1, 6, 3},
		{4, 1, 9, 2}
	};
	int B[4][3] =
	{
		{1, 0, 4},
		{2, -1, 1},
		{5, 6, 9},
		{6, 3, 2}
	};
	time_t t1 = clock();

	printf("Matrix multiplication is:\n");
	int sum = 0;
	for(int i=0; i < 3; i++)
	{
		for(int j=0; j < 3; j++)
		{
			sum = 0;
			for(int k=0; k < 4; k++)
				sum += (A[i][k] * B[k][j]);
			printf("%d ", sum);
		}
		printf("\n");
	}


	printf("Time taken: %ld\n", (clock() - t1));
}