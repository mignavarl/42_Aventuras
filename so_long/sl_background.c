/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_background.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 12:49:27 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/19 11:28:42 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_exit(t_game *data, t_img *sprite)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (data->map[line])
	{
		while (data->map[line][pos] != '\n' && data->map[line][pos] != '\0')
		{
			if (data->map[line][pos] == 'E' && data->col != 0)
				mlx_put_image_to_window(data->mlx, data->win, sprite->exit,
					pos * 64, line * 64);
			if (data->map[line][pos] == 'E' && data->col == 0)
				mlx_put_image_to_window(data->mlx, data->win, sprite->open,
					pos * 64, line * 64);
			pos++;
		}
		pos = 0;
		line++;
	}
}

void	put_floor(t_game *data, t_img *sprite)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (data->map[line])
	{
		while (data->map[line][pos] != '\n' && data->map[line][pos] != '\0')
		{
			if (data->map[line][pos] == '0' || data->map[line][pos] == 'P'
				|| data->map[line][pos] == 'C' || data->map[line][pos] == 'E')
				mlx_put_image_to_window(data->mlx, data->win, sprite->floor,
					pos * 64, line * 64);
			pos++;
		}
		pos = 0;
		line++;
	}
}

void	put_walls(t_game *data, t_img *sprite)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	while (data->map[line])
	{
		while (data->map[line][pos] != '\n' && data->map[line][pos] != '\0')
		{
			if (data->map[line][pos] == '1')
				mlx_put_image_to_window(data->mlx, data->win, sprite->wall,
					pos * 64, line * 64);
			pos++;
		}
		pos = 0;
		line++;
	}
}

void	put_background(t_game *data, t_img *sprite)
{
	put_walls(data, sprite);
	put_floor(data, sprite);
	put_exit(data, sprite);
	put_col(data, sprite);
}
