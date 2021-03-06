#ifndef GUARD_BOARD_H
#define GUARD_BOARD_H

#include "player.h"

class Board {
public:
	Board();
	void print_board();
	bool submit_move(Player player);
	bool is_winner(Player player);
	bool is_tie();

private:
	char board[3][3];
	unsigned int empty_tiles;
};

#endif