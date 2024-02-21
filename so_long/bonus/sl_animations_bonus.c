/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_animations_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 14:44:15 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/21 12:15:46 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	animate_sea(t_game *data)
{
	static int	frames;

	if (!frames)
		frames = 0;
	if (frames < 40)
		put_walls(data, data->sprite.wall);
	else if (frames < 80)
		put_walls(data, data->sprite.wall_2);
	else if (frames == 80)
		frames = 0;
	frames++;
	return (0);
}

int	number_movements(t_game *data, t_img *sprite)
{
	if (!sprite->black)
		return (1);
	if (!data->mov)
		data->mov = 0;
	mlx_put_image_to_window(data->mlx, data->win, sprite->black,
		0, (get_total_line(data->map) * 64));
	mlx_string_put(data->mlx, data->win, 0,
		((get_total_line(data->map)) * 64), 0xE1A6FF, ft_itoa(data->mov));
	return (0);
}
