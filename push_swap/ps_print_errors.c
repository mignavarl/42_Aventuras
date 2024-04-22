/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_print_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 12:29:24 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/09 14:28:58 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *error, t_data data)
{
	ft_printf(RED"Error\n%s\n"END, error);
	if (data.bunker)
		free_bunker(data);
	exit(0);
}
