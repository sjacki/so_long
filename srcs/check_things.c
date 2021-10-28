/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_things.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:01 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:54 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	count_E(t_lon *lon)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (y < lon->map.hight)
	{
		x = 0;
		while (x < lon->map.width)
		{
			if (lon->map.array[y][x] == 'E')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}

int	count_C(t_lon *lon)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (y < lon->map.hight)
	{
		x = 0;
		while (x < lon->map.width)
		{
			if (lon->map.array[y][x] == 'C')
				count++;
			x++;
		}
		y++;
	}
	lon->spr = count;
	return (count);
}

int	count_P(t_lon *lon)
{
	int	count;
	int	y;
	int	x;

	y = 0;
	count = 0;
	while (y < lon->map.hight)
	{
		x = 0;
		while (x < lon->map.width)
		{
			if (lon->map.array[y][x] == 'P')
				count++;
			x++;
		}
		y++;
	}
	return (count);
}
