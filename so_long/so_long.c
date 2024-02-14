/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 10:54:56 by mignavar          #+#    #+#             */
/*   Updated: 2024/02/14 18:09:57 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_objects(char **map, int total_line)
{
	if (check_wall(map, total_line) == 1)
		return (1);
	ft_printf("Muros bien\n");
	if (check_pj(map, total_line) != 1)
		return (1);
	ft_printf("Pj bien\n");
	if (check_col(map, total_line) == 0)
		return (1);
	ft_printf("Coleccionables bien\n");
	if (check_exit(map, total_line) != 1)
		return (1);
	ft_printf("Salida bien\n");
	if (check_letter(map, total_line) == 1)
		return (1);
	ft_printf("Letras bien\n");
	if (fill_map(map, total_line, ft_strlen_no_n(map[0])) == 1)
		return (1);
	ft_printf("Mapa relleno\n");
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
		if (line == 2)
			ft_printf("solo linea 2: %s\n", map[line]);
		ft_printf("n line: %d total line: %d(line: %d total: %d)\n", line, total_line, len_line, final_line);
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
	print_map(map);
	e = check_objects(map, total_line);//le tengo que enviar una copia para poder moverme por el mapa original, ¿strdup?
	if (e == 1)
		return (1);
	return (0);
}


int	main(int ac, char **av)
{
	t_game	data;

	if (error_arg(ac, av) == 1)
		return (1);
	//CREACION DEL MAPA
	data.map = create_map(av[1]);
	if (!data.map)
		return (1);
	//COMPROBAR MAPA
	if (check_map(data.map) == 0)
		ft_printf("\n\033[1;32mMapa güeno, si si\033[0m\n");
	else
	{
		ft_printf("--------------\n");
		ft_printf("\n\033[1;31mMapa malo, no no\033[0m\n");
		return (0);
	}
	free(data.map);
	data.map = create_map(av[1]);
	init_game(&data);
	return (0);
}
