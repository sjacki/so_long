/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:30 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:31 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	t_lon	*lon;

	if (argc == 2)
	{
		lon = (struct s_lon *)malloc(sizeof(t_lon));
		read_file(argv[1], lon);
		if (check_map(lon) == 1)
		{
			draw_map(lon);
		}
	}
	return (1);
}
