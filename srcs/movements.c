/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:21 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 09:58:44 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	set_new(t_lon *lon, t_image *image, int y, int x)
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

void	check_move_c(t_lon *lon, int x, int y)
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

void	check_move_zero(t_lon *lon, int x, int y)
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

void	paint_step(t_lon *lon)
{
	mlx_string_put(lon->mlx, lon->mlx_win, 20, 30, 0x000000, "#####");
	mlx_string_put(lon->mlx, lon->mlx_win, 21, 30, 0x000000, "#####");
	mlx_string_put(lon->mlx, lon->mlx_win, 19, 30, 0x000000, "#####");
	mlx_string_put(lon->mlx, lon->mlx_win, 25, 30, 0xffffff, \
	 				ft_itoa(lon->steps));
}
