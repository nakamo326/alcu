/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:54:41 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 20:03:13 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

static int	solver(t_game *game);

void	ai(t_game *game)
{
	int pick = solver(game);
	pick_items(game, pick);

	char pick_c = pick + '0';
	ft_putendl_fd("AI took ", STDOUT_FILENO);
	write(1, &pick_c, 1);
	ft_putendl_fd("", STDOUT_FILENO);
	return ;
}

static int	solver(t_game *game)
{
	(void)game;
	return (1);
}
