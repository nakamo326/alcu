#include "bonus.h"

void init_window() {
	initscr();
	start_color();
	init_pair(1,COLOR_WHITE,COLOR_BLUE);
	init_pair(2,COLOR_BLUE,COLOR_WHITE);
	init_pair(3,COLOR_GREEN,COLOR_WHITE);
	curs_set(0);
	noecho();
}

WINDOW* init_prompt(t_window* window) {
	WINDOW *prompt = subwin(stdscr, 3, window->w, window->h - 3, 0);
	wbkgd(prompt,COLOR_PAIR(2));
	wattron(prompt,COLOR_PAIR(3));
	waddstr(prompt,"PROMPT");
    wattroff(prompt,COLOR_PAIR(3));
	return prompt;
}