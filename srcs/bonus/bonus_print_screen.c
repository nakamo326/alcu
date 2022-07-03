#include "alcu.h"
#include "bonus.h"
#include "game.h"
#include "image.h"

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

void	print_screen(t_game *game, t_image **images, WINDOW *game_screen)
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
		print_img(game_screen, images[1], game->heap[i].num, 2 + i * images[1]->img_h, center);
	}
	wrefresh(game_screen);
}
