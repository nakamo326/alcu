#include "alcu.h"
#include "bonus.h"
#include "game.h"

#include <ncurses.h>

void	start_bonus_game(t_game *game)
{
	t_window window;

	initscr();
	getmaxyx(stdscr, window.h, window.w);
	init_window();
	window.prompt = init_prompt(&window);
    refresh();
	while (!is_game_over(game))
	{
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
