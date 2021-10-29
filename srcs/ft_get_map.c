/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:27 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 08:34:51 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	err_exit(char *str)
{
		ft_putstr("Error: ", 2);
		ft_putstr(str, 2);
		ft_putstr("\n", 2);
		exit(1);
}

void	ber_check(char **argv)
{
	int x;

	x = ft_strlen(argv[1]) - 1;
	if (argv[1][x] != 'r' || argv[1][x - 1] != 'e' || argv[1][x - 2] != 'b'\
		|| argv[1][x - 4] == '.')
		err_exit("Not valid map file");
}

int		check_first_line(char *line)
{
	int x;

	x = 0;
	if (!line)
		return (1);
	while (line[x])
	{
		if (line[x] != '1')
			return (1);
		x++;
	}
	return (0);
}

void	check_ch(char **map, t_lon *m)
{
	int	x;
	int	y;
	int	ex;
	int f;

	f = 0;
	m->x = 0;
	m->y = 0;
	ex = 0;
	m->count_eat = 0;
	y = 0;
	while (y < m->map.height)
	{
		x = 0;
		while (x < m->map.width)
		{
			if (map[y][x] == '1' || map[y][x] == '0')
			{
				x++;
				continue;
			}
			else if (map[y][x] == 'W')
			{
				m->x_v = y;
				m->y_v = x;
			}
			else if (map[y][x] == 'C')
				m->count_eat++;
			else if (map[y][x] == 'E')
				ex++;
			else if (map[y][x] == 'P')
			{
				m->x = y;
				m->y = x;
				f++;
			}
			else
				err_exit("Not valid map file");
			x++;
		}
		y++;
	}
	if (!ex || !m->x || !m->y || !m->count_eat || f != 1)
		err_exit("Not valid map file");
}

void	get_map(char **argv, t_lon *lon)
{
	char	*line;
	int	x;
	int	fd;
	int	err_gnl;
	char	*map;
	int	len_ex_line;
	
		line = NULL;
	x = 0;
	ber_check(argv);
	fd = open(argv[1], O_RDONLY);
	map = ft_strdup("");
	if (!fd || !map)
		err_exit("Not valid map file");
	err_gnl = get_next_line(fd, &line);
	if (err_gnl == -1 || check_first_line(line))
			err_exit("Not valid map file");
	len_ex_line = ft_strlen(line);
	map = ft_strjoin(map, line);
	map = ft_strjoin(map, "\n");
	while ((err_gnl = get_next_line(fd, &line)))
	{
		if (err_gnl == -1 || ft_strlen(line) != len_ex_line || \
		 	line[0] != '1' || line[len_ex_line - 1] != '1')
			err_exit("Not valid map file");
		map = ft_strjoin(map, line);
		map = ft_strjoin(map, "\n");
		x++;
	}
	if (err_gnl == -1 || check_first_line(line) || ft_strlen(line) != len_ex_line)
			err_exit("Not valid map file");
	map = ft_strjoin(map, line);
	lon->map.width = len_ex_line;
	lon->map.height = x + 1;
	lon->map.buf = ft_split(map, '\n');
	check_ch(lon->map.buf, lon);
}
