/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:04:55 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 20:31:30 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "game.h"
#include "get_next_line.h"
#include "libft.h"

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

void	start_game(t_game *game)
{
	bool is_end = false;

	while (!is_end)
	{
		print_map(game);
		if(game->player_turn) {
			player(game);
			// pick_item_player(game);
		} else {
			ai(game);
			// pick_item_ai(game);
		}
		game->player_turn = !game->player_turn;
		is_end = is_game_over(game);
	}
	announce_winner(game);
	free_gnl_buf();
}
