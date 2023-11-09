#include <stdio.h>
void main()
{
	int a[2][3] = {{3, 6, 9}, {12, 15, 18}};
	int i, j;
	for(i = 0; i < 2; i++)
	{
		for(j = 0; j < 3; j++)
			printf("%d\t", a[i][j]);
		printf("\n");
	}
}