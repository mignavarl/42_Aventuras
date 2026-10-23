/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 10:59:46 by mignavar          #+#    #+#             */
/*   Updated: 2024/01/08 11:40:30 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	l;
	char	*str;

	l = 0;
	str = s;
	while (l < n)
	{
		str[l] = '\0';
		l++;
	}
}

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;

	a = malloc(nitems * size);
	if (!a)
		return (NULL);
	ft_bzero(a, (nitems * size));
	return (a);
}
