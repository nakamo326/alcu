#include "alcu.h"

// 後で削除！！！！

void debug_print(t_game *game) {
	puts("===============================");
	printf("index       : %d\n", game->index);
	printf("current heap: %d\n", game->map[game->index]);
	printf("is_player_turn: %d\n", game->player_turn);
	puts("===============================");
}