/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 16:33:42 by mignavar          #+#    #+#             */
/*   Updated: 2023/10/02 17:28:07 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	a;
	size_t	t;

	a = 0;
	t = start;
	if (ft_strlen(s) < start)
	{
		sub = (char *)malloc(sizeof(char));
		*sub = '\0';
		return (sub);
	}
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (0);
	while (a < len && t < ft_strlen(s))
	{
		sub[a] = s[t];
		a++;
		t++;
	}
	sub[a] = '\0';
	return (sub);
}
