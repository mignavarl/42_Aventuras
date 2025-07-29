#include "HumanA.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
// HumanA::HumanA(void)
// {
// }

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon)
{
}

HumanA::~HumanA(void)
{
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void	HumanA::attack(void)
{
	std::cout << this->_name << " atacks with their " << this->_weapon.getType() << std::endl;
}
