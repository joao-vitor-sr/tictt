char board[3][3];

bool game_is_end();
void display_board();
bool make_a_movement(char input[3], bool first_player);
short return_character_index(char character);

short winner_player; // 1 - main, 2 - secondary;
