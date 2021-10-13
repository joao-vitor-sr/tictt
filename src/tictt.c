#include <stdio.h>

char board[3][3];

void display_board(short line) 
{
	for (short indexLine = 0; indexLine < 3; indexLine++) {
		for (short indexSquare = 0; indexSquare < 3; indexSquare++) {
			printf("|%c", board[indexLine][indexSquare]);
		}
		printf("|\n");
	}
}
