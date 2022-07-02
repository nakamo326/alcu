/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:54:41 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/02 14:27:49 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

static int pick_to_lose(const t_heap *heap)
{
	if (heap->num % 4 == 0)
		return (1);
	return (heap->num % 4);
}

static int pick_to_win(const t_heap *heap)
{
	if ((heap->num - 3) % 4 == 1)
		return (3);
	if ((heap->num - 2) % 4 == 1)
		return (2);
	if ((heap->num - 1) % 4 == 1)
		return (1);
	return (3);
}

int	solver(t_game *game)
{
	int pick = 0;
	if (game->heap[game->index].mode == LOSE)
		pick = pick_to_lose(&game->heap[game->index]);
	else
		pick = pick_to_win(&game->heap[game->index]);
	return (pick);
}

void	pick_item_ai(t_game *game)
{
	int pick = solver(game);
	pick_items(game, pick);

	char pick_c = pick + '0';
	ft_putendl_fd("AI took ", STDOUT_FILENO);
	write(1, &pick_c, 1);
	ft_putendl_fd("", STDOUT_FILENO);
	return ;
}
