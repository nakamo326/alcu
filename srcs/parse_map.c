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
#include "libft.h"

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

static char**	raed_map(int input_fd)
{
	char	**lines = NULL;
	char	*line = NULL;
	int		line_num = 0;

	while (1)
	{
		int res = get_next_line(input_fd, &line);
		if (res == ERROR) {
			ft_free_split(lines);
			return NULL;
		}
		if (res == END) {
			if (line[0] != '\0') {
				ft_extend_split(lines, line_num + 1);
				lines[line_num] = line;
				line_num++;
			}
			break;
		}
		if (res == SUCCESS) {
			ft_extend_split(lines, line_num + 1);
			lines[line_num] = line;
			line_num++;
		}
	}
	return lines;
}

static int*	convert_map(char **lines)
{
	int line_num = 0;
	while(lines[line_num] != NULL)
		line_num++;
	int *map = malloc(sizeof(int) * (line_num - 1));
	for (int i = 0; lines[i] != NULL; i++)
	{
		int num = map_atoi(lines[i]);
		if (num == -1) {
			free(map);
			return NULL;
		}
		map[i] = num;
	}
	return map;
}

bool	parse_map(t_data *ds, int input_fd)
{
	char** lines = raed_map(input_fd);
	if (lines == NULL) {
		return false;
	}
	int* map = convert_map(lines);
	ft_free_split(lines);
	ds->map = map;
	return true;
}
