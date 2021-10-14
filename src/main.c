#include <stdio.h>
#include <stdbool.h>

// headers
#include "tictt.h"
#include "main.h"

int main() 
{
	get_player_configuration();

	bool game_is_running = true;
	bool current_player_is_main = true; // true first, false player


	while (game_is_running) {
		printf("\nPlayer: %s", 
				(current_player_is_main == true ? name_of_first_player : name_of_second_player));
		display_board();

		printf("\nWhat is the next move? ");

		char line_next_move[10];

		if (fgets(line_next_move, sizeof(line_next_move), stdin) != NULL) {
			make_a_movement(line_next_move, current_player_is_main);
		}

		// validating if game is end
		if (game_is_end() == true) {

			if (winner_player == 1) {
				printf("Congratulations %s", name_of_first_player);	
				break;
			} else {
				printf("Congratulations %s", name_of_second_player);	
				break;

			}
		}

		if (!player_is_alone) {
			current_player_is_main = (current_player_is_main ? false : true);
		}

	}

	return 1;
}

void get_player_configuration() 
{
	name_of_first_player = "player-one";
	name_of_second_player = "player-two";

	printf("What is your name? ");
	char line_first_player[253];

	if (fgets(line_first_player, sizeof(line_first_player), stdin) != NULL) {
		name_of_first_player = line_first_player;
	}

	if (!player_is_playing_alone()) { 
		player_is_alone = false;

		printf("What is the second player name? ");
		char line_second_player[253];

		if (fgets(line_second_player, sizeof(line_second_player), stdin) != NULL) {
			name_of_second_player = line_second_player;
		}

	}

}

bool player_is_playing_alone() 
{
	printf("Will you play alone? (Y/n): ");

	char line[3];

	if (fgets(line, sizeof(line), stdin) != NULL && 
			(line[0] == 'Y' || line[0] == 'y')) {
		return true;
	}

	return false;
}
