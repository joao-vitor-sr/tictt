#include <stdio.h>
#include <stdbool.h>

// headers
#include "tictt.h"
#include "main.h"

int main() 
{
	get_player_configuration();
	return 1;
}

void get_player_configuration() 
{
	printf("What is your name? ");
	char line_first_player[253];

	if (fgets(line_first_player, sizeof(line_first_player), stdin) == NULL) {
		name_of_first_player = "player-one";
	}

	name_of_first_player = line_first_player;

	if (!player_is_playing_alone()) { 
		player_is_alone = false;

		printf("What is the second player name? ");
		char line_second_player[253];

		if (fgets(line_second_player, sizeof(line_second_player), stdin) == NULL) {
			name_of_second_player = "player-two";
		}

		name_of_second_player = line_second_player;
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
