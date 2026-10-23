/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_other_funcions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:21:07 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/22 11:30:51 by mignavar         ###   ########.fr       */
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

void	free_all(t_game *data)
{
	int	total;

	total = get_total_line(data->map);
	while (total >= 0)
	{
		free(data->map[total]);
		total--;
	}
	free(data->map);
}

int	cross_window(t_game *data)
{
	ft_printf("\033[1;31m-----------------------\033[0m\n");
	ft_printf("\033[1;31m      YOU GIVE UP      \033[0m\n");
	ft_printf("\033[1;31m-----------------------\033[0m\n");
	mlx_destroy_window(data->mlx, data->win);
	free_all(data);
	exit(0);
}

void	failed_sprite(t_game *data)
{
	mlx_destroy_window(data->mlx, data->win);
	free_all(data);
	print_errors(8);
	exit(0);
}
