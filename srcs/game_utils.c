#include "game.h"
#include "libft.h"

bool is_game_over(t_game *game) {
	return game->index == 0 && (game->map[0] == 1 || game->map[0] == 0);
}

void announce_winner(t_game *game) {
	printf("ds->map[0]: %d\n", game->map[0]);
	printf("is_player_turn: %d\n", game->player_turn);
	if (game->map[0] == 1 && game->player_turn) {
		ft_putendl_fd("AI's win! you lose.", STDOUT_FILENO);
	} else if (game->map[0] == 0 && game->player_turn) {
		ft_putendl_fd("player's win! you won.", STDOUT_FILENO);
	} else if (game->map[0] == 0 && !game->player_turn) {
		ft_putendl_fd("AI's win! you lose.", STDOUT_FILENO);
	} else {
		ft_putendl_fd("player's win! you won.", STDOUT_FILENO);
	}
}
