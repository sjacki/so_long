/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:27 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:28 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static int	get_hight(char *argv)
{
	char	*line;
	int		fd;
	int		hight;

	hight = 0;
	fd = open(argv, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		hight++;
		free(line);
	}
	free(line);
	close(fd);
	hight++;
	return (hight);
}

int	get_width(t_lon *lon)
{
	int	width;

	width = 0;
	while (lon->map.array[0][width] != '\0')
		width++;
	return (width);
}

void	read_file(char *argv, t_lon *lon)
{
	char	*line;
	int		y;
	int		fd;

	y = 0;
	lon->map.hight = get_hight(argv);
	fd = open(argv, O_RDONLY);
	lon->map.array = (char **)malloc(sizeof(char *) * (lon->map.hight + 1));
	while (get_next_line(fd, &line) && y != lon->map.hight)
	{
		lon->map.array[y] = line;
		y++;
	}
	lon->map.array[y] = line;
	close(fd);
	lon->map.array[++y] = NULL;
	lon->map.width = get_width(lon);
	lon->hight = lon->map.hight;
	lon->width = lon->map.width;
}
