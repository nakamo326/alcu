#include "alcu.h"
#include "bonus.h"
#include "game.h"

void	print_screen(t_game *game, WINDOW *screen)
{
	(void)screen;
	mvprintw(1, 1, "screen\n");
	for (int i = 0; game->heap[i].num != 0; i++)
	{
		for (int j = 0; j < game->heap[i].num; j++)
		{
			printw("| ");
		}
		printw(" ");
	}
}

void	start_bonus_game(t_game *game)
{
	t_window window;

	initscr();
	getmaxyx(stdscr, window.h, window.w);
	init_window();
	window.prompt = init_prompt(&window);
	char input[10];
	int pick = 0;
	while (!is_game_over(game))
	{
		int key = getch();
		if (key == 'c') {
			break;
		}
		// keypad(window.prompt, TRUE);
		echo();
		mvscanw(window.h - 1, 10, ">>", &input);
		mvprintw(window.h - 2, 1, input);
		refresh();
		noecho();
		if(game->player_turn) {
			pick_items(game, pick);
		} else {
			pick = solver(game);
			pick_items(game, pick);
		}
		print_screen(game, window.game_screen);
		game->player_turn = !game->player_turn;
	}
	endwin();
	// announce_winner(game);
}
