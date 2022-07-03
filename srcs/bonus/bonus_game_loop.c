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
	bool		is_game_start = false;
	bool		is_view_mode = false;
	int			view_index = -1;
	t_window	window;
	t_image		*images[3] = {NULL, NULL, NULL};

	if (!init_window(&window)){
		return;
	}
	if (!init_images(images)) {
		endwin();
		ft_putendl_fd("image malloc error.", STDERR_FILENO);
		delete_images(images);
		return;
	}
	mvwaddstr(window.prompt, 0, 0, "PROMPT");
	mvwaddstr(window.prompt, 1, 1, "Press space key to start game.");
	while (!is_game_over(game))
	{
		if (is_view_mode) {
			print_view_screen(game, images, window.game_screen, view_index);
		} else {
			print_screen(game, images, window.game_screen);
		}
		refresh();
		int pick = 0;
		int key = getch();
		mvwprintw(window.prompt, 2, 1, "got key input: %c" , (char)key);
		wrefresh(window.prompt);
		if (key == 'c') {
			break;
		}
		if (key == ' ') {
			is_game_start = true;
		}
		if (!is_game_start) {
			continue;
		}
		if (key == 'v') {
			is_view_mode = !is_view_mode;
			view_index = game->index;
			continue;
		}
		if (is_view_mode && key == 'w') {
			if (view_index != 0)
				view_index--;
			continue;
		}
		if (is_view_mode && key == 's') {
			if (view_index < game->index)
				view_index++;
			continue;
		}
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
		print_screen(game, images, window.game_screen);
		print_prompt_winner(game, &window);
		getch();
	}
	delete_images(images);
	endwin();
}
