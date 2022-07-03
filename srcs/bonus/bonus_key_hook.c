#include "bonus.h"

void	key_hook(int key, t_game *game, t_bonus *bonus_info) {
	if (key == ' ') {
		bonus_info->is_game_start = true;
		return;
	}
	if (!bonus_info->is_game_start) {
		return;
	}
	if (key == 'v') {
		bonus_info->is_view_mode = !bonus_info->is_view_mode;
		bonus_info->view_index = game->index;
		return;
	}
	if (bonus_info->is_view_mode && key == 'w') {
		if (bonus_info->view_index != 0)
			bonus_info->view_index--;
		return;
	}
	if (bonus_info->is_view_mode && key == 's') {
		if (bonus_info->view_index < game->index)
			bonus_info->view_index++;
		return;
	}
}
