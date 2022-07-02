#include "alcu.h"
#include "bonus.h"
#include "game.h"

#include <curses.h>

void	start_bonus_game(t_game *game)
{
	initscr();
	curs_set(0);
	noecho();
	while (!is_game_over(game))
	{
		// get_input from nsurses
		int key = getch();
		if (key == 'c') {
			break;
		}
		// if(game->player_turn) {
		// 	// pick_items(game, pick);
		// } else {
		// 	int pick = solver(game);
		// 	pick_items(game, pick);
		// }
		game->player_turn = !game->player_turn;
	}
	endwin();
	// announce_winner(game);
}