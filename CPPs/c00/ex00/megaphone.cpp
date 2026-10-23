/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 11:02:58 by mignavar          #+#    #+#             */
/*   Updated: 2025/05/05 16:09:44 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char *av[])
{
	int	i;
	int	arg;

	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	arg = 1;
	while (arg < ac)
	{
		i = 0;
		while (av[arg][i])
		{
			std::cout << static_cast<char>(toupper(av[arg][i]));
			i++;
		}
		arg++;
	}
	std::cout << std::endl;
	return(0);
}