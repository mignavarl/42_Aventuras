/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 17:10:11 by mignavar          #+#    #+#             */
/*   Updated: 2025/05/26 18:16:02 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie	*new_zombie;
	
	new_zombie = newZombie("Pepe");
	new_zombie->announce();
	randomChump("Paco");
	delete new_zombie;
}
