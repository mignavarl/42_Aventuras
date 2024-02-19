/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 12:57:40 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/19 11:30:48 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_total_line(char **map)
{
	int	line;
	int	pos;

	line = 0;
	pos = 0;
	while (map[line])
	{
		while (map[line][pos] != '\n' && map[line][pos] != '\0')
			pos++;
		pos = 0;
		line++;
	}
	return (line);
}

int	get_tall(char *path)
{
	int		fd;
	int		tall;
	char	*line;

	fd = open(path, O_RDONLY);
	tall = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		tall++;
	}
	close(fd);
	return (tall);
}

char	**create_map(char *path)
{
	char	**map;
	int		fd;
	int		tall;
	int		i;

	tall = get_tall(path);
	map = ft_calloc(tall + 1, sizeof(char *));
	if (!map)
		return (0);
	fd = open(path, O_RDONLY);
	i = 0;
	while (i <= tall)
	{
		map[i] = get_next_line(fd);
		if (!map[0])
			return (close(fd), NULL);
		i++;
	}
	close(fd);
	return (map);
}
