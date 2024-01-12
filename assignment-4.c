#include <stdio.h>
float add(float* m, float* n, float* res)
{
	*res = (*m + *n);
}
float subtract(float* m, float* n, float* res)
{
	*res = (*m - *n);
}
float multiply(float* m, float* n, float* res)
{
	*res = ((*m) * (*n));
}
float divide(float* m, float* n, float* res)
{
	*res = (*m / *n);
}
int main()
{
	int choice = 0;
	float x = 0.0, y = 0.0, result = 0.0;
	printf("Enter number 1: ");
	scanf("%f", &x);
	printf("Enter number 2: ");
	scanf("%f", &y);
	printf("Calculator:-\n 1) Addition of two numbers\n 2) Subtraction of two numbers\n\
 3) Multiplication of two numbers\n 4) Division  of two numbers\n\
Choose an operation to perform: ");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		{
			add(&x, &y, &result);
			printf("Addition (%f + %f) is: %f.\n", x, y, result);
			break;
		}
		case 2:
		{
			subtract(&x, &y, &result);
			printf("Subtraction (%f - %f) is: %f.\n", x, y, result);
			break;
		}
		case 3:
		{
			multiply(&x, &y, &result);
			printf("Multiplication (%f * %f) is: %f.\n", x, y, result);
			break;
		}
		case 4:
		{
			divide(&x, &y, &result);
			printf("Division (%f / %f) is: %f.\n", x, y, result);
			break;
		}
		default:
		{
			printf("Invalid choice.\n");
			break;
		}
	}
}