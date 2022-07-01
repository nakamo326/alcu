/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/10 10:17:53 by ynakamot          #+#    #+#             */
/*   Updated: 2021/03/13 09:24:39 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	while (isset(s1[i], set) && s1[i] != '\0')
		i++;
	if (s1[i] == '\0')
		return (ft_strdup(""));
	len = ft_strlen(&s1[i]);
	while (isset(s1[i + len - 1], set))
		len--;
	str = ft_substr(s1, (unsigned int)i, len);
	if (!str)
		return (NULL);
	return (str);
}
