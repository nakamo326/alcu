#include "alcu.h"
#include "bonus.h"
#include "game.h"
#include "image.h"

void	print_screen(t_game *game, t_image **images, WINDOW *game_screen)
{
	int center = SCREEN_W / 2;
	
	werase(game_screen);
	mvwaddstr(game_screen, 0, 0, "SCREEN");

	// 描画するのは直近3行
	int h_index = 1;
	for (int i = 0; i < 3; i++)
	{
		if (game->index - 2 + i < 0) {
			h_index += images[i]->img_h;
			continue;
		}
		print_img(game_screen, images[i], game->heap[game->index - 2 + i].num, h_index, center);
		h_index += images[i]->img_h;
	}
	wrefresh(game_screen);
}
