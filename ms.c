#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
	// To get randomness
	srand(time(NULL));
	// Calculate number of mines to spawn
	int r = 6, c = 6, mines = 5 + (rand() % 10), flags = mines;
	char a = '\0', b = '\0', choice = '\0';
	// Stores data of each cell in the game
	char game[r][c];
	// printf("Mines: %d\n", mines);

	// Create a new game and store the data values
	generateGame(game, r, c, mines);

	while(1)
	{
		// Display the game to stdout
		displayGame(game, r, c);

		// Accept cell no. from user
		printf("Minesweeper\nNo. of flags remaining: %d\n\'cA6\' to check cell A6, \'fA6\' to flag cell A6\n", flags);
		printf("Enter the cell in the format:\n");
		scanf(" %c%c%c", &choice, &a, &b);
		if(b < '1' || b > '6')
			continue;;
		if(a < 'A' || a > 'F')
			continue;;

		if(choice == 'c')
		{
			// Check the cell and display output
			checkCell(game, r, c, a, b);

			// Check if cell is a mine
			if(isMine(game, r, c, a, b))
			{
				printf("Game Over! You hit a mine (%c%c) and exploded.\n", a, b);
				return 1;
			}
		}
		else if(choice == 'f')
		{
			// Flag the cell and display output
			flagCell(game, r, c, a, b);
		}
		else continue;
	}
}