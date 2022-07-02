#include "game.h"

bool is_game_over(t_data *ds) {
	return ds->index == 0 && (ds->map[0] == 1 || ds->map[0] == 0);
}