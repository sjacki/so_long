/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:13:53 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:13:55 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	check_rectangular(t_lon *lon)
{
	int	lenght;
	int	i;
	int	j;

	i = 0;
	lenght = lon->map.width;
	while (i < lon->map.hight - 1)
	{
		j = i + 1;
		if (ft_strlen(lon->map.array[j]) != lenght)
		{
			return (0);
			break ;
		}
		j++;
		i++;
	}
	return (1);
}

static int	it_is_this_smbl(t_lon *lon)
{
	int	y;
	int	x;

	y = 0;
	while (y < lon->map.hight)
	{
		x = 0;
		while (x < lon->map.width)
		{
			if (!(ft_check(lon->map.array[y][x], "PWEC01")))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

static int	more_than_ove(t_lon *lon)
{
	if (count_E(lon) != 1)
		return (0);
	else if (count_C(lon) < 1)
		return (0);
	else if (count_P(lon) != 1)
		return (0);
	return (1);
}

static void	not_valid(int flag)
{
	if (flag == 1)
		write(1, "Error\n", 6);
}

int	check_map(t_lon *lon)
{
	if (check_rectangular(lon) != 1 || check_wall_n(lon) != 1 || \
	check_wall_s(lon) != 1 || check_wall_w(lon) != 1 || check_wall_e(lon) != 1 || \
	it_is_this_smbl(lon) != 1 || more_than_ove(lon) != 1)
	{
		not_valid(1);
		return (0);
	}
	return (1);
}
