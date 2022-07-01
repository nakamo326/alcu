/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extend_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 09:55:02 by ynakamot          #+#    #+#             */
/*   Updated: 2021/04/14 11:13:03 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** extend split char **LIST to SIZE and copy current list.
** if list is NULL, return allocated heap(sizeof(char *) * size).
*/
char	**ft_extend_split(char **list, size_t size)
{
	char	**new;
	size_t	i;

	new = malloc(sizeof(char *) * size);
	if (!new)
		return (NULL);
	if (list == NULL)
		return (new);
	i = 0;
	while (list[i] != NULL && i < size - 1)
	{
		new[i] = list[i];
		i++;
	}
	new[i] = NULL;
	free(list);
	return (new);
}
