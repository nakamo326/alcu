#include "bonus.h"


void 	print_view_screen(t_game *game, t_image **images, WINDOW *game_screen, int view_index){
	int center = SCREEN_W / 2;
	
	werase(game_screen);
	mvwaddstr(game_screen, 0, 0, "VIEW");

	// 描画するのはview_indexを中心に4行
	int h_index = 1;
	for (int i = 0; i < 3; i++)
	{
		if (view_index - 2 + i < 0) {
			h_index += images[i]->img_h;
			continue;
		}
		print_img(game_screen, images[i], game->heap[view_index - 2 + i].num, h_index, center);
		h_index += images[i]->img_h;
	}
	if (view_index + 1 <= game->index) {
		print_img(game_screen, images[1], game->heap[view_index + 1].num, h_index, center);
	}
	wrefresh(game_screen);
}
