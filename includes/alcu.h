/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aicu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:10:05 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 19:43:51 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# include "get_next_line.h"

# include <stdio.h>

typedef struct s_game
{
	int		*map;
	int		index;
	bool	player_turn;
}	t_game;

void debug_print(t_game *game);

bool	parse_map(t_game *game, int input_fd);
void	print_map(t_game *game);

void	start_game(t_game *game);
void	ai(t_game *game);
void	player(t_game *game);

void	pick_items(t_game *game, int pick);

#endif
