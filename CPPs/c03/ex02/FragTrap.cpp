#include "FragTrap.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
FragTrap::FragTrap(void) : ClapTrap()
{
	std::cout << GREEN "FragTrap default constructor called" NC << std::endl;
	this->_name = "no_name";
	this->_health = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN "FragTrap name constructor called" NC << std::endl;
	this->_name = name;
	this->_health = 100;
	this->_energy = 100;
	this->_attack_damage = 30;
}

FragTrap::FragTrap(FragTrap const& other) : ClapTrap(other._name)
{
	std::cout << GREEN "FragTrap copy constructor called" NC << std::endl;
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_attack_damage = other._attack_damage;
}

FragTrap::~FragTrap(void)
{
	std::cout << RED "FragTrap destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
FragTrap& FragTrap::operator=(FragTrap const& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_health = other._health;
		this->_energy = other._energy;
		this->_attack_damage = other._attack_damage;	
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void FragTrap::highFivesGuys(void)
{
	std::cout << "✋ ¡¡CHOCA ESOS CINCO!! ✋\n";
}