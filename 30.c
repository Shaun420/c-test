#include <stdio.h>
int main()
{
char str1[] = "Hello";
char *p = "Hello";
// str1 = "Bye"; /* error */
p = "Bye"; /* works */
printf("Element: %d\n", *p);
}