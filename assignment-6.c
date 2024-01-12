#include <stdio.h>
#include <string.h>

struct Account {
	int acc_number;
	char acc_holder[50];
	float acc_balance;
	int acc_banking_facility;
	int acc_pincode;
	char acc_type[15];
};

void display_accounts(struct Account acc[], int num)
{
	int i;
	for(i = 0; i < num; i++)
	{
		printf("%d %s %0.2f %s %d %s\n", acc[i].acc_number, acc[i].acc_holder, acc[i].acc_balance,
		acc[i].acc_banking_facility ? "Yes":"No", acc[i].acc_pincode, acc[i].acc_type);
	}
}

void display_golden_accounts(struct Account acc[], int num)
{
	int i;
	printf("Golden accounts:\n");
	for(i = 0; i < num; i++)
	{
		if(acc[i].acc_balance >= 1000000)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
}

void display_silver_accounts(struct Account acc[], int num)
{
	int i;
	printf("Silver accounts:\n");
	for(i = 0; i < num; i++)
	{
		if(acc[i].acc_balance < 1000000 && acc[i].acc_balance >= 500000)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
}

void display_general_accounts(struct Account acc[], int num)
{
	int i;
	printf("General accounts:\n");
	for(i = 0; i < num; i++)
	{
		if(acc[i].acc_balance < 500000)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
}

void display_internet_banking(struct Account acc[], int num)
{
	int i;
	printf("List of customers availing Internet Banking facility:\n");
	for(i = 0; i < num; i++)
	{
		if(acc[i].acc_banking_facility)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
}

void display_pincode_accounts(struct Account acc[], int num, int pincode)
{
	int i;
	printf("List of accounts with pincode %d are:\n", pincode);
	for(i = 0; i < num; i++)
	{
		if(acc[i].acc_pincode == pincode)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
}

void display_by_type(struct Account acc[], int num, int pincode)
{
	int i;
	// Display savings account customers
	printf("Savings account customers:\n");
	for(i = 0; i < num; i++)
	{
		if(strcmp(acc[i].acc_type, "savings") == 0)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
	// Display recurring account customers
	printf("Recurring account customers:\n");
	for(i = 0; i < num; i++)
	{
		if(strcmp(acc[i].acc_type, "recurring") == 0)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
	// Display deposit account customers
	printf("Deposit account customers:\n");
	for(i = 0; i < num; i++)
	{
		if(strcmp(acc[i].acc_type, "deposit") == 0)
		{
			printf("%d %s\n", acc[i].acc_number, acc[i].acc_holder);
		}
	}
}

int main()
{
	int n = 0, N = 0;
	printf("Enter number of accounts to input: ");
	scanf("%d", &n);
	// Store account information in structure variable array a
	struct Account a[n];
	int i;
	// Take account data input from user.
	for(i = 0; i < n; i++)
	{
		printf("Enter account number: ");
		scanf("%d", &a[i].acc_number);
        printf("Enter account holder's name: ");
        scanf("%s", a[i].acc_holder);
        printf("Enter account balance: ");
        scanf("%f", &a[i].acc_balance);
        printf("Enter if account has availed banking facility (1 for yes, 0 for no): ");
        scanf("%d", &a[i].acc_banking_facility);
        printf("Enter account pincode (422001 to 422013): ");
        scanf("%d", &a[i].acc_pincode);
        printf("Enter account type (savings, recurring, deposit): ");
        scanf("%s", a[i].acc_type);
	}

	// Read account details for N customers.
	printf("Enter number of accounts to display: ");
	scanf("%d", &N);
	display_accounts(a, n);

	// Identify the golden, silver and general customers.
	display_golden_accounts(a, n);
	display_silver_accounts(a, n);
	display_general_accounts(a, n);

	// Display the list of customers availing the Internet Banking facility
	display_internet_banking(a, n);

	/* Display the customers belonging to a particular geographical location
	depending on postal code
	*/
	int pincode = 0;
	// Take pincode from user.
	printf("Enter pincode: ");
	scanf("%d", &pincode);
	// Display accounts with the given pincode
	display_pincode_accounts(a, n, pincode);

	// Display the customer list as per their account type.
	display_by_type(a, n, pincode);

	return 0;
}
