#include "ScavTrap.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
ScavTrap::ScavTrap(void) : ClapTrap()
{
	std::cout << GREEN "ScavTrap default constructor called" NC << std::endl;
	this->_name = "no_name";
	this->_health = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN "ScavTrap name constructor called" NC << std::endl;
	this->_name = name;
	this->_health = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap(ScavTrap const& other) : ClapTrap(this->_name)
{
	std::cout << GREEN "ScavTrap copy constructor called" NC << std::endl;
	this->_name = other._name;
	this->_health = 100;
	this->_energy = 50;
	this->_attack_damage = 20;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << RED "ScavTrap destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
ScavTrap& ScavTrap::operator=(ScavTrap const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->_name << " entra en modo guardián\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (this->_health <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " está muerto. No puede atacar\n";
		return;
	}
	if (this->_energy == 0)
	{
		std::cout << "ScavTrap " << this->_name << " no tiene energía para atacar\n";
		return;
	}
	std::cout << "ScavTrap " << this->_name << " ataca a " << target << ", causando " << this->_attack_damage << " puntos de daño\n";
	this->_energy--;
}