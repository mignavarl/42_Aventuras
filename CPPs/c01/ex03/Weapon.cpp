#include "Weapon.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Weapon::Weapon(void)
{
}

Weapon::Weapon(std::string type)
{
	setType(type);
}

Weapon::~Weapon(void)
{
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

std::string Weapon::getType(void)
{
	return (this->type);
}

void Weapon::setType(std::string type)
{
	this->type = type;
}
