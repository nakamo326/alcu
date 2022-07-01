/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_addstr_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:00:51 by ynakamot          #+#    #+#             */
/*   Updated: 2021/09/11 16:31:21 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** add duplicated STR to split char LIST.
** if LIST is NULL, return new list includes two elements(str and null).
*/
char	**ft_addstr_split(char **list, const char *str)
{
	size_t	i;
	char	*new_str;
	char	**tmp;

	new_str = ft_strdup(str);
	if (new_str == NULL)
	{
		ft_free_split(list);
		return (NULL);
	}
	i = 0;
	if (list != NULL)
		while (list[i] != NULL)
			i++;
	tmp = list;
	list = ft_extend_split(list, i + 2);
	if (list == NULL)
	{
		free(new_str);
		ft_free_split(tmp);
		return (NULL);
	}
	list[i] = new_str;
	list[i + 1] = NULL;
	return (list);
}
