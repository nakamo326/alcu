#ifndef INCLUDES_BONUS_H
#define INCLUDES_BONUS_H

#include "alcu.h"

#include <curses.h>

typedef struct s_window {
	int		w;
	int		h;
	WINDOW*	prompt;
	WINDOW*	game_screen;
} t_window;

void	start_bonus_game(t_game *game);
void	init_window(t_window *window);
WINDOW* init_prompt(t_window *window);
WINDOW* init_game_screen(t_window *window);

void	print_screen(t_game *game, WINDOW *game_screen);

#endif /* INCLUDES_BONUS_H */
