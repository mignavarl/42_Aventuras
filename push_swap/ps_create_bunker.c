/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_create_bunker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:33:58 by mignavar          #+#    #+#             */
/*   Updated: 2024/04/23 16:04:23 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	length_number(char *str)
{
	int	l;
	int	num;

	l = 0;
	num = 0;
	while (str[l])
	{
		if (str[l] == ' ')
			l++;
		else if (ft_isdigit(str[l]) == 1 || str[l] == '-' || str[l] == '+')
		{
			l++;
			num++;
		}
		else
			l++;
		if (str[l] == ' ' && ft_isdigit(str[l - 1]) == 1)
			return (num);
	}
	return (num);
}

char	**create_bunker(char **argv, int argc, t_data data)
{
	char	**bunker;
	int		num;
	int		len_num;
	int		pos;

	bunker = (char **)ft_calloc((data.numbers), sizeof(char *));
	num = 0;
	pos = 0;
	while (num <= data.numbers && argc > 0)
	{
		while (argv[argc][pos] != '\0')
		{
			if (argv[argc][pos] != ' ')
			{
				len_num = length_number(&argv[argc][pos]);
				bunker[num] = ft_substr(argv[argc], pos, len_num);
				num++;
				pos += len_num - 1;
			}
			pos++;
		}
		pos = 0;
		argc--;
	}
	return (bunker);
}
