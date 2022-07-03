#include "alcu.h"
#include "bonus.h"
#include "game.h"

static void print_stick_line(WINDOW *game_screen, int num, int y) {
	char* stick[5] =   {" ,-, ",
						",-.| ",
						"| || ",
						"; |, ",
						"'-'  ",};

	int w = getmaxx(game_screen);
	int start = w / 2 - 5 * num / 2;
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

void	print_screen(t_game *game, WINDOW *game_screen)
{

	werase(game_screen);
	mvwaddstr(game_screen, 0, 0, "SCREEN");
	for (int i = 0; game->heap[i].num != 0; i++)
	{
		print_stick_line(game_screen, game->heap[i].num, 2 + i * 5);
	}
	wrefresh(game_screen);
}