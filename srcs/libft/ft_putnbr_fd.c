/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:56:05 by ynakamot          #+#    #+#             */
/*   Updated: 2021/03/13 09:32:46 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	output_num(unsigned int unb, int fd)
{
	if (unb / 10 == 0)
	{
		ft_putchar_fd('0' + unb, fd);
		return ;
	}
	output_num(unb / 10, fd);
	ft_putchar_fd('0' + unb % 10, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	unb;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		unb = -1 * n;
	}
	else
	{
		unb = n;
	}
	output_num(unb, fd);
}
