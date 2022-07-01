/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:29:40 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 20:22:38 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "get_next_line.h"
#include "board.h"

static int	map_atoi(char *s);
static int	cnt_nl(char *map);

t_board*	parse_map(int input_fd)
{
	t_board *res = NULL;
	char *line;
	int res = 0;

	while (1)
	{
		int res = get_next_line(input_fd, &line);
		if (res == ERROR) {
			return NULL;
		}

		if (line[0] == '\n')
		{
			ds->map[i] = 0;
			free(line);
			break ;
		}

		res = map_atoi(line);
		free(line);
		if (res == -1)
			return (false);

		ds->map[i] = res;
		i++;
	}
	return (true);
}

static int	cnt_nl(char *map)
{
	char buff = 0;
	int cnt = 0;
	int fd = open(map, O_RDONLY);

	if (fd < 0)
		return (1);
	while (read(fd, &buff, 1) > 0)
	{
		if (buff == '\n')
			cnt++;
	}
	close(fd);
	return (cnt);
}

static int	map_atoi(char *s)
{
	int	res = 0;

	if (ft_strlen(s) > 5)
		return (-1);
	while (*s != '\n')
	{
		if ('0' <= *s && *s <= '9')
			res = res * 10 + (*s - '0');
		else
			return (-1);
		s++;
	}
	if (res < 1 || 10000 < res)
		return (-1);
	return (res);
}