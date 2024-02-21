/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_print_error_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:41:51 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/20 14:30:22 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	error_arg(int ac, char **av)
{
	if (ac < 2)
	{
		ft_printf("Error\nPocos argumentos\n");
		return (1);
	}
	if (ac > 2)
	{
		ft_printf("Error\nDemasiados argumentos\n");
		return (1);
	}
	if (ft_strncmp(&av[1][(ft_strlen(av[1]) - 4)], ".ber", 4) != 0)
	{
		ft_printf("Error\nArchivo no válido\n");
		return (1);
	}
	return (0);
}

void	print_errors(int error)
{
	ft_printf("\033[1;31mError\033[0m\n");
	if (error == 0)
		ft_printf("Map too big\n");
	if (error == 1)
		ft_printf("Non-rectangular map\n");
	if (error == 2)
		ft_printf("It is not surrounded by walls\n");
	if (error == 3)
		ft_printf("Incorrect number of 'P'\n");
	if (error == 4)
		ft_printf("Put at least one collectible\n");
	if (error == 5)
		ft_printf("Incorrect number of 'E'\n");
	if (error == 6)
		ft_printf("invalid character in map\n");
	if (error == 7)
		ft_printf("The map cannot be completed\n");
	if (error == 8)
		ft_printf("Problems with images\n");
}
