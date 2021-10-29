/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:13 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 08:15:47 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static int	deal_key(int key, t_lon *lon)
{
	if (key == ESC)
		exit (0);
	if (key == KEY_W)
	{
		lon->player->image = mlx_xpm_file_to_image(lon->mlx, "textures/up.xpm", \
				&lon->player->width, &lon->player->height);
		movements(lon, -1, 0);
	}
	if (key == KEY_A)
	{
		lon->player->image = mlx_xpm_file_to_image(lon->mlx, "textures/worm.xpm", \
				&lon->player->width, &lon->player->height);
		movements(lon, 0, -1);
	}
	if (key == KEY_S)
	{
		lon->player->image = mlx_xpm_file_to_image(lon->mlx, "textures/down.xpm", \
				&lon->player->width, &lon->player->height);
		movements(lon, 1, 0);
	}
	if (key == KEY_D)
	{
		lon->player->image = mlx_xpm_file_to_image(lon->mlx, "textures/worm2.xpm", \
			&lon->player->width, &lon->player->height);
		movements(lon, 0, 1);
	}
	return (1);
}

static void	set_new_image(t_lon *lon, t_image *image, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y <= lon->map.height)
	{
		x = 0;
		while (x <= lon->map.width)
		{
			if (lon->map.buf[y][x] == c)
			{
				mlx_put_image_to_window(lon->mlx, \
				lon->mlx_win, image->image, x * \
				 (lon->width / lon->map.width) + \
				  (lon->width % lon->map.width), y * \
				   (lon->height / (lon->map.height + 1)) \
				   + (lon->height % (lon->map.height + 1)) + 20);
			}
			x++;
		}
		y++;
	}
}

static int	close_window(void)
{
	ft_putstr("window closed!\n", 1);
	exit(0);
	return (1);
}

static void	get_malloc(t_lon **lon)
{
	(*lon)->image = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->image)
		exit(0);
	(*lon)->player = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->player)
		exit(0);
	(*lon)->floor = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->floor)
		exit(0);
	(*lon)->wall = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->wall)
		exit(0);
	(*lon)->sprite = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->sprite)
		exit(0);
	(*lon)->door = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->door)
		exit(0);
	(*lon)->enemy = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->enemy)
		exit(0);
	(*lon)->face = (struct s_image *)malloc(sizeof(t_image));
	if (!(*lon)->face)
		exit(0);
}

void	set_back(t_lon *lon)
{
	int	x;
	int	y;

	y = 0;
	while (y < lon->height)
	{
		x = 0;
		while (x < lon->width)
		{
			mlx_pixel_put(lon->mlx, lon->mlx_win, x, y, 0x4d678e);
			if ((y > 0 && y < (lon->height / (lon->map.height + 1)) \
				   + (lon->height % (lon->map.height + 1))) || \
				   ((y > lon->height - ((lon->height / (lon->map.height + 1)) \
				   + (lon->height % (lon->map.height + 1)) + 20)) && y < lon->height))
				mlx_pixel_put(lon->mlx, lon->mlx_win, x, y, 0x3f1a10);
			if ((x > 0 && x < (lon->width / (lon->map.width)) \
				   + (lon->width % (lon->map.width))) || \
				   ((x > lon->width - ((lon->width / (lon->map.width)) \
				   + (lon->width % (lon->map.width)))) && x < lon->width))
				mlx_pixel_put(lon->mlx, lon->mlx_win, x, y, 0x3f1a10);
			x++;
		}
		y++;
	}
}

void	draw_map(t_lon *lon)
{
	get_malloc(&lon);
	lon->mlx = mlx_init();
	mlx_get_screen_size(lon->mlx, &lon->width, &lon->height);
	lon->mlx_win = mlx_new_window(lon->mlx, lon->width, lon->height, "so_long");
	set_back(lon);
	lon->player->image = mlx_xpm_file_to_image(lon->mlx, "textures/worm.xpm", \
				&lon->player->width, &lon->player->height);
	set_new_image(lon, lon->player, 'P');
	lon->floor->image = mlx_xpm_file_to_image(lon->mlx, "textures/floor.xpm", \
				&lon->floor->width, &lon->floor->height);
	set_new_image(lon, lon->floor, '0');
	lon->wall->image = mlx_xpm_file_to_image(lon->mlx, "textures/wall.xpm", \
				&lon->wall->width, &lon->wall->height);
	set_new_image(lon, lon->wall, '1');
	lon->sprite->image = mlx_xpm_file_to_image(lon->mlx, "textures/bag.xpm", \
				&lon->sprite->width, &lon->sprite->height);
	set_new_image(lon, lon->sprite, 'C');
	lon->door->image = mlx_xpm_file_to_image(lon->mlx, "textures/door.xpm", \
				&lon->door->width, &lon->door->height);
	set_new_image(lon, lon->door, 'E');
	lon->enemy->image = mlx_xpm_file_to_image(lon->mlx, "textures/enemy.xpm", \
				&lon->enemy->width, &lon->enemy->height);
	set_new_image(lon, lon->enemy, 'W');

	mlx_hook(lon->mlx_win, 2, 1L << 0, deal_key, lon);
	mlx_hook(lon->mlx_win, 17, 1L << 0, close_window, lon);
	mlx_loop(lon->mlx);
}
