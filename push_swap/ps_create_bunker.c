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

char	**extract_number(t_data data, char **argv, int argc, char **bunker)
{
	int	num;
	int	ac;
	int	len_num;
	int	pos;

	num = 0;
	pos = 0;
	ac = 1;
	while (num <= data.numbers && ac <= argc)
	{
		while (argv[ac][pos] != '\0')
		{
			if (argv[ac][pos] != ' ')
			{
				len_num = length_number(&argv[ac][pos]);
				bunker[num] = ft_substr(argv[ac], pos, len_num);
				num++;
				pos += len_num - 1;
			}
			pos++;
		}
		pos = 0;
		ac++;
	}
	return (bunker);
}

char	**create_bunker(char **argv, int argc, t_data data)
{
	char	**bunker;

	bunker = (char **)ft_calloc((data.numbers), sizeof(char *));
	bunker = extract_number(data, argv, argc, bunker);
	return (bunker);
}
