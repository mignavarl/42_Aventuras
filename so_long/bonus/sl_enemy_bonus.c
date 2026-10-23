/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:56:39 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/21 11:48:38 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	put_enemy(t_game *data, t_img *sprite)
{
	int		pos;
	int		line;

	pos = 0;
	line = 0;
	if (!sprite->enemy)
		return (1);
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
	return (0);
}

void	enemy_kill(t_game *data)
{
	if (data->map[data->y][data->x] == 'S')
	{
		ft_printf("\033[1;31m---------------------\033[0m\n");
		ft_printf("\033[1;31m      YOU  LOSE      \033[0m\n");
		ft_printf("\033[1;31m---------------------\033[0m\n");
		mlx_destroy_window(data->mlx, data->win);
		free_all(data);
		exit(0);
	}
}
