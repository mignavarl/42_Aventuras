/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_window_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:24:24 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/20 14:25:12 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_move(int key, t_game *data)
{
	static int	mov;

	if (!mov)
		mov = 1;
	if ((key == 13 || key == 126) && data->map[data->y - 1][data->x] != '1')
	{
		ft_printf("Nº Movimientos: %d\n", mov++);
		(data->y)--;
	}
	if ((key == 1 || key == 125) && data->map[data->y + 1][data->x] != '1')
	{
		ft_printf("Nº Movimientos: %d\n", mov++);
		(data->y)++;
	}
	if ((key == 2 || key == 124) && data->map[data->y][data->x + 1] != '1')
	{
		ft_printf("Nº Movimientos: %d\n", mov++);
		(data->x)++;
	}
	if ((key == 0 || key == 123) && data->map[data->y][data->x - 1] != '1')
	{
		ft_printf("Nº Movimientos: %d\n", mov++);
		(data->x)--;
	}
}

int	other_keycode(int key, t_game *data)
{
	if (key == 53)
	{
		mlx_destroy_window(data->mlx, data->win);
		free_all(data);
		exit(0);
	}
	if (key == 18 && key == 19)
	{
		ft_printf("FUNCIONA\n");
		return (0);
	}
	return (0);
}

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
	sprite->open = mlx_xpm_file_to_image(data->mlx,
			"./textures/chest_open.xpm", &w, &h);
}

int	key_event(int key, t_game *data)
{
	key_move(key, data);
	key_col(data);
	key_exit(data);
	if (other_keycode(key, data) == 1)
		return (1);
	restore_player(data, &data->sprite);
	return (0);
}

int	init_game(t_game *data)
{
	data->col = check_col(data->map, get_total_line(data->map));
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, ft_strlen_no_n(data->map[0]) * 64,
			get_total_line(data->map) * 64, "so_long");
	init_sprite(&data->sprite, data);
	data->x = 0;
	data->y = 0;
	if (put_background(data, &data->sprite) != 0)
		return (1);
	pos_player(data);
	if (put_player(data, &data->sprite) != 0)
		return (1);
	mlx_hook(data->win, 2, 1L >> 0, key_event, data);
	mlx_hook(data->win, 17, 0L, cross_window, data);
	mlx_loop(data->mlx);
	return (0);
}
