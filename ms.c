#include <stdio.h>
#include <stdlib.h>
// #include <math.h>
#include <time.h>

// Represents each Tile/cell in the game board
struct Tile
{
	int isMine;
	int isSearched;
	int isFlagged;
	int nearbyMine;
};

// Game board dimensions
#define ROWS	8
#define COLS	8
// Save how many mines to spawn in totalmines
// Store how many flags are available in flags
int totalmines = 0, flags = 0;
// Stores data of each cell in the game
struct Tile board[ROWS][COLS];

// Function prototypes
void generateGame();
void displayGame();
void generateMines();
void addNearbyMinesCount(int, int);
int isValidTile(int, int);
int is_game_over();

int main()
{
	// Variables for storing user input
	char a = '\0', b = '\0', choice = '\0';

	// To get randomness
	srand(time(NULL));
	// Total no. of mines to spawn
	totalmines = 10 + (rand() % 5);
	flags = totalmines;
	printf("Mines to spawn: %d\n", totalmines);

	// Create a new game and store the data values
	generateGame();

	// Create the mines at random tiles
	generateMines();

	while(1)
	{
		// Display the game to stdout
		displayGame();

		// Accept choice and tile no. from user
		printf("Minesweeper\nNo. of flags remaining: %d\nEnter \"s\" for searching tile and \
\"f\" for flagging tiles.\nEnter your choice: ", flags);
		scanf(" %c", &choice);
		printf("Enter the cell in the format (A1): ");
		scanf(" %c%c", &a, &b);
		// Check if value of b is correct
		if(b < '1' || b > ('1' + ROWS))
		{
			continue;
		}
		// printf("a: %d, b: %d\n", a, b);
		// Convert b from character (digit) to corresonding integer
		b -= 49;

		// Convert a from character (uppercase or lowercase) to corresonding integer
		if(a >= 'A' && a <= 'Z')
			a -= 65;
		else if(a >= 'a' && a <= 'z')
			a -= 97;
		else continue;
		if(a >= COLS) continue;

		// Search the cell
		if(choice == 's')
		{
			// Check if cell is a mine
			if(board[b][a].isMine)
			{
				printf("Game Over! You hit a mine (%c%c) and exploded.\n", 'A' + a, '1' + b);
				return 1;
			}
			// Set the tile as searched for displayGame to show nearbyMines
			board[b][a].isSearched = 1;
		}
		else if(choice == 'f') // Flag the cell
		{
			// Check if cell has already been searched
			if(board[b][a].isSearched)
			{
				printf("ERROR: Given tile is already searched.\n");
				continue;
			}
			if(board[b][a].isFlagged)
			{
				// Set the tile as not flagged
				board[b][a].isFlagged = 0;
				flags++;
			}
			else
			{
				// Flags remaining is zero
				if(flags == 0)
				{
					printf("ERROR: No flags are remaining. Unflag some tile to get a flag.\n");
					continue;
				}
				// Set the tile as flagged
				board[b][a].isFlagged = 1;
				flags--;
				// Check if the game is over
				if(flags == 0)
				{
					if(!is_game_over()) continue;
					printf("You won! All the mines are successfully flagged.\n");
					return 0;
				}
			}
		}
		else continue;
	}
}

// Sets the default values in board array
void generateGame()
{
	int i, j;
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			board[i][j].isMine = 0;
			board[i][j].isSearched = 0;
			board[i][j].isFlagged = 0;
			board[i][j].nearbyMine = 0;
			continue;
		}
	}
}

// Print the entire board with correct values
void displayGame()
{
	int i, j;

	// For first row, display A to Z (or last alphabet)
	printf("  |");
	for(i = 0; i < COLS; i++)
	{
		printf(" %c |", 'A' + i);
	}
	printf("\n");

	// Display each row of board prefixed by row no.
	for(i = 0; i < ROWS; i++)
	{
		printf("%d |", i + 1);
		for(j = 0; j < COLS; j++)
		{
			if(board[i][j].isSearched)
				printf(" %d |", board[i][j].nearbyMine);
			else if(board[i][j].isFlagged)
				printf(" F |");
			else
				printf(" x |");
		}
		printf("\n");
	}
}

/* Set random tiles as mines without duplicates
till no. of mines spawned = totalmines */
void generateMines()
{
	int mines = 0, id = 0, row = 0, col = 0;
	while(mines < totalmines)
	{
		id = (rand() % (ROWS * COLS));
		row = (id / ROWS);
		col = (id % ROWS);
		// For checking if mine is already spawned
		if(board[row][col].isMine)
			continue;
		// Set the tile as mines
		board[row][col].isMine = 1;
		// Increment nearbyMines of nearby tiles by 1
		addNearbyMinesCount(row, col);
		mines++;
	}
	return;
}

/* For setting correct value of nearbyMines of all tiles,
this function increments nearbyMines of nearby tiles by one.
Hence, if two mines are near a tile, this function will
increment value of nearbyMines for that tile by 1 twice. */
void addNearbyMinesCount(int r, int c)
{
	// Top middle
	if(isValidTile(r-1, c))
		board[r-1][c].nearbyMine++;
	// Top left
	if(isValidTile(r-1, c-1))
		board[r-1][c-1].nearbyMine++;
	// Top right
	if(isValidTile(r-1, c+1))
		board[r-1][c+1].nearbyMine++;
	// Middle left
	if(isValidTile(r, c-1))
		board[r][c-1].nearbyMine++;
	// Middle right
	if(isValidTile(r, c+1))
		board[r][c+1].nearbyMine++;
	// Bottom middle
	if(isValidTile(r+1, c))
		board[r+1][c].nearbyMine++;
	// Bottom left
	if(isValidTile(r+1, c-1))
		board[r+1][c-1].nearbyMine++;
	// Bottom right
	if(isValidTile(r+1, c+1))
		board[r+1][c+1].nearbyMine++;
	return;
}

// To check if a given row and col id is within game dimensions
int isValidTile(int r, int c)
{
	return ((r >= 0 && r < ROWS) && (c >= 0 && c < COLS));
}

// To check if all the mines have been flagged or not
int is_game_over()
{
	int i, j;
	for(i = 0; i < ROWS; i++)
	{
		for(j = 0; j < COLS; j++)
		{
			if(board[i][j].isMine && !board[i][j].isFlagged)
				return 0;
		}
	}
	return 1;
}
