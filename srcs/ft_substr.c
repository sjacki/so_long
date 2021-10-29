/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 19:52:41 by sjacki            #+#    #+#             */
/*   Updated: 2021/10/29 03:56:55 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		walk;
	char		*ptr;

	walk = start;
	if (s == NULL)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
	{
		ptr = (char *)malloc(1 * sizeof(char));
		ptr[0] = '\0';
		return (ptr);
	}
	while (walk - start < len)
		walk++;
	ptr = (char *)malloc((walk - start + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	walk = start;
	while (s[walk] && walk - start < len)
	{
		ptr[walk - start] = s[walk];
		walk++;
	}
	ptr[walk - start] = '\0';
	return (ptr);
}
