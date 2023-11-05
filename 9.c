#include <stdio.h>
void main()
{
	int a = 0, b = 0, c = 0;
	printf("Enter length of side a of triangle:");
	scanf("%d", &a);
	printf("Enter length of side b of triangle:");
	scanf("%d", &b);
	printf("Enter length of side c of triangle:");
	scanf("%d", &c);

	if(a == b && a == c)
	{
		printf("Triangle is equilateral.\n");
	}
	else if(a == b || b == c || a == c)
	{
		printf("Triangle is isosceles.\n");
	}
	else
	{
		printf("Triangle is scalene.\n");
	}
}