/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexandr <alexandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 00:31:42 by sjacki            #+#    #+#             */
/*   Updated: 2021/10/29 08:09:16 by alexandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

size_t		len_itoa(int n)
{
	size_t		len;

	len = 1;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	size_t		len;
	char		*pnt;
	long		num;

	num = n;
	len = len_itoa(n);
	if ((pnt = (char *)malloc(len * sizeof(char))) == NULL)
		return (NULL);
	pnt[len - 1] = '\0';
	len--;
	if (num < 0)
	{
		pnt[0] = '-';
		num *= -1;
	}
	if (num == 0)
		pnt[0] = '0';
	while (num)
	{
		pnt[--len] = num % 10 + '0';
		num /= 10;
	}
	return (pnt);
}
