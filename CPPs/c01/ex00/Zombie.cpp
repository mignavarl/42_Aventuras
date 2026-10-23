#include "Zombie.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie(void)
{
	std::cout << RED << this->name << ": Zombie destructor called" NC << std::endl;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void	Zombie::announce(void)
{
	std::cout << MAGENTA << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
