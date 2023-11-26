#include <stdio.h>
#include <string.h>
int main()
{
	// Initialize the variables
	char str1[30];
	int choice = 0;
	// Take string input from user
	printf("Enter string 1: ");
	scanf("%s", str1);
	// Get option selected by user and store it in choice
	printf(" 1) Display length of given string.\n 2) Copy the string to another string and display\n\
 3) Concatenate given string with another string.\n 4) Compare given string with another string.\n");
	printf("Enter your choice: ");
	scanf("%d", &choice);
	// Menu based interface
	switch(choice)
	{
		case 1:
		{
			// Display length of str1
			printf("Length of given string is: %ld\n", strlen(str1));
			break;
		}
		case 2:
		{
			// Copy str1 into str2 and display str1
			char str2[30];
			strcpy(str2, str1);
			printf("String 2 is: %s\n", str2);
			break;
		}
		case 3:
		{
			// Retrieve str2 from user input
			char str2[30];
			printf("Enter string 2: ");
			scanf(" %s", str2);
			// Join str1 and str2 and store it in str1
			strcat(str1, str2);
			// Display str1
			printf("String 1 after concatenation is: %s\n", str1);
			break;
		}
		case 4:
		{
			// Retrieve str2 from user input
			char str2[30];
			printf("Enter string 2: ");
			scanf(" %s", str2);
			// Compare str1 and str2 and display if they are equal or not
			if(strcmp(str1, str2) == 0)
				printf("The two given strings are equal.\n");
			else
				printf("The two given strings are not equal.\n");
			break;
		}
		default:
		{
			// If choice is some other value, display invalid message
			printf("Invalid option selected.\n");
			break;
		}
	}
	return 0;
}
