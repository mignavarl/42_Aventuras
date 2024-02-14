/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:24:24 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/14 16:54:40 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_img *sprite, t_game *data)
{
	int	w;
	int	h;

	sprite->pj = mlx_xpm_file_to_image(data->mlx, "./textures/pirate.xpm",
					&w, &h);
	sprite->floor = mlx_xpm_file_to_image(data->mlx, "./textures/floor.xpm",
					&w, &h);
	sprite->wall = mlx_xpm_file_to_image(data->mlx, "./textures/sea.xpm",
					&w, &h);
	sprite->exit = mlx_xpm_file_to_image(data->mlx, "./textures/chest.xpm",
					&w, &h);
	sprite->col = mlx_xpm_file_to_image(data->mlx, "./textures/rum.xpm",
					&w, &h);
}

int	key_event(int keycode, t_game *data)
{
	if (keycode == 13 || keycode == 126)
	{
		if (data->map[data->y-1][data->x] == '1')
			return (0);
		(data->y)--;
	}
	if (keycode == 1 || keycode == 125)
	{	if (data->map[data->y+1][data->x] != '1')
			(data->y)++;
	}
	if (keycode == 2 || keycode == 124)
	{
		if (data->map[data->y][data->x+1] != '1')
			(data->x)++;
	}
	if (keycode == 0 || keycode == 123)
	{
		if (data->map[data->y][data->x-1] != '1')
			(data->x)--;
	}
	ft_printf("Tecla: %d\n", keycode);
	restore_player(data, &data->sprite);
	return (0);
}

void	init_game(t_game *data)
{

	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, ft_strlen_no_n(data->map[0]) * 64,
				get_total_line(data->map) * 64, "so_long");
	init_sprite(&data->sprite, data);
	data->x = 0;
	data->y = 0;

	put_background(data, &data->sprite);
	pos_player(data);
	put_player(data, &data->sprite);
	mlx_key_hook(data->win, key_event, data);
	mlx_loop(data->mlx);
}
