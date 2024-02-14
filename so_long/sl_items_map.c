/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_items_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:57:00 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/14 15:35:31 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_col(t_game *data, t_img *sprite)
{
	int		pos;
	int		line;
	
	pos = 0;
	line = 0;
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
}
