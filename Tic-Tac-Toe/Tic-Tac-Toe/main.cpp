#include <iostream>
#include <string>

#include "player.h"
#include "board.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main() {
	string padding = string(12, '*');
	cout << padding << endl << "Tic-Tac-Toe" << endl << padding << endl;
	cout << "Valid moves are {row} {column} i.e. 1 1 being the centre block." << endl;

	Player player1('X');
	Player player2('O');
	Board board;

	board.print_board();


	// game loop
	while (true) {
		// player 1's turn
		if (board.is_winner(player1.get_name(), player1.get_marker()) || board.is_winner(player2.get_name(), player2.get_marker())) {
			return 0;
		}
		if (board.is_tie()) {
			return 0;
		}
		while (!(board.submit_move(player1.get_player_move(), player1.get_name(), player1.get_marker()))) {
			continue;
		}
		board.print_board();

		// player 2's turn
		if (board.is_winner(player1.get_name(), player1.get_marker()) || board.is_winner(player2.get_name(), player2.get_marker())) {
			return 0;
		}
		if (board.is_tie()) {
			return 0;
		}
		board.submit_move(player2.get_player_move(), player2.get_name(), player2.get_marker());
		board.print_board();
	}

	return 0;
}