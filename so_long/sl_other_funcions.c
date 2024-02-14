/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_funcions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:21:07 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/09 14:52:07 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_map(char **map)
{
	int	i;
	
	i = 0;
	while (map[i])
	{
		ft_printf("\033[1;32m%s\033[0m", map[i]);
		i++;
	}
	ft_printf("\n");
}

int	ft_strlen_no_n(char *map)
{
	int	len;

	len = 0;
	while (map[len] != '\n' && map[len] != '\0')
		len++;
	return (len);
}
