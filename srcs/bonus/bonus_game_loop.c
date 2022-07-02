#include "alcu.h"
#include "bonus.h"
#include "game.h"

void	start_bonus_game(t_game *game)
{
	// init window
	while (!is_game_over(game))
	{
		// get_input from nsurses

		if(game->player_turn) {
			// pick_items(game, pick);
		} else {
			int pick = solver(game);
			pick_items(game, pick);
		}
		game->player_turn = !game->player_turn;
	}
	// announce_winner(game);
}