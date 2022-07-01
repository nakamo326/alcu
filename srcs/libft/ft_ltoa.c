/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/11 16:48:46 by ynakamot          #+#    #+#             */
/*   Updated: 2021/03/13 09:45:37 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

static void	output_number(long long unb, char *p)
{
	char	*tmp;

	tmp = p;
	if (unb / 10 == 0)
	{
		*tmp = '0' + unb;
		return ;
	}
	output_number(unb / 10, --p);
	*tmp = '0' + unb % 10;
}

static long long	init_num(long n)
{
	if (n < 0)
		return ((long long) - 1 * n);
	else
		return ((long long)n);
}

char	*ft_ltoa(long n)
{
	long long	unb;
	char		*str;
	char		*p;
	int			len;

	unb = init_num(n);
	len = 1;
	while (unb >= 10)
	{
		unb = unb / 10;
		len++;
	}
	if (n < 0)
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	p = str + len;
	*p = '\0';
	p--;
	unb = init_num(n);
	output_number(unb, p);
	if (n < 0)
		str[0] = '-';
	return (str);
}
