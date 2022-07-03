#include "alcu.h"
#include "bonus.h"
#include "game.h"
#include "image.h"
#include "libft.h"

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
	t_bonus		bonus_info = {false, false, -1,{NULL, NULL, NULL}};
	t_window	window;

	if (!init_window(&window)){
		return;
	}
	if (!init_images(bonus_info.images)) {
		endwin();
		ft_putendl_fd("image malloc error.", STDERR_FILENO);
		delete_images(bonus_info.images);
		return;
	}
	while (!is_game_over(game))
	{
		print_screen(game, &bonus_info, window.game_screen);
		refresh();
		int key = getch();
		mvwprintw(window.prompt, 2, 1, "got key input: %c" , (char)key);
		wrefresh(window.prompt);
		if (key == 'c') {
			break;
		}
		if (key_hook(key, game, &bonus_info)) {
			continue;
		}
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
		print_screen(game, &bonus_info, window.game_screen);
		print_prompt_winner(game, &window);
		getch();
	}
	delete_images(bonus_info.images);
	endwin();
}
