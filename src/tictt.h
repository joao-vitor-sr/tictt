char board[3][3];
char board_line_letters[] = {'A', 'B', 'C'};

bool game_is_end();
void display_board();
bool make_a_movement(char input[3], bool first_player);
short return_character_index(char character);
