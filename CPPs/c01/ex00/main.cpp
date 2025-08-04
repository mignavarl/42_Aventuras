/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:10:11 by mignavar          #+#    #+#             */
/*   Updated: 2025/08/01 13:44:08 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*new_zombie;
	
	new_zombie = newZombie("Pipo");
	new_zombie->announce();
	randomChump("Paco");
	delete new_zombie;
}
