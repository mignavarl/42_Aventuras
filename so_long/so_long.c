/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:54:56 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/19 16:50:44 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_objects(char **map, int total_line)
{
	if (check_wall(map, total_line) == 1)
		return (2);
	if (check_pj(map, total_line) != 1)
		return (3);
	if (check_col(map, total_line) == 0)
		return (4);
	if (check_exit(map, total_line) != 1)
		return (5);
	if (check_letter(map, total_line) == 1)
		return (6);
	if (fill_map(map, total_line, ft_strlen_no_n(map[0])) == 1)
		return (7);
	return (0);
}

int	check_rectangle(char **map, int total_line)
{
	int	line;
	int	len_line;
	int	final_line;

	line = 0;
	len_line = ft_strlen_no_n(map[line]);
	final_line = ft_strlen_no_n(map[total_line]);
	if (total_line < 2 || final_line < 2 || (total_line == 2 && final_line < 5)
		|| (final_line == 2 && total_line < 5))
		return (1);
	while (line < total_line)
	{
		if (len_line != final_line)
			return (1);
		line++;
		len_line = ft_strlen_no_n(map[line]);
	}
	return (0);
}

int	check_map(char **map)
{
	int	e;
	int	total_line;

	total_line = get_total_line(map);
	e = check_rectangle(map, --total_line);
	if (e == 1)
		return (1);
	e = check_objects(map, total_line);
	if (e != 0)
		return (e);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	data;
	int		error;

	if (error_arg(ac, av) == 1)
		return (1);
	data.map = create_map(av[1]);
	if (!data.map)
		return (1);
	if (get_total_line(data.map) > 22 && ft_strlen_no_n(data.map[0]) > 40)
	{
		print_errors(0);
		return (0);
	}
	error = check_map(data.map);
	if (error != 0)
	{
		print_errors(error);
		return (0);
	}
	free_all(&data);
	data.map = create_map(av[1]);
	init_game(&data);
	return (0);
}
