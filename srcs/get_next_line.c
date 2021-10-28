/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:17 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:19 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static char	*ft_check_rem(char **line, char **reminders)
{
	char	*linebreak;
	char	*temp;

	linebreak = 0;
	if (*reminders)
	{
		linebreak = ft_strchr(*reminders, '\n');
		if (linebreak)
		{
			*linebreak = '\0';
			*line = ft_strdup(*reminders);
			temp = *reminders;
			*reminders = ft_strdup(++linebreak);
			free(temp);
		}
		else
		{
			*line = ft_strdup(*reminders);
			free(*reminders);
			*reminders = NULL;
		}
	}
	else
		*line = ft_strdup("");
	return (linebreak);
}

static void	free_temp(char **line, char *buff)
{
	char	*temp;

	temp = *line;
	*line = ft_strjoin(*line, buff);
	free(temp);
}

static int	if_params(int fd, char **line, t_gl *gl)
{
	gl->buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (fd < 0 || BUFFER_SIZE < 1 || !line || \
	!gl->buff || (read(fd, gl->buff, 0) < 0))
		return (0);
	return (1);
}

static int	init_params_in_cycle(t_gl *gl, int fd)
{
	gl->bytes_read = read(fd, gl->buff, BUFFER_SIZE);
	if (gl->bytes_read == 0 || gl->bytes_read == -1)
		return (0);
	gl->buff[gl->bytes_read] = '\0';
	gl->linebreak = ft_strchr(gl->buff, '\n');
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*reminders[FD_AMOUNT];
	t_gl		gl;

	if (!(if_params(fd, line, &gl)))
		return (-1);
	gl.linebreak = ft_check_rem(line, &(reminders[fd]));
	while (!gl.linebreak)
	{
		if (!(init_params_in_cycle(&gl, fd)))
			break ;
		if (gl.linebreak)
		{
			*gl.linebreak = '\0';
			reminders[fd] = ft_strdup(++gl.linebreak);
			if (!(reminders[fd]))
				return (-1);
		}
		free_temp(line, gl.buff);
	}
	free(gl.buff);
	if (gl.linebreak)
		return (1);
	return (0);
}
