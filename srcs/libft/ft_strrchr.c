/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/08 00:00:15 by ynakamot          #+#    #+#             */
/*   Updated: 2020/10/08 13:43:19 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*last;
	unsigned char	chr;

	last = NULL;
	chr = (unsigned char)c;
	while (*s)
	{
		if (*s == c)
			last = (char *)s;
		s++;
	}
	if (chr == '\0')
		return ((char *)s);
	else
		return (last);
}
