#include <stdbool.h>

#include "tictt.h"
#include "bot.h"

bool defense_diagonal_right_to_left()
{

	// right to left
	// get the last empty square
	bool still_is_searching_right_to_left = true;

	short line_index = 0;
	short column_index = 2;
	unsigned short invalid_diagonal_squares_right = 0;
	bool diagonal_right_to_left_is_safe = false;
	while (still_is_searching_right_to_left) {
		if (board[line_index][column_index] == 'O') {
			diagonal_right_to_left_is_safe = true;
			still_is_searching_right_to_left = false;
			break;
		} else if (board[line_index][column_index] == 'X') {
			invalid_diagonal_squares_right++;
		}


		line_index++;
		column_index--;

		if (line_index == 3) {
			still_is_searching_right_to_left = false;
		}
	}


	if (!diagonal_right_to_left_is_safe && invalid_diagonal_squares_right == 2) {
		unsigned short line_index = 0;
		unsigned short column_index = 0;
		bool diagonal_left_to_right_is_safe = false;
		bool still_is_searching_left_to_right = true;
		while (still_is_searching_left_to_right) {
			if (board[line_index][column_index] == '\0') {
				board[line_index][column_index] = 'O';
				still_is_searching_left_to_right = false;
				return true;
			}

			line_index++;
			column_index++;


			if (line_index == 3) {
				still_is_searching_left_to_right = false;
			}
		}
	}

	return false;
}

bool defense_diagonal_left_to_right()
{

	// left to right
	// get the last empty square
	bool still_is_searching_left_to_right = true;

	unsigned short line_index = 0;
	unsigned short column_index = 0;
	unsigned short invalid_diagonal_squares_left = 0;
	bool diagonal_left_to_right_is_safe = false;
	while (still_is_searching_left_to_right) {
		if (board[line_index][column_index] == 'O') {
			diagonal_left_to_right_is_safe = true;
			still_is_searching_left_to_right = false;
			break;
		} else if (board[line_index][column_index] == 'X') {
			invalid_diagonal_squares_left++;
		}


		line_index++;
		column_index++;

		if (line_index == 3) {
			still_is_searching_left_to_right = false;
		}
	}


	if (!diagonal_left_to_right_is_safe && invalid_diagonal_squares_left == 2) {
		unsigned short line_index = 0;
		unsigned short column_index = 0;
		bool diagonal_left_to_right_is_safe = false;
		bool still_is_searching_left_to_right = true;
		while (still_is_searching_left_to_right) {
			if (board[line_index][column_index] == '\0') {
				board[line_index][column_index] = 'O';
				still_is_searching_left_to_right = false;
				return true;
			}

			line_index++;
			column_index++;


			if (line_index == 3) {
				still_is_searching_left_to_right = false;
			}
		}
	}

	return false;
}

bool defense_column(short index)
{
	// column
	bool column_is_safe = false;
	char column_array[3];
	for (short index_line = 0; index_line < 3; index_line++) {
		column_array[index_line] = board[index_line][index];
		if (board[index_line][index] == 'O') {
			column_is_safe = true;
		}
	}

	if (unique_element(column_array, 3, '\0')) {
		column_is_safe = true;
	}

	// validating if the player is close to complete the line
	short quantity_of_invalid_squares_column = 0;
	for (short index_line = 0; index_line < 3; index_line++) {
		if (board[index_line][index] == 'X') {
			quantity_of_invalid_squares_column++;
		}
	}

	if (!column_is_safe && quantity_of_invalid_squares_column == 2) {
		for (short index_line = 0; index_line < 3; index_line++) {
			if (board[index_line][index] != 'X') {
				board[index_line][index] = 'O';
				return true;
				break;
			}
		}
	}

	return false;
}

bool defense_line(short index)
{

	// line
	bool line_is_safe = false;
	for (short index_column = 0; index_column < 3; index_column++) {
		if (board[index][index_column] == 'O') {
			line_is_safe = true;
		}
	}

	if (unique_element(board[index], 3, '\0')) {
		line_is_safe = true;
	}

	// validating if the player is close to complete the line
	short quantity_of_invalid_squares = 0;
	for (short index_column = 0; index_column < 3; index_column++) {
		if (board[index][index_column] == 'X') {
			quantity_of_invalid_squares++;
		}
	}

	if (!line_is_safe && quantity_of_invalid_squares == 2) {
		for (short index_column = 0; index_column < 3; index_column++) {
			if (board[index][index_column] != 'X') {
				board[index][index_column] = 'O';
				return true;
				break;
			}
		}
	}

	return false;
}

