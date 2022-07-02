#include "game.h"

bool is_game_over(t_game *game) {
	return game->index == 0 && (game->map[0] == 1 || game->map[0] == 0);
}