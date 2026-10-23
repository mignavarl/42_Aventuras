/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_collectables_map.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:57:00 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/22 11:59:47 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	put_col(t_game *data, t_img *sprite)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	if (!sprite->col)
		return (1);
	while (data->map[line])
	{
		while (data->map[line][pos] != '\n' && data->map[line][pos] != '\0')
		{
			if (data->map[line][pos] == 'C')
				mlx_put_image_to_window(data->mlx, data->win, sprite->col,
					pos * 64, line * 64);
			pos++;
		}
		pos = 0;
		line++;
	}
	return (0);
}

void	key_col(t_game *data)
{
	if (data->map[data->y][data->x] == 'C')
	{
		data->map[data->y][data->x] = '0';
		data->col--;
	}
}

void	key_exit(t_game *data)
{
	if (data->map[data->y][data->x] == 'E' && data->col == 0)
	{
		ft_printf("\033[1;32m--------------------\033[0m\n");
		ft_printf("\033[1;32m      YOU  WIN      \033[0m\n");
		ft_printf("\033[1;32m--------------------\033[0m\n");
		mlx_destroy_window(data->mlx, data->win);
		free_all(data);
		exit(0);
	}
}
