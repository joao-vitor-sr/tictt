#include <stdbool.h>

#include "bot.h"
#include "tictt.h"

bool bot_line_movement()
{
	// line
	for (short index_line = 0; index_line < 3; index_line++) {
		bool line_is_invalid = false;
		// validating if at line exist some charater of the player
		for (short index_column = 0; index_column < 3; index_column++) {
			if (board[index_line][index_column] == 'X') {
				line_is_invalid = true;
				break;
			}

		}

		if (line_is_invalid) {
			line_is_invalid = false;
			continue;
		}

		// get the last empty square
		for (short index_column = 0; index_column < 3; index_column++) {
			if (board[index_line][index_column] == '\0') {
				board[index_line][index_column] = 'O';
				return true;
				break;
			}
		}
		break;
	}

	return false;
}

bool bot_column_movement()
{
	// column
	for (short index_column = 0; index_column < 3; index_column++) {
		bool column_is_invalid = false;
		// validating if at line exist some charater of the player
		for (short index_line = 0; index_line < 3; index_line++) {
			if (board[index_line][index_column] == 'X') {
				column_is_invalid = true;
				break;
			}

		}

		if (column_is_invalid) {
			column_is_invalid = false;
			continue;
		}

		// get the last empty square
		for (short index_line = 0; index_line < 3; index_line++) {
			if (board[index_line][index_column] == '\0') {
				board[index_line][index_column] = 'O';
				return true;
				break;
			}
		}
		break;
	}

	return false;
}

bool bot_diagonal_movement()
{

	// -- diagonal --

	// diagonal (right to left)
	bool diagonal_right_to_left_is_valid = true;
	if (board[0][2] == 'X' ||
			board[1][1] == 'X' || 
			board[2][0] == 'X') {
		diagonal_right_to_left_is_valid = false;

	}

	if (diagonal_right_to_left_is_valid) {
		// get the last empty square
		bool still_is_searching = true;

		unsigned short line_index = 0;
		unsigned short column_index = 2;
		while (still_is_searching) {
			if (board[line_index][column_index] == '\0') {
				board[line_index][column_index] = 'O';
				return true;
			}

			if (column_index == 0) {
				still_is_searching = false;
				break;
			}

			column_index--;
			line_index++;
		}

	}

	// diagonal (left to right)
	bool diagonal_left_to_right_is_valid = true;
	if (board[0][0] == 'X' ||
			board[1][1] == 'X' || 
			board[2][2] == 'X') {
		diagonal_left_to_right_is_valid = false;

	}

	if (diagonal_left_to_right_is_valid) {
		// get the last empty square
		bool still_is_searching = true;

		unsigned short line_index = 0;
		unsigned short column_index = 0;
		while (still_is_searching) {
			if (board[line_index][column_index] == '\0') {
				board[line_index][column_index] = 'O';
				return true;
			}

			if (column_index == 0) {
				still_is_searching = false;
				break;
			}

			column_index++;
			line_index++;
		}

	}

	return false;
}

void make_bot_movement() 
{

	// line
	if (bot_line_movement()) {
		return;
	}

	// column
	if (bot_column_movement()) {
		return;
	}

	if (bot_diagonal_movement()) {
		return;
	}

}
