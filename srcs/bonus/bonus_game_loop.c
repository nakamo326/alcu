#include "alcu.h"
#include "bonus.h"
#include "game.h"

void	print_screen(t_game *game, WINDOW *screen)
{
	(void)screen;
	// erase();
	mvprintw(1, 1, "screen\n");
	move(2,1);
	for (int i = 0; game->heap[i].num != 0; i++)
	{
		for (int j = 0; j < game->heap[i].num; j++)
		{
			printw("| ");
		}
		move(2 + i, 1);
	}
}

static void print_item_pick_message(t_window window, int pick) {
	// move(window.h - 2, 1);
	wattron(window.prompt,COLOR_PAIR(3));
	mvprintw(window.h - 2, 1, "AI took %d. it's your turn!", pick);
	mvwprintw(window.prompt, window.h - 2, 1, "AI took %d. it's your turn!", pick);
	wattroff(window.prompt,COLOR_PAIR(3));
}

void	start_bonus_game(t_game *game)
{
	t_window window;

	initscr();
	getmaxyx(stdscr, window.h, window.w);
	init_window();
	window.prompt = init_prompt(&window);
	while (!is_game_over(game))
	{
		print_screen(game, window.game_screen);
		refresh();
		int key = getch();
		if (key == 'c') {
			break;
		}
		int pick = 0;
		if ('1' <= key && key <= '3')
			pick = key - '0';
		if(game->player_turn && pick != 0) {
			pick_items(game, pick);
			game->player_turn = !game->player_turn;
			continue;
		}
		if (!game->player_turn) {
			pick = solver(game);
			pick_items(game, pick);
			print_item_pick_message(window, pick);
		}
	}
	endwin();
	// announce_winner(game);
}
