#include <stdio.h>
int main()
{
	/*	Test of structure in C
	*/
	struct point
	{
		int x, y;
	};
    struct point A = {.x = 1, .y = 0};
    printf("A: (%d, %d)\n", A.x, A.y);
	return 1;
}