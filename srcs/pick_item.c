#include "alcu.h"

void	pick_items(t_game *game, int pick)
{
	debug_print(game);
	int i = game->index;
	if (game->heap[i].num >= pick) {
		game->heap[i].num -= pick;
	} else {
		game->heap[i].num = 0;
	}
	if (game->index != 0 && game->heap[i].num == 0)
		game->index--;
}
