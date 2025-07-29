#include "HumanB.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
HumanB::HumanB(void)
{
}
HumanB::HumanB(std::string name)
{
	this->_name = name;
}

HumanB::~HumanB(void)
{
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void	HumanB::attack(void)
{
	std::cout << this->_name << " atacks with their " << _weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
