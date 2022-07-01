/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 20:04:24 by ynakamot          #+#    #+#             */
/*   Updated: 2021/03/13 09:35:45 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dl;
	size_t	sl;
	size_t	i;

	i = 0;
	dl = ft_strlen(dst);
	sl = ft_strlen(src);
	if (dstsize == 0)
		return (sl + dstsize);
	while (src[i] != '\0' && (dl + i) < dstsize - 1)
	{
		dst[dl + i] = src[i];
		i++;
	}
	if (src[i] == '\0' || (dl + i) == dstsize - 1)
		dst[dl + i] = '\0';
	if (dl >= dstsize)
		return (sl + dstsize);
	else
		return (dl + sl);
}
