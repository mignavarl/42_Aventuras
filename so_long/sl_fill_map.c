/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:03:28 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/19 11:29:59 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill_pj(char **map, int line, int pos)
{
	map[line][pos] = 'P';
	if (map[line][pos + 1] == '0' || map[line][pos + 1] == 'C'
		|| map[line][pos + 1] == 'E')
		fill_pj(map, line, pos + 1);
	if (map[line][pos - 1] == '0' || map[line][pos - 1] == 'C'
		|| map[line][pos - 1] == 'E')
		fill_pj(map, line, pos - 1);
	if (map[line + 1][pos] == '0' || map[line + 1][pos] == 'C'
		|| map[line + 1][pos] == 'E')
		fill_pj(map, line + 1, pos);
	if (map[line - 1][pos] == '0' || map[line - 1][pos] == 'C'
		|| map[line - 1][pos] == 'E')
		fill_pj(map, line - 1, pos);
}

int	fill_map(char **map, int total_line, int final_pos)
{
	int	pos;
	int	line;

	pos = 1;
	line = 1;
	while (map[line][pos] != '\0')
	{
		while (pos < final_pos)
		{
			if (map[line][pos] == 'P')
				break ;
			pos++;
		}
		if (map[line][pos] == 'P')
			break ;
		pos = 1;
		line++;
	}
	fill_pj(map, line, pos);
	if (check_col(map, total_line) != 0 || check_exit(map, total_line) != 0)
		return (1);
	return (0);
}
