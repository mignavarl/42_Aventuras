/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_check_objects.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 13:22:32 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/19 11:29:11 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_wall(char **map, int total_line)
{
	int	wall;
	int	line;

	wall = 0;
	line = 0;
	while (map[0][wall + 1] != '\n' && map[0][wall + 1] != '\0')
	{
		if (map[0][wall] != '1' || map[total_line][wall] != '1')
			return (1);
		wall++;
	}
	while (line <= total_line)
	{
		if (map[line][0] != '1' || map[line][wall] != '1')
			return (1);
		line++;
	}
	return (0);
}

int	check_pj(char **map, int total_line)
{
	int	pos;
	int	line;
	int	pj;

	pos = 1;
	line = 1;
	pj = 0;
	while (line < total_line)
	{
		while (map[line][pos] != '\0')
		{
			if (map[line][pos] == 'P')
				pj++;
			pos++;
		}
		pos = 1;
		line++;
	}
	return (pj);
}

int	check_col(char **map, int total_line)
{
	int	pos;
	int	line;
	int	col;

	pos = 1;
	line = 1;
	col = 0;
	while (line < total_line)
	{
		while (map[line][pos] != '\0')
		{
			if (map[line][pos] == 'C')
				col++;
			pos++;
		}
		pos = 1;
		line++;
	}
	return (col);
}

int	check_exit(char **map, int total_line)
{
	int	pos;
	int	line;
	int	exit;

	pos = 1;
	line = 1;
	exit = 0;
	while (line < total_line)
	{
		while (map[line][pos] != '\0')
		{
			if (map[line][pos] == 'E')
				exit++;
			pos++;
		}
		pos = 1;
		line++;
	}
	return (exit);
}

int	check_letter(char **map, int total_line)
{
	int	pos;
	int	line;

	pos = 0;
	line = 0;
	while (line < total_line)
	{
		while (map[line][pos] != '\n' && map[line][pos] != '\0')
		{
			if (map[line][pos] != '0' && map[line][pos] != '1'
					&& map[line][pos] != 'P' && map[line][pos] != 'C'
					&& map[line][pos] != 'E')
				return (1);
			pos++;
		}
		pos = 0;
		line++;
	}
	return (0);
}
