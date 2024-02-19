/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:56:39 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/19 18:13:07 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	put_enemy(t_game *data, t_img *sprite)//CREO QUE ES ESTO
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (data->map[line])
	{
		while (data->map[line][pos] != '\n' && data->map[line][pos] != '\0')
		{
			if (data->map[line][pos] == 'S')
				mlx_put_image_to_window(data->mlx, data->win, sprite->enemy,
					pos * 64, line * 64);
			pos++;
		}
		pos = 0;
		line++;
	}
}

void	enemy_kill(t_game *data)//EESTO FUNCIONA
{
	if (data->map[data->y][data->x] == 'S')
	{
		mlx_destroy_window(data->mlx, data->win);
		free_all(data);
		exit(0);
	}
}
