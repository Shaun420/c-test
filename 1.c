#include <stdio.h>
void main()
{
	/*	Datatypes sizes in bytes
	*/
	printf("sizeof(void): %ld\n", sizeof(void));
	printf("sizeof(char): %ld\n", sizeof(char));
	printf("sizeof(int): %ld\n", sizeof(int));
	printf("sizeof(short int): %ld\n", sizeof(short int));
	printf("sizeof(unsigned short int): %ld\n", sizeof(unsigned short int));
	printf("sizeof(signed int): %ld\n", sizeof(signed int));
	printf("sizeof(unsigned int): %ld\n", sizeof(unsigned int));
	printf("sizeof(long int): %ld\n", sizeof(long int));
	printf("sizeof(unsigned long int): %ld\n", sizeof(unsigned long int));
	printf("sizeof(long long int): %ld\n", sizeof(long long int));
	printf("sizeof(unsigned long long int): %ld\n", sizeof(unsigned long long int));

	printf("sizeof(float): %ld\n", sizeof(float));
	printf("sizeof(double): %ld\n", sizeof(double));
	printf("sizeof(long double): %ld\n", sizeof(long double));
}