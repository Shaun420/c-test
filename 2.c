#include <stdio.h>
int main()
{
	/*	Test of ASCII value of characters
	*/
	unsigned char a = '0';
	unsigned char b = '9';
	unsigned char c = 'A';
	unsigned char d = 'Z';
	unsigned char e = 'a';
	unsigned char f = 'z';
	printf("0: (%d)\n", a);
	printf("9: (%d)\n", b);
	printf("A: (%d)\n", c);
	printf("Z: (%d)\n", d);
	printf("a: (%d)\n", e);
	printf("z: (%d)\n", f);
	a -= 257;
	printf("48-257: %c (%d)\n", a, a);
	return 1;
}