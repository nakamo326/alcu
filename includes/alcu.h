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

# include <stdio.h>//

typedef struct s_data
{
	int	*map;
	int index;
}	t_data;

bool	parse_map(t_data *ds, int input_fd);

void	start_game(t_data *ds);
void	ai(t_data *ds);
void	player(t_data *ds);

void	pick_items(t_data *ds, int pick);

#endif
