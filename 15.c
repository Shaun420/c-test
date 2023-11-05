#include <stdio.h>
#include <time.h>
void main()
{
	time_t t1 = clock();
	printf("Test.\n");
	printf("Time taken: %ld\n", (clock() - t1));
}