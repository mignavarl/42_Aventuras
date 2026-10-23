/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 13:11:58 by mignavar          #+#    #+#             */
/*   Updated: 2023/11/22 15:17:48 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;

	i = 0;
	str = ((char *)malloc((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char) + 1));
	if (!str)
		return (NULL);
	while (*s1 != '\0')
	{
		str[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 != '\0')
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
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

char	*ft_strchr(const char *str, int ch)
{
	if (!str)
		return (0);
	while (*str != '\0' && *str != (char)ch)
		str++;
	if (*str == (char)ch)
		return ((char *)str);
	return (0);
}
