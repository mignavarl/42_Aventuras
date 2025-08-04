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

void	HumanB::attack(void) const
{
	std::string wep = this->_weapon->getType();
	std::cout << this->_name << " atacks with their " << wep << std::endl;
}

void	HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}
