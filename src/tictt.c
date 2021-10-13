#include <stdio.h>
#include <stdbool.h>

// headers 
#include "tictt.h"

char board[3][3];

bool game_is_end()
{
	// line
	for (short index_line = 0; index_line < 3; index_line++) {
		if (board[index_line][0] == board[index_line][1] &&
				board[index_line][1] == board[index_line][2]) {
			return true;
		}
	}

	// column
	for (short index_column = 0; index_column < 3; index_column++) {
		if (board[0][index_column] == board[1][index_column] &&
				board[1][index_column] == board[2][index_column]) {
			return true;
		}
	}

	// diagonal
	if ((board[0][0] == board[1][1] &&
			board[1][1] == board[2][2]) ||
			(board[0][2] == board[1][1] &&
			 board[1][1] == board[2][0])) {
		return true;
	}

	return false;
}


char which_player_win()
{
	return 'X';
}

void display_board() 
{
	for (short indexLine = 0; indexLine < 3; indexLine++) {
		for (short indexSquare = 0; indexSquare < 3; indexSquare++) {
			printf("|%c", board[indexLine][indexSquare]);
		}
		printf("|\n");
	}
}
