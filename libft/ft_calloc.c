/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 11:26:51 by mignavar          #+#    #+#             */
/*   Updated: 2023/09/25 13:10:55 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;

	a = malloc(nitems * size);
	if (!a)
		return (NULL);
	ft_bzero(a, (nitems * size));
	return (a);
}
