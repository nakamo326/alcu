/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tharaguc <tharaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:04:55 by tharaguc          #+#    #+#             */
/*   Updated: 2022/07/01 20:31:30 by tharaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <aicu.h>

static void	print_map(t_data *ds);
static int	check_over(t_data *ds);

void	start_game(t_data *ds)
{
	int flag = 0;

	while (1)
	{
		print_map(ds);
		ai(ds);
		flag = check_over(ds);
		if (flag != 0)
		{
			if (flag == 1)
				ft_putstr("You lose\n");
			else
				ft_putstr("You are the winner! Congratulations!\n");
			break ;
		}
		print_map(ds);
		player(ds);
		flag = check_over(ds);
		if (flag != 0)
		{
			if (flag == 1)
				ft_putstr("You are the winner! Congratulations!\n");
			else
				ft_putstr("You lose\n");
			break ;
		}
	}
}

static void	print_map(t_data *ds)
{
	
	for (int i = 0; ds->map[i] != 0; i++)
	{
		for (int j = 0; j < ds->map[i]; j++)
		{
			ft_putstr("| ");
		}
		ft_putstr("\n");
	}
}

void	pick_items(t_data *ds, int pick)
{
	int i = 0;

	while (ds->map[i] != 0)
		i++;
	i--;
	while (pick > 0)
	{
		ds->map[i]--;
		if (ds->map[i] == 0)
			i--;
		pick--;
	}
}

static int	check_over(t_data *ds)
{
	int i = 0;

	if (ds->map[i] <= 0)
		return (2);
	while (ds->map[i] != 0)
		i++;
	i--;
	if (i == 0 && ds->map[i] <= 1)
		return (1);
	return (0);
}
