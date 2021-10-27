#include <stdbool.h>

#include "tictt.h"
#include "bot.h"

bool validate_line_attack(short index_line)
{

	for (short index_column = 0; index_column < 3; index_column++) {
		if (board[index_line][index_column] == first_player_character) {
			return false;
		}

	}

	return true;
}

short get_line_empty_column(short index_line)
{

		// get the last empty square
		for (short index_column = 0; index_column < 3; index_column++) {
			if (board[index_line][index_column] == '\0') {
				return index_column;
			}
		}

		return 3; // return a invalid index when no column was found
}

bool bot_line_attack()
{
	// line
	for (short index_line = 0; index_line < 3; index_line++) {

		if (!validate_line_attack(index_line)) {
			continue;
		}

		if (unique_element(board[index_line], 3, '\0')) {
			board[index_line][return_random_number(0, 2)] = second_player_character;
			return true;
		}


		// get the last empty square
		short empty_square = get_line_empty_column(index_line);

		if (empty_square < 3) {
			board[index_line][empty_square] = second_player_character;
			return true;
		}
	}

	return false;
}

bool bot_column_attack()
{
	// column
	for (short index_column = 0; index_column < 3; index_column++) {

		bool column_is_invalid = false;
		char column_array[3];

		// validating if at line exist some charater of the player
		for (short index_line = 0; index_line < 3; index_line++) {

			column_array[index_line] = board[index_line][index_column];

			if (board[index_line][index_column] == first_player_character) {
				column_is_invalid = true;
				break;
			}

		}

		if (column_is_invalid) {
			column_is_invalid = false;
			continue;
		}

		if (unique_element(column_array, 3, '\0')) {
			board[return_random_number(0, 2)][index_column] = second_player_character;
			return true;
		}

		// get the last empty square
		for (short index_line = 0; index_line < 3; index_line++) {
			if (board[index_line][index_column] == '\0') {
				board[index_line][index_column] = second_player_character;
				return true;
				break;
			}
		}
		break;
	}

	return false;

}

bool bot_diagonal_attack()
{

	// -- diagonal --

	// diagonal (right to left)
	bool diagonal_right_to_left_is_valid = true;
	if (board[0][2] == 'X' ||
			board[1][1] == first_player_character || 
			board[2][0] == first_player_character) {
		diagonal_right_to_left_is_valid = false;

	}

	if (diagonal_right_to_left_is_valid) {
		// get the last empty square
		bool still_is_searching = true;

		unsigned short line_index = 0;
		unsigned short column_index = 2;
		while (still_is_searching) {
			if (board[line_index][column_index] == '\0') {
				board[line_index][column_index] = second_player_character;
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
	if (board[0][0] == first_player_character ||
			board[1][1] == first_player_character || 
			board[2][2] == first_player_character) {
		diagonal_left_to_right_is_valid = false;

	}

	if (diagonal_left_to_right_is_valid) {
		// get the last empty square
		bool still_is_searching = true;

		unsigned short line_index = 0;
		unsigned short column_index = 0;
		while (still_is_searching) {
			if (board[line_index][column_index] == '\0') {
				board[line_index][column_index] = second_player_character;
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

void bot_random_attack() 
{
	// get a empty square
	for (short index_line = 0; index_line < 3; index_line++) {
		for (short index_column = 0; index_column < 3; index_column++) {
			if (board[index_line][index_column] == '\0') {
				board[index_line][index_column] = second_player_character;
				break;
			}
		}
	}
}
