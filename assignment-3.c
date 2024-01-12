#include <stdio.h>
#include <math.h>
float add(float m, float n)
{
	return (m + n);
}
float subtract(float m, float n)
{
	return (m - n);
}
float multiply(float m, float n)
{
	return (m * n);
}
float divide(float m, float n)
{
	return (m / n);
}
float power(float num, float exp)
{
	return powf(num, exp);
}
int main()
{
	int choice = 0;
	float x = 0.0, y = 0.0;
	printf("Enter number 1: ");
	scanf("%f", &x);
	printf("Enter number 2: ");
	scanf("%f", &y);
	printf("Calculator:-\nChoose an operation to perform:\n 1) Addition 2) Subtraction 3) Multiplication 4) Division.\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case 1:
		{
			printf("Addition (%f + %f) is: %f.\n", x, y, add(x, y));
			break;
		}
		case 2:
		{
			printf("Subtraction (%f - %f) is: %f.\n", x, y, subtract(x, y));
			break;
		}
		case 3:
		{
			printf("Multiplication (%f * %f) is: %f.\n", x, y, multiply(x, y));
			break;
		}
		case 4:
		{
			printf("Division (%f / %f) is: %f.\n", x, y, divide(x, y));
			break;
		}
		case 5:
		{
			printf("Power (%f ^ %f) is: %f.\n", x, y, power(x, y));
		}
		default:
		{
			printf("Invalid choice.\n");
			break;
		}
	}
}