/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:21 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:22 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	set_new(t_lon *lon, char *textu, void *image)
{
	image = mlx_xpm_file_to_image(lon->mlx, textu, \
				&lon->width, &lon->hight);
	mlx_put_image_to_window(lon->mlx, \
				lon->mlx_win, image, lon->y * 20, lon->x * 20);
}

static void	print_step(t_lon **lon)
{
	int	count;

	count = (*lon)->steps;
	ft_putstr("step number:");
	ft_putnbr(count);
	ft_putchar('\n');
}

static void	move(t_lon **lon, int x, int y)
{
	set_new(*lon, "textures/floor.xpm", (*lon)->player->image);
	(*lon)->steps++;
	print_step(lon);
	(*lon)->x = (*lon)->x + x;
	(*lon)->y = (*lon)->y + y;
	if (x == 0 && y == 1)
	{
		set_new(*lon, "textures/worm2.xpm", (*lon)->player->image);
	}
	else if (x == -1 && y == 0)
	{
		set_new(*lon, "textures/up.xpm", (*lon)->player->image);
	}
	else if (x == 1 && y == 0)
	{
		set_new(*lon, "textures/down.xpm", (*lon)->player->image);
	}
	else
		set_new(*lon, "textures/worm.xpm", (*lon)->player->image);
}

void	movements(t_lon **lon, int x, int y)
{
	if (((*lon)->map.array[(*lon)->x + x][(*lon)->y + y]) == 'C' \
	&& (*lon)->spr != 0)
		(*lon)->spr--;
	if (((*lon)->map.array[(*lon)->x + x][(*lon)->y + y]) == '1')
		set_new(*lon, "textures/face.xpm", (*lon)->player->image);
	else if (((*lon)->map.array[(*lon)->x + x][(*lon)->y + y]) == 'E')
	{
		if ((*lon)->spr == 0)
		{
			ft_putstr("You won!\n");
			exit(1);
		}
		else
			set_new(*lon, "textures/worm.xpm", (*lon)->player->image);
	}
	else if (((*lon)->map.array[(*lon)->x + x][(*lon)->y + y]) == 'W')
	{
		ft_putstr("YOU LOSE!\n");
		exit(1);
	}
	else
	{
		move(lon, x, y);
	}
}
