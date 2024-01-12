#include <stdio.h>
#include <string.h>
int main()
{
	// Initialize the variables
	int choice = 0, r1 = 0, c1 = 0, r2 = 0, c2 = 0, i = 0, j = 0, defined = 0;
	// Input matrix dimensions from user
	printf("Enter no. of rows in matrix A: ");
	scanf("%d", &r1);
	printf("Enter no. of columns in matrix A: ");
	scanf("%d", &c1);
	printf("Enter no. of rows in matrix B: ");
	scanf("%d", &r2);
	printf("Enter no. of columns in matrix B: ");
	scanf("%d", &c2);
	int m1[r1][c1], m2[r2][c2];
	while(1)
	{
		// Get option selected by user and store it in choice
		printf(" 1) Matrix Input\n 2) Matrix Addition\n 3) Matrix Multiplication\n");
		printf("Enter your choice: ");
		scanf("%d", &choice);
		// Menu based interface
		switch(choice)
		{
			case 1: // Matrix input
			{
				printf("Enter elements of matrix A:\n");
				for(i = 0; i < r1; i++)
				{
					for(j = 0; j < c1; j++)
					{
						printf("Enter element a%d%d: ", i+1, j+1);
						scanf("%d", &m1[i][j]);
					}
				}
				printf("Enter elements of matrix B:\n");
				for(i = 0; i < r2; i++)
				{
					for(j = 0; j < c2; j++)
					{
						printf("Enter element a%d%d: ", i+1, j+1);
						scanf("%d", &m2[i][j]);
					}
				}
				defined = 1;
				break;
			}
			case 2: // Matrix addition
			{
				if(!defined)
				{
					printf("Matrix A and B are not defined. Input matrix A and B first.\n");
					break;
				}
				if(r1 != r2 || c1 != c2)
				{
					printf("Matrix A and B cannot be added.\n");
					break;
				}
				int m3[r1][c1];
				printf("Matrix addition A + B is:\n");
				for(i = 0; i < r1; i++)
				{
					for(j = 0; j < c1; j++)
					{
						m3[i][j] = m1[i][j] + m2[i][j];
						printf("%d\t", m3[i][j]);
					}
					printf("\n");
				}
				break;
			}
			case 3: // Matrix multiplication
			{
				if(!defined)
				{
					printf("Matrix A and B are not defined. Input matrix A and B first.\n");
					break;
				}
				if(c1 != r2)
				{
					printf("Matrix A and B cannot be multiplied.\n");
					break;
				}
				int m3[r1][c1], k = 0, sum = 0;
				printf("Matrix multiplication A x B is:\n");
				for(i = 0; i < r1; i++)
				{
					for(j = 0; j < c2; j++)
					{
						sum = 0;
						for(k = 0; k < r2; k++)
						{
							sum += (m1[i][k] * m2[k][j]);
						}
						m3[i][j] = sum;
						printf("%d\t", m3[i][j]);
					}
					printf("\n");
				}
				break;
			}
			default:
			{
				// If choice is some other value, display invalid message
				printf("Invalid option selected.\n");
				break;
			}
		}
	}
	return 0;
}
