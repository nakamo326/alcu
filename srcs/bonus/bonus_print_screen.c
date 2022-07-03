#include "alcu.h"
#include "bonus.h"
#include "game.h"
#include "image.h"

void	print_game_screen(t_game *game, t_image **images, WINDOW *game_screen)
{
	int center = SCREEN_W / 2;
	
	werase(game_screen);
	mvwaddstr(game_screen, 0, 0, "GAME");

	// 描画するのは直近3行
	int h_index = 1;
	for (int i = 0; i < 3; i++)
	{
		if (game->index - 2 + i < 0) {
			h_index += images[i]->img_h;
			continue;
		}
		print_img(game_screen, images[i], &game->heap[game->index - 2 + i], h_index, center);
		h_index += images[i]->img_h;
	}
	wrefresh(game_screen);
}

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
		print_img(game_screen, images[i], &game->heap[view_index - 2 + i], h_index, center);
		h_index += images[i]->img_h;
	}
	if (view_index + 1 <= game->index) {
		print_img(game_screen, images[1], &game->heap[view_index + 1], h_index, center);
	}
	wrefresh(game_screen);
}

void print_screen(t_game *game, t_bonus *bonus_info, WINDOW * game_screen) {
	if (bonus_info->is_view_mode) {
		print_view_screen(game, bonus_info->images, game_screen, bonus_info->view_index);
	} else {
		print_game_screen(game, bonus_info->images, game_screen);
	}
}
