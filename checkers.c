#include <stdio.h>
#define BOARD_SIZE 8
char board[BOARD_SIZE][BOARD_SIZE];
void initialize_board()
{
	for(int row = 0; row < BOARD_SIZE; row++)
	{
		for(int col = 0; col < BOARD_SIZE; col++)
		{
			if ((row + col) % 2 == 0)
			{
				if(row < 3)
					board[row][col] = 'X';
				else if(row > 4)
					board[row][col] = 'O';
				else
					board[row][col] = ' ';
			}
			else
			{
				board[row][col] = ' ';
			}
		}
	}
}
int move_is_invalid(int p, char a, char b, char c, char d)
{
	printf("Debug 3\n");
	// Check if the piece belongs to player.
	if((p == 1) && (board[b - 49][a - 65] != 'X'))
		return 1;
	else if((p == -1) && (board[b - 49][a - 65] != 'O'))
		return 1;

	printf("Debug 4\n");
	// Check if the destination is empty.
	if(board[d - 49][c - 65] != ' ')
		return 1;

	printf("Debug 5\n");
	int n = (d - b) / p;
	if(n < 1)
		return 1;

	printf("Debug 6\n");
	int l = (c - a) / p;
	if(l != n && l != -n)
		return 1;
	for(int i = 1; i < n; i++)
	{
		if(board[b + i*p][a + i*p*l/n] != ((p == 1) ? 'O' : 'X'))
			return 1;
	}
	for(int i = 1; i < n; i++)
		board[b + i*p][a + i*p*l/n] = ' ';

	printf("Debug 7\n");
	return 0;
}
void move_piece(int p, char a, char b, char c, char d)
{
	board[d - 49][c - 65] = (p == 1) ? 'X' : 'O';
	board[b - 49][a - 65] = ' ';
}
void print_board()
{
	printf("  | A | B | C | D | E | F | G | H |\n");
	for(int row = 0; row < BOARD_SIZE; row++)
	{
		printf("%d ", row + 1);
		for(int col = 0; col < BOARD_SIZE; col++)
		{
			printf("| %c ", board[row][col]);
		}
		printf("|\n");
	}
}
int is_game_over()
{
	// Check if all X's pieces are eliminated
	int x = 0, y = 0;
	for(int row = 0; row < BOARD_SIZE; row++)
	{
		for(int col = 0; col < BOARD_SIZE; col++)
		{
			if(board[row][col] == 'X')
				x++;
			if(board[row][col] == 'O')
				y++;
			continue;
		}
	}
	if(x == 0 || y == 0)
		return 1;

	return 0;
}
int main()
{
	initialize_board();
	int game_over = 0;
	int player_turn = 1; // 1 for player 'X', -1 for player 'O'
	char a = '\0', b = '\0', c = '\0', d = '\0';
	while(!game_over)
	{
		printf("Player %c's turn:\n", (player_turn == 1) ? 'X' : 'O');
		print_board();
		// Add game logic to allow the current player to make a move.
		// Piece to move such as D6
		printf("Enter which piece to move: ");
		scanf(" %c%c", &a, &b);
		printf("a: %d, b: %d\n", a, b);
		if(b < '1' || b > '8')
			continue;
		if(a < 'A' || a > 'H')
			continue;

		// Destination of piece
		printf("Where do you want to move piece (%c%c)? ", a, b);
		scanf(" %c%c", &c, &d);
		printf("c: %d, d: %d\n", c, d);
		if(d < '1' || d > '8')
			continue;
		if(c < 'A' || c > 'H')
			continue;

		// Implement the rules for moving and capturing checkers.
		if(move_is_invalid(player_turn, a, b, c, d))
		{
			printf("Given move is invalid. Enter some other move to play.\n");
			continue;
		}
		move_piece(player_turn, a, b, c, d);

		// Check for game over conditions and set the game_over variable accordingly.
		if(is_game_over())
		{
			game_over = 1;
			break;
		}

		// Toggle player turn
		player_turn = -player_turn;
	}
	printf("Game Over! The winner is %c.\n", (player_turn == 1) ? 'X' : 'O');
	print_board();
	return 0;
}