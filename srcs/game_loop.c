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

void	start_game(t_game *game)
{
	while (!is_game_over(game))
	{
		print_map(game);
		if(game->player_turn) {
			pick_item_player(game);
		} else {
			pick_item_ai(game);
		}
		game->player_turn = !game->player_turn;
	}
	announce_winner(game);
	free_gnl_buf();
}
