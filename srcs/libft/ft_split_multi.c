/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_multi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 19:02:03 by ynakamot          #+#    #+#             */
/*   Updated: 2021/04/05 11:14:45 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char str, char *set)
{
	while (*set != '\0')
	{
		if (str == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	check_str(char *str, char *set)
{
	int	w;

	w = 0;
	while (*str)
	{
		if (is_sep(*str, set))
		{
			str++;
			continue ;
		}
		w++;
		while (*str && !is_sep(*str, set))
			str++;
	}
	return (w);
}

static char	**split_wrd(char **ret, char *str, char *set, int wrds)
{
	int		i;
	int		len;

	i = 0;
	while (i < wrds)
	{
		while (is_sep(*str, set))
			str++;
		len = 0;
		while (str[len] && !is_sep(str[len], set))
			len++;
		ret[i] = malloc(sizeof(char) * (len + 1));
		if (!ret[i])
		{
			while (i >= 0)
				free(ret[i--]);
			return (NULL);
		}
		ft_strlcpy(ret[i], str, len + 1);
		i++;
		str = str + len;
	}
	return (ret);
}

char	**ft_split_multi(char *str, char *set)
{
	char	**ret;
	int		wrds;

	if (!str)
		return (NULL);
	wrds = check_str(str, set);
	ret = (char **)malloc(sizeof(*ret) * (wrds + 1));
	if (!ret)
		return (NULL);
	ret[wrds] = NULL;
	if (!split_wrd(ret, str, set, wrds))
	{
		free(ret);
		return (NULL);
	}
	return (ret);
}
