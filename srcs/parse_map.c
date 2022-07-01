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
	while (*s != '\0')
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

static t_list*	raed_map(int input_fd)
{
	t_list *head = NULL;
	char	*line = NULL;

	while (1)
	{
		int res = get_next_line(input_fd, &line);
		if (res == ERROR) {
			ft_lstclear(&head, free);
			return NULL;
		}
		if (res == END) {
			free(line);
			break;
		}
		if (res == SUCCESS) {
			t_list* new = ft_lstnew(line);
			ft_lstadd_back(&head, new);
		}
	}
	return head;
}

void	convert_map(t_data *ds, t_list *line_list)
{
	ds->index = ft_lstsize(line_list);
	printf("%d\n", ds->index);
	int *map = malloc(sizeof(int) * ds->index);
	t_list* list_ptr = line_list;
	for (int i = 0; list_ptr != NULL; i++)
	{
		int num = map_atoi(list_ptr->content);
		if (num == -1) {
			free(map);
			return;
		}
		map[i] = num;
		list_ptr = list_ptr->next;
	}
	ds->map = map;
}

bool	parse_map(t_data *ds, int input_fd)
{
	t_list* line_list = raed_map(input_fd);
	if (line_list == NULL) {
		return false;
	}
	convert_map(ds, line_list);
	ft_lstclear(&line_list, free);
	if (ds->map == NULL) {
		return false;
	}
	return true;
}
