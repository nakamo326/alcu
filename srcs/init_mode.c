/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 13:34:28 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/02 13:40:18 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"

void	init_mode(t_game *game)
{
	int i = 1;
	while (game->heap[i].num != 0)
	{
		if (game->heap[i - 1].num % 4 == 1)
			game->heap[i].mode = LOSE;
		else
			game->heap[i].mode = WIN;
		i++;
	}
}
