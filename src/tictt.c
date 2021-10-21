#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

// headers 
#include "tictt.h"

char board_line_letters[3] = {'A', 'B', 'C'};

bool game_is_end()
{
	// line
	for (short index_line = 0; index_line < 3; index_line++) {
		if (board[index_line][0] == board[index_line][1] &&
				board[index_line][1] == board[index_line][2] && board[index_line][2] != '\0') {

			if (board[index_line][0] == 'O') {
				winner_player = 2;
			} else if (board[index_line][0] == 'X') {
				winner_player = 1;
			}

			return true;
		}

	}

	// column
	for (short index_column = 0; index_column < 3; index_column++) {
		if (board[0][index_column] == board[1][index_column] &&
				board[1][index_column] == board[2][index_column] && board[2][index_column] != '\0') {


			if (board[1][index_column] == 'O') {
				winner_player = 2;
			} else if (board[1][index_column] == 'X') {
				winner_player = 1;
			}

			return true;
		}
	}

	// diagonal
	if ((board[0][0] == board[1][1] &&
				board[1][1] == board[2][2] && board[2][2] != '\0') ||
			(board[0][2] == board[1][1] &&
			 board[1][1] == board[2][0] && board[2][0] != '\0' )) {


		if (board[1][1] == 'O') {
			winner_player = 2;
		} else if (board[1][1] == 'X') {
			winner_player = 1;
		}

		return true;
	}

	return false;
}


void display_board() 
{
	printf("\n   0 1 2 \n"); // column number
	for (short indexLine = 0; indexLine < 3; indexLine++) {
		printf("%c ", board_line_letters[indexLine]); // line letter

		for (short indexSquare = 0; indexSquare < 3; indexSquare++) {
			printf("|%c", (board[indexLine][indexSquare] != '\0' ? board[indexLine][indexSquare] : ' '));
		}

		printf("|\n"); // break line for each line
	}
}

bool make_a_movement(char input[10], bool first_player) 
{
	char line_character = toupper(input[0]);
	short line_index = return_character_index(line_character);
	short column_number = atoi(&input[1]);

	if (board[line_index][column_number] == '\0') {
		board[line_index][column_number] = (first_player ? 'X' : 'O');
		return true;
	}

	return false;

}

short return_character_index(char character) 
{
	for (short index = 0;index < 3; index++) {
		if (board_line_letters[index] == character) {
			return index;
		}
	}

	return 2;
}



