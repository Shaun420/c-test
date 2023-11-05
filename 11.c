#include <stdio.h>
void main()
{
	int m = 0, y = 0;
	printf("Enter no. of the month:");
	scanf("%d", &m);
	printf("Enter the year:");
	scanf("%d", &y);
	switch(m)
	{
		case 2:
			if((y % 4 == 0) && (y % 100 != 0) || (y % 400 == 0))
				printf("No. of days in given month is 29.\n");
			else
				printf("No. of days in given month is 28.\n");
			break;
		case 1:case 3:case 5:case 7:case 8:case 10:case 12:
			printf("No. of days in given month is 31.\n");
			break;
		case 4:case 6:case 9:case 11:
			printf("No. of days in given month is 30.\n");
			break;
		default:
			printf("Invalid no. of month.\n");
			break;
	}
}