#include "alcu.h"
#include "bonus.h"
#include "game.h"

void	print_screen(t_game *game, WINDOW *screen)
{
	werase(screen);
	mvwaddstr(screen, 0, 0, "SCREEN");
	wmove(screen, 2,1);
	for (int i = 0; game->heap[i].num != 0; i++)
	{
		for (int j = 0; j < game->heap[i].num; j++)
		{
			wprintw(screen, "| ");
		}
		wmove(screen, 2 + i + 1, 1);
	}
	wrefresh(screen);
}

static void print_item_pick_message(t_window *window, int pick) {
	werase(window->prompt);
	mvwaddstr(window->prompt, 0, 0, "PROMPT");
	mvwprintw(window->prompt, 1, 1, "AI took %d. it's your turn!", pick);
	wrefresh(window->prompt);
}

static void print_prompt_winner(t_game *game, t_window *window) {
	werase(window->prompt);
	if (game->heap[0].num == 1 && game->player_turn) {
		mvwaddstr(window->prompt, 1, 1, "AI's win! you lose.");
	} else if (game->heap[0].num == 0 && game->player_turn) {
		mvwaddstr(window->prompt, 1, 1, "player's win! you won.");
	} else if (game->heap[0].num == 0 && !game->player_turn) {
		mvwaddstr(window->prompt, 1, 1, "AI's win! you lose.");
	} else {
		mvwaddstr(window->prompt, 1, 1, "player's win! you won.");
	}
	wrefresh(window->prompt);
}


void	start_bonus_game(t_game *game)
{
	t_window window;

	init_window(&window);
	mvwaddstr(window.prompt, 1, 1, "Press any key to start game.");
	while (!is_game_over(game))
	{
		print_screen(game, window.game_screen);
		refresh();
		echo();
		int key = getch();
		if (key == 'c') {
			break;
		}
		noecho();
		int pick = 0;
		if ('1' <= key && key <= '3')
			pick = key - '0';
		if(game->player_turn && pick != 0) {
			pick_items(game, pick);
			game->player_turn = !game->player_turn;
			if (is_game_over(game)) {
				break;
			}
		}
		if (!game->player_turn) {
			pick = solver(game);
			pick_items(game, pick);
			print_item_pick_message(&window, pick);
			game->player_turn = !game->player_turn;
		}
	}
	print_screen(game, window.game_screen);
	print_prompt_winner(game, &window);
	getch();
	endwin();
}
