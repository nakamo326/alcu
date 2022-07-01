/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 23:26:20 by ynakamot          #+#    #+#             */
/*   Updated: 2021/01/19 22:01:11 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*r;

	if (!s)
		return (NULL);
	r = (char *)s;
	while (*r)
	{
		if (*r == c)
			return (r);
		r++;
	}
	if (c == '\0')
		return (r);
	else
		return (NULL);
}
