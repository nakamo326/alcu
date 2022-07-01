/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:48:46 by ynakamot          #+#    #+#             */
/*   Updated: 2021/03/13 09:31:41 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	output_number(unsigned long long n, char *bs, size_t len, char *p)
{
	char	*tmp;

	tmp = p;
	if (n / len == 0)
	{
		*tmp = bs[n];
		return ;
	}
	output_number(n / len, bs, len, --p);
	*tmp = bs[n % len];
}

char	*ft_lltoa_base(unsigned long long n, char *base)
{
	unsigned long long	tmp;
	char				*str;
	char				*p;
	size_t				len;
	size_t				blen;

	tmp = n;
	blen = ft_strlen(base);
	len = 1;
	while (n >= blen)
	{
		n = n / blen;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	p = str + (int)len;
	*p = '\0';
	p--;
	n = tmp;
	output_number(n, base, blen, p);
	return (str);
}
