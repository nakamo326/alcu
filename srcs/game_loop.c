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

void announce_winner(t_data *ds) {
	printf("ds->map[0]: %d\n", ds->map[0]);
	printf("is_player_turn: %d\n", ds->player_turn);
	if (ds->map[0] == 1 && ds->player_turn) {
		ft_putendl_fd("AI's win! you lose.", STDOUT_FILENO);
	} else if (ds->map[0] == 0 && ds->player_turn) {
		ft_putendl_fd("player's win! you won.", STDOUT_FILENO);
	} else if (ds->map[0] == 0 && !ds->player_turn) {
		ft_putendl_fd("AI's win! you lose.", STDOUT_FILENO);
	} else {
		ft_putendl_fd("player's win! you won.", STDOUT_FILENO);
	}
}

void	start_game(t_data *ds)
{
	bool is_end = false;

	while (!is_end)
	{
		print_map(ds);
		if(ds->player_turn) {
			player(ds);
			// pick_item_player(ds);
		} else {
			ai(ds);
			// pick_item_ai(ds);
		}
		ds->player_turn = !ds->player_turn;
		is_end = is_game_over(ds);
	}
	announce_winner(ds);
	free_gnl_buf();
}
