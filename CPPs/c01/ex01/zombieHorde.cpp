/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:24:09 by mignavar          #+#    #+#             */
/*   Updated: 2025/05/27 19:02:41 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie *horde;
	int	i;

	i = 0;
	horde = new Zombie[N];
	while (i < N)
	{
		horde[i].SetName(name);
		horde[i].announce();
		i++;
	}
	return (horde);
}