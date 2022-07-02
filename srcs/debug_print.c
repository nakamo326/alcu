#include "alcu.h"

// 後で削除！！！！

void debug_print(t_data *ds) {
	puts("===============================");
	printf("index       : %d\n", ds->index);
	printf("current heap: %d\n", ds->map[ds->index]);
	printf("is_player_turn: %d\n", ds->player_turn);
	puts("===============================");
}