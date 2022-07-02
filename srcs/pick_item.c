#include "alcu.h"

void	pick_items(t_game *game, int pick)
{
	debug_print(game);
	int i = game->index;
	if (game->map[i] >= pick) {
		game->map[i] -= pick;
	} else {
		game->map[i] = 0;
	}
	if (game->index != 0 && game->map[i] == 0)
		game->index--;
}
