#include "bonus.h"

void init_window(t_window *window) {
	initscr();
	// start_color();
	// init_pair(1,COLOR_WHITE,COLOR_BLUE);
	// init_pair(2,COLOR_BLUE,COLOR_WHITE);
	// init_pair(3,COLOR_GREEN,COLOR_WHITE);
	curs_set(0);
	noecho();
	getmaxyx(stdscr, window->h, window->w);
	window->game_screen = init_game_screen(window);
	window->prompt = init_prompt(window);
}

WINDOW* init_prompt(t_window* window) {
	WINDOW *prompt = subwin(stdscr, 3, window->w, window->h - 3, 0);
	return prompt;
}

WINDOW* init_game_screen(t_window* window) {
	WINDOW *game_screen = subwin(stdscr, window->h - 3, window->w, 0, 0);
	return game_screen;
}