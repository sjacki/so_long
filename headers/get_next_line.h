/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 13:02:35 by sjacki            #+#    #+#             */
/*   Updated: 2021/10/29 01:59:06 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int			get_next_line(int fd, char **line);
char		*ft_g_strjoin(char const *s1, char const *s2);
size_t		ft_g_strlen(const char *s);
char		*ft_g_strchr(char *s, int c);
char		*ft_g_substr(char const *s, unsigned int start, size_t len);
char		*ft_g_strdup(const char *s1);
#endif
