/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_sandwich.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynakamot <ynakamot@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 09:38:05 by ynakamot          #+#    #+#             */
/*   Updated: 2021/04/13 09:20:56 by ynakamot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_sandwich(char *filling, char *bread)
{
	char	*sandwich;
	char	*bread_with_topping;

	if (!filling)
		return (NULL);
	if (!bread)
		return (ft_strdup(filling));
	bread_with_topping = ft_strjoin(bread, filling);
	if (!bread_with_topping)
		return (NULL);
	sandwich = ft_strjoin(bread_with_topping, bread);
	free(bread_with_topping);
	return (sandwich);
}
