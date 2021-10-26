#include <stdbool.h>
#include <stdio.h>

#include "bot.h"
#include "tictt.h"
#include "bot_defense.h"
#include "bot_attack.h"

bool unique_element(char array[], short array_index, char char_to_compare)
{
	for (short index = 0; index < array_index; index++) {
		if (array[index] != char_to_compare) {
			return false;
		}
	}

	return true;
}

bool bot_defense() 
{
	for (short index = 0; index < 3; index++) {
		if (defense_line(index)) {
			return true;
		}

		if (defense_column(index)) {
			return true;
		}

	}

	// diagonal

	if (defense_diagonal_left_to_right()) {
		return true;
	}

	if (defense_diagonal_right_to_left()) {
		return true;
	}

	return false;
}

void make_bot_attack() 
{

	for (short index = 0; index < 3; index++) {

		// line
		short line_bot_mark = 0;
		for (short index_column = 0; index_column < 3; index_column++) {
			if (board[index][index_column] == 'O') {
				line_bot_mark++;
			}
		}

		if (line_bot_mark == 2) {
			if (bot_line_attack()) {
				return;
				break;
			}
		}

		// column
		short column_bot_mark = 0;
		for (short index_line = 0; index_line < 3; index_line++) {
			if (board[index_line][index] == 'O') {
				column_bot_mark++;
			}
		}

		if (column_bot_mark == 2) {
			if (bot_column_attack()) {
				return;
				break;
			}
		}

	}

	// diagonal

	bool still_is_searching_diagonal_right_to_left = true;

	short index_line = 0;
	short index_column = 2;
	short column_bot_mark_right_left = 0;

	while (still_is_searching_diagonal_right_to_left) {
		if (board[index_line][index_column] == 'O') {
			column_bot_mark_right_left++;
		}

		if (bot_diagonal_attack()) {
			return;
		}

		if (index_line <= 2) {
			index_line++;
			index_column--;
			continue;
		}

		still_is_searching_diagonal_right_to_left = false;

		break;
	}

	if (column_bot_mark_right_left == 2) {
		bot_diagonal_attack();
	}

	bool still_is_searching_diagonal_left_to_right = true;

	index_line = 0;
	index_column = 0;
	column_bot_mark_right_left = 0;

	while (still_is_searching_diagonal_left_to_right) {
		if (board[index_line][index_column] == 'O') {
			column_bot_mark_right_left++;
		}

		if (bot_diagonal_attack()) {
			return;
		}

		if (index_line <= 2) {
			index_line++;
			index_column++;
			continue;
		}

		still_is_searching_diagonal_left_to_right = false;

		break;
	}

	if (column_bot_mark_right_left == 2) {
		bot_diagonal_attack();
	}

	// defense
	if (bot_defense()) {
		return;
	}

	// line
	if (bot_line_attack()) {
		return;
	}

	// column
	if (bot_column_attack()) {
		return;
	}

	// diagonal
	if (bot_diagonal_attack()) {
		return;
	}

	// TIE
	bot_random_attack();
}
