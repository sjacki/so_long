/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 09:43:15 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 09:58:08 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_en(t_lon *lon, int x, int y)
{
	if (lon->map.buf[lon->x_v + x][lon->y_v + y] != '1')
	{
		set_new(lon, lon->floor, lon->x_v, lon->y_v);
		set_new(lon, lon->enemy, lon->x_v + x, lon->y_v + y);
		lon->map.buf[lon->x_v][lon->y_v] = '0';
		lon->map.buf[lon->x_v + x][lon->y_v + y] = 'W';
		lon->x_v += x;
		lon->y_v += y;
	}
}

void	movements(t_lon *lon, int x, int y)
{
	if (lon->x_v == lon->x && lon->y_v == lon->y)
		exit(0);
	if (lon->map.buf[lon->x + x][lon->y + y] == 'C')
		check_move_c(lon, x, y);
	else if (lon->map.buf[lon->x + x][lon->y + y] == 'E')
	{
		if (lon->count_eat == 0)
		{
			ft_putstr("You won!\n", 1);
			exit(1);
		}
	}
	else if (lon->map.buf[lon->x + x][lon->y + y] == 'W')
	{
		ft_putstr("You lose!\n", 1);
		exit(1);
	}
	else
		check_move_zero(lon, x, y);
	paint_step(lon);
	move_en(lon, x, y);
}
