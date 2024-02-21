/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_player_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:13:05 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/20 16:59:48 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	pos_player(t_game *data)
{
	int	pos;
	int	line;

	pos = 1;
	line = 1;
	while (data->map[line])
	{
		while (data->map[line][pos] != '\n' && data->map[line][pos] != '\0')
		{
			if (data->map[line][pos] == 'P')
				break ;
			pos++;
		}
		if (data->map[line][pos] == 'P')
			break ;
		pos = 1;
		line++;
	}
	data->x = pos;
	data->y = line;
}

int	put_player(t_game *data, t_img *sprite)
{
	if (!sprite->pj)
		return (1);
	mlx_put_image_to_window(data->mlx, data->win, sprite->pj,
		data->x * 64, data->y * 64);
	return (0);
}

void	restore_player(t_game *data, t_img *sprite)
{
	put_background(data, sprite);
	put_player(data, sprite);
}
