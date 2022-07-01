/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:54:41 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 20:03:13 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alcu.h"
#include "libft.h"

static int	solver(t_data *ds);

void	ai(t_data *ds)
{
	int pick = solver(ds);
	pick_items(ds, pick);

	char pick_c = pick + '0';
	ft_putendl_fd("AI took ", STDOUT_FILENO);
	write(1, &pick_c, 1);
	ft_putendl_fd("", STDOUT_FILENO);
	return ;
}

static int	solver(t_data *ds)
{
	(void)ds;
	return (1);
}
