#include <stdio.h>
#include <string.h>
#include <time.h>

struct Account {
	int accNumber;
	char accHolder[64];
	int accBalance;
	int internet_banking;
	int accPincode;
	char accType[16];
};

void displayGoldenAccounts(struct Account a[], int n)
{
	printf("Golden Customers are:\n");
	for(int i = 0; i < n; i++)
	{
		if(a[i].accBalance >= 1000000)
		{
			printf("%d - %s - %d\n", a[i].accNumber, a[i].accHolder, a[i].accBalance);
		}
	}
}

void displaySilverAccounts(struct Account a[], int n)
{
	printf("Silver Customers are:\n");
	for(int i = 0; i < n; i++)
	{
		if(a[i].accBalance >= 500000 && a[i].accBalance < 1000000)
		{
			printf("%d - %s - %d\n", a[i].accNumber, a[i].accHolder, a[i].accBalance);
		}
	}
}

void displayGeneralAccounts(struct Account a[], int n)
{
	printf("General Customers are:\n");
	for(int i = 0; i < n; i++)
	{
		if(a[i].accBalance < 500000)
		{
			printf("%d - %s - %d\n", a[i].accNumber, a[i].accHolder, a[i].accBalance);
		}
	}
}

void displayInternetBanking(struct Account a[], int n)
{
	printf("Customers who enabled Internet Banking are:\n");
	for(int i = 0; i < n; i++)
	{
		if(a[i].internet_banking == 1)
		{
			printf("%d - %s\n", a[i].accNumber, a[i].accHolder);
		}
	}
}

void displayPincode(struct Account a[], int n, int pincode)
{
	printf("Customers who belong to pincode %d are:\n", pincode);
	for(int i = 0; i < n; i++)
	{
		if(a[i].accPincode == pincode)
		{
			printf("%d - %s\n", a[i].accNumber, a[i].accHolder);
		}
	}
}

void displaySavingsAcc(struct Account a[], int n)
{
	printf("Savings Accounts are:\n");
	for(int i = 0; i < n; i++)
	{
		if(strcmp(a[i].accType, "savings") == 0)
		{
			printf("%d - %s\n", a[i].accNumber, a[i].accHolder);
		}
	}
}

void displayRecurringAcc(struct Account a[], int n)
{
	printf("Recurring Accounts are:\n");
	for(int i = 0; i < n; i++)
	{
		if(strcmp(a[i].accType, "recurring") == 0)
		{
			printf("%d - %s\n", a[i].accNumber, a[i].accHolder);
		}
	}
}

void displayDepositAcc(struct Account a[], int n)
{
	printf("Deposit Accounts are:\n");
	for(int i = 0; i < n; i++)
	{
		if(strcmp(a[i].accType, "deposit") == 0)
		{
			printf("%d - %s\n", a[i].accNumber, a[i].accHolder);
		}
	}
}

void main()
{
	int n = 0, N = 0, i = 0, pincode = 0;
	printf("Enter no. of accounts to input: ");
	scanf("%d", &n);
	struct Account a[n];
	for(i = 0; i < n; i++)
	{
		printf("Enter data for account %d:\n", i + 1);
		printf("Enter account number: ");
		scanf("%d", &a[i].accNumber);
		printf("Enter name of account holder: ");
		scanf(" %s", a[i].accHolder);
		printf("Enter account balance: ");
		scanf("%d", &a[i].accBalance);
		printf("Enter if account holder has enabled internet banking facility. Type 1 for yes and 0 for no: ");
		scanf("%d", &a[i].internet_banking);
		printf("Enter pincode of account holder (422001 - 422013): ");
		scanf("%d", &a[i].accPincode);
		printf("Enter account type (savings, recurring, deposit): ");
		scanf(" %s", a[i].accType);
	}
	printf("Enter no. of accounts to display: ");
	scanf("%d", &N);
	printf("Account Data for %d accounts:\n", N);
	printf("Acc No.\t- Account Holder - Balance - Internet Banking - Pincode - Account Type\n");
	for(i = 0; i < N; i++)
	{
		printf("%d\t - %s\t\t - %d - %s\t\t - %d\t - %s\n", a[i].accNumber, a[i].accHolder, a[i].accBalance,
		a[i].internet_banking ? "Yes" : "No", a[i].accPincode, a[i].accType);
	}
	printf("---------------------------------------\n");

	displayGoldenAccounts(a, n);
	displaySilverAccounts(a, n);
	displayGeneralAccounts(a, n);

	displayInternetBanking(a, n);

	printf("Enter pincode of account to display: ");
	scanf("%d", &pincode);
	displayPincode(a, n, pincode);

	displaySavingsAcc(a, n);
	displayRecurringAcc(a, n);
	displayDepositAcc(a, n);
}
