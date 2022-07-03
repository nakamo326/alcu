#include "alcu.h"
#include "bonus.h"
#include "game.h"

static void print_stick_line(WINDOW *game_screen, int num, int y, int center) {
	char* stick[5] =   {" ,-, ",
						",-.| ",
						"| || ",
						"; |, ",
						"'-'  ",};

	int start = center - 5 * num / 2;
	if (start <= 0) {
		start = 0;
	}
	wmove(game_screen, y, start);
	for (int i = 0;  i < 5; i++)
	{
		for (int j = 0; j < num; j++)
		{
			wprintw(game_screen, stick[i]);
		}
		wmove(game_screen, y + i + 1, start);
	}
}

static int get_max_heap_num(t_game* game) {
	int max = -1;

	for (int i = 0; game->heap[i].num != 0; i++)
	{
		if (game->heap[i].num > max) {
			max = game->heap[i].num;
		}
	}
	return max;
}

void	print_screen(t_game *game, WINDOW *game_screen)
{
	// int h, w;
	// getmaxyx(game_screen, h, w);
	int max_heap_num = get_max_heap_num(game);
	// TODO: get_max_height (index * 5) > h;
	// TODO: max_heap_num * 5 > w;
	int center = max_heap_num * 5 / 2;
	

	werase(game_screen);
	mvwaddstr(game_screen, 0, 0, "SCREEN");
	for (int i = 0; game->heap[i].num != 0; i++)
	{
		print_stick_line(game_screen, game->heap[i].num, 2 + i * 5, center);
	}
	wrefresh(game_screen);
}