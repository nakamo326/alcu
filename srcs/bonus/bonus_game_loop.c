#include "alcu.h"
#include "bonus.h"
#include "game.h"

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

	if (!init_window(&window)){
		return;
	}
	mvwaddstr(window.prompt, 0, 0, "PROMPT");
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
	if (is_game_over(game)) {
		print_screen(game, window.game_screen);
		print_prompt_winner(game, &window);
		getch();
	}
	endwin();
}
