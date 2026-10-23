/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:23:42 by mignavar          #+#    #+#             */
/*   Updated: 2025/08/01 13:55:12 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Zombie::Zombie(void)
{
}

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << RED << this->name << "Zombie destructor called" NC << std::endl;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void	Zombie::announce(void)
{
	std::cout << MAGENTA << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(std::string n)
{
	this->name = n;
}
