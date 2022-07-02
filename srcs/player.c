/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:56:06 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/02 13:25:40 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"
#include "get_next_line.h"

static int check_input(t_game *game, char *line)
{
	int res = 0;

	if (ft_strlen(line) != 1)
		return (-1);
	res = *line - '0';
	if (!(1 <= res && res <= 3))
		return (-1);
	if (game->heap[game->index].num < res)
		return (-1);
	return (res);
}

void	pick_item_player(t_game *game)
{
	char	*line;
	int		res, pick;

	while (1)
	{
		ft_putendl_fd("Please choose between 1 and 3 items", STDOUT_FILENO);
		res = get_next_line(STDOUT_FILENO, &line);
		// res = get_next_line(STDIN_FILENO, &line);
		if (res == ERROR) {
			free(line);
			return;
		}
		if (res == END) {
			free(line);
			continue;
		}
		pick = check_input(game, line);
		free(line);
		if (pick != -1) {
			break;
		}
		ft_putendl_fd("Invalid choice", STDOUT_FILENO);
		print_map(game);
	}
	pick_items(game, pick);
}
