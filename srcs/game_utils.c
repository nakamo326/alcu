#include "game.h"
#include "libft.h"

bool is_game_over(t_game *game) {
	return game->index == 0 && (game->heap[0].num == 1 || game->heap[0].num == 0);
}

void announce_winner(t_game *game) {
	printf("ds->heap[0].num: %d\n", game->heap[0].num);
	printf("is_player_turn: %d\n", game->player_turn);
	if (game->heap[0].num == 1 && game->player_turn) {
		ft_putendl_fd("AI's win! you lose.", STDOUT_FILENO);
	} else if (game->heap[0].num == 0 && game->player_turn) {
		ft_putendl_fd("player's win! you won.", STDOUT_FILENO);
	} else if (game->heap[0].num == 0 && !game->player_turn) {
		ft_putendl_fd("AI's win! you lose.", STDOUT_FILENO);
	} else {
		ft_putendl_fd("player's win! you won.", STDOUT_FILENO);
	}
}
