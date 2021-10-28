/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:06 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:08 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	check_wall_n(t_lon *lon)
{
	int	x;

	x = 0;
	while (x < lon->map.width - 1)
	{
		if (lon->map.array[0][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_wall_s(t_lon *lon)
{
	int	x;
	int	y;

	x = 0;
	y = lon->map.hight - 1;
	while (x < lon->map.width - 1)
	{
		if (lon->map.array[y][x] != '1')
			return (0);
		x++;
	}
	return (1);
}

int	check_wall_w(t_lon *lon)
{
	int	y;

	y = 0;
	while (y < lon->map.hight - 1)
	{
		if (lon->map.array[y][0] != '1')
			return (0);
		y++;
	}
	return (1);
}

int	check_wall_e(t_lon *lon)
{
	int	x;
	int	y;

	y = 0;
	x = lon->map.width - 1;
	while (y < lon->map.hight - 1)
	{
		if (lon->map.array[y][x] != '1')
			return (0);
		y++;
	}
	return (1);
}
