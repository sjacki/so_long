/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:13 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:15 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	deal_key(int key, t_lon *lon)
{
	if (key == ESC)
	{
		exit (0);
	}
	if (key == KEY_W)
		movements(&lon, -1, 0);
	if (key == KEY_A)
		movements(&lon, 0, -1);
	if (key == KEY_S)
		movements(&lon, 1, 0);
	if (key == KEY_D)
		movements(&lon, 0, 1);
	return (1);
}

static void	set_new_image(t_lon **lon, char *textu, void *image, char c)
{
	int	y;
	int	x;

	y = 0;
	while (y < (*lon)->map.hight)
	{
		x = 0;
		while (x < (*lon)->map.width)
		{
			if ((*lon)->map.array[y][x] == c)
			{
				image = mlx_xpm_file_to_image((*lon)->mlx, textu, \
				&(*lon)->width, &(*lon)->hight);
				if ((*lon)->map.array[y][x] == 'P')
				{
					(*lon)->y = x;
					(*lon)->x = y;
				}
				mlx_put_image_to_window((*lon)->mlx, \
				(*lon)->mlx_win, image, x * 20, y * 20);
			}
			x++;
		}
		y++;
	}
}

static int	close_window(void)
{
	ft_putstr("window closed!\n");
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
}

void	draw_map(t_lon *lon)
{
	get_malloc(&lon);
	lon->mlx = mlx_init();
	lon->mlx_win = mlx_new_window(lon->mlx, lon->width * 20, \
	lon->hight * 20, "so_long");
	set_new_image(&lon, "textures/worm.xpm", lon->player->image, 'P');
	set_new_image(&lon, "textures/floor.xpm", lon->floor->image, '0');
	set_new_image(&lon, "textures/wall.xpm", lon->wall->image, '1');
	set_new_image(&lon, "textures/bag.xpm", lon->sprite->image, 'C');
	set_new_image(&lon, "textures/door.xpm", lon->door->image, 'E');
	set_new_image(&lon, "textures/enemy.xpm", lon->door->image, 'W');
	// mlx_key_hook(lon->mlx_win, deal_key, lon); // move one time when press key
	mlx_hook(lon->mlx_win, 2, 1L << 0, deal_key, lon); // mowe while handing key
	mlx_hook(lon->mlx_win, 17, 1L << 0, close_window, lon);
	mlx_loop(lon->mlx);
}
