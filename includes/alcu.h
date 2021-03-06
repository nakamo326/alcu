/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alcu.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:10:05 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/02 13:40:49 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AICU_H
# define AICU_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>

# include <stdio.h>

typedef enum e_mode {
	WIN,
	LOSE,
} t_mode;

typedef struct s_heap
{
	int		num;
	t_mode	mode;
} t_heap;


typedef struct s_game
{
	t_heap	*heap;
	int		index;
	bool	player_turn;
}	t_game;

void debug_print(t_game *game);

bool	parse_map(t_game *game, int input_fd);
void	print_map(t_game *game);

void	init_mode(t_game *game);
void	start_game(t_game *game);
int		solver(t_game *game);
void	pick_item_ai(t_game *game);
void	pick_item_player(t_game *game);

void	pick_items(t_game *game, int pick);

#endif
