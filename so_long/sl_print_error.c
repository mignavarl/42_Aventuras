/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:41:51 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/12 11:48:05 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	error_arg(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Pocos argumentos\n");
		return (1);
	}
	if (ac > 2)
	{
		ft_printf("Demasiados argumentos\n");
		return (1);
	}
	if (ft_strncmp(&av[1][(ft_strlen(av[1]) - 4)], ".ber", 4) != 0)
	{
		ft_printf("Archivo no válido\n");
		return (1);
	}
	return (0);
}
