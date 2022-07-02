#include "bonus.h"

#include <ncurses.h>

void init_window() {
	initscr();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_RED,COLOR_WHITE);
	curs_set(0);
	noecho();
}

WINDOW* init_prompt(t_window* window) {
	WINDOW *prompt = subwin(stdscr, 2, window->w, window->h - 2, 0);
	wbkgd(prompt,COLOR_PAIR(2));
	waddstr(prompt,"Menu1");
	wattron(prompt,COLOR_PAIR(3));
	waddstr(prompt,"(F1)");
    wattroff(prompt,COLOR_PAIR(3));
	return prompt;
}