/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 00:14:36 by alexandr          #+#    #+#             */
/*   Updated: 2021/10/29 00:14:39 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	ft_check(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		len2;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc((len1 + len2 + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(char const *string, int symbol)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == (char)symbol)
			return ((char *)string + i);
		i++;
	}
	if ((char)symbol == '\0')
		return ((char *)string + i);
	return (NULL);
}

char 	*ft_strdup(const char *str)
{
	int		lenght;
	char	*dest;

	lenght = ft_strlen(str);
	dest = (char *)malloc((lenght + 1) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (lenght >= 0)
	{
		dest[lenght] = str[lenght];
		lenght--;
	}
	lenght = ft_strlen(str);
	dest[lenght++] = '\0';
	return (dest);
}
