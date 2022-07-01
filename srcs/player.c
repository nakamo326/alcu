/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:56:06 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 19:59:26 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"
#include "get_next_line.h"

static int check_input(char *line);

void	player(t_data *ds)
{
	char	*line;
	int		pick;

	while (1)
	{
		ft_putendl_fd("Please choose between 1 and 3 items", STDOUT_FILENO);
		get_next_line(STDIN_FILENO, &line);
		pick = check_input(line);
		free(line);
		if (pick == -1) {
			ft_putendl_fd("Invalid choice", STDOUT_FILENO);
			continue;
		}
		pick_items(ds, pick);
		break;
	}
}

static int check_input(char *line)
{
	int res = 0;

	if (ft_strlen(line) != 1)
		return (-1);
	res = *line - '0';
	if (!(1 <= res && res <= 3))
		return (-1);
	return (res);
}
