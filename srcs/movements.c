/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:21 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 08:28:56 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	set_new(t_lon *lon, t_image *image, int y, int x)
{
	mlx_put_image_to_window(lon->mlx, \
	lon->mlx_win, image->image, x * \
	 (lon->width / lon->map.width) + \
	  (lon->width % lon->map.width), y * \
	   (lon->height / (lon->map.height + 1)) \
	  + (lon->height % (lon->map.height + 1)) + 20);
}

static void	print_step(t_lon *lon)
{
	int	count;

	count = lon->steps;
	ft_putstr("step number:", 1);
	ft_putnbr(count);
	ft_putchar('\n', 1);
}

void	movements(t_lon *lon, int x, int y)
{
	if (lon->map.buf[lon->x + x][lon->y + y] == 'C')
	{
		set_new(lon, lon->floor, lon->x, lon->y);
		set_new(lon, lon->player, lon->x + x, lon->y + y);
		lon->map.buf[lon->x + x][lon->y + y] = '0';
		lon->count_eat--;
		lon->x += x;
		lon->y += y;
		lon->steps++;
		print_step(lon);
	}
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
	{
		if (lon->map.buf[lon->x + x][lon->y + y] == '0')
		{
			set_new(lon, lon->player, lon->x + x, lon->y + y);
			set_new(lon, lon->floor, lon->x, lon->y);
			lon->map.buf[lon->x][lon->y] = '0';
			lon->x += x;
			lon->y += y;
			lon->steps++;
			print_step(lon);
		}
	}
	mlx_string_put(lon->mlx, lon->mlx_win, 20, 30, 0x000000, "#####");
	mlx_string_put(lon->mlx, lon->mlx_win, 21, 30, 0x000000, "#####");
	mlx_string_put(lon->mlx, lon->mlx_win, 19, 30, 0x000000, "#####");
	mlx_string_put(lon->mlx, lon->mlx_win, 25, 30, 0xffffff, ft_itoa(lon->steps));
	if (lon->x_v == lon->x && lon->y_v == lon->y)
		exit (0);
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
