#include "DiamondTrap.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
DiamondTrap::DiamondTrap(void) :  ClapTrap("no_name_clap_name")
{
	std::cout << GREEN "DiamondTrap default constructor called" NC << std::endl;
	this->_name = "no_name";
	ClapTrap::_name = this->_name + "_clap_name";
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name)
{
	std::cout << GREEN "DiamondTrap name constructor called" NC << std::endl;
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_health = FragTrap::_health;
	this->_energy = ScavTrap::_energy;
	this->_attack_damage = FragTrap::_attack_damage;
}

DiamondTrap::DiamondTrap(DiamondTrap const& other) : ClapTrap(other._name + "_clap_name"), ScavTrap(other._name), FragTrap(other._name)
{
	std::cout << GREEN "DiamondTrap copy constructor called" NC << std::endl;
	this->_name = other._name;
	ClapTrap::_name = this->_name + "_clap_name";
	this->_health = other._health;
	this->_energy = other._energy;
	this->_attack_damage = other._attack_damage;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << RED "DiamondTrap destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
DiamondTrap& DiamondTrap::operator=(DiamondTrap const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

std::string	&DiamondTrap::getName(void)
{
	return (this->_name);
}

int &DiamondTrap::getHealth(void)
{
	return (this->_health);
}

int &DiamondTrap::getEnergy(void)
{
	return (this->_energy);
}

int &DiamondTrap::getAttack(void)
{
	return (this->_attack_damage);
}



void DiamondTrap::whoAmI(void)
{
	std::cout << "Soy DiamondTrap y me llamo: " << this->_name << std::endl;
	std::cout << "Soy ClapTrap y me llamo: " << ClapTrap::_name << std::endl;
}

void	DiamondTrap::getDiam_stats(void)
{
	std::cout << "Stats de " << this->_name << std::endl;
	std::cout << "Vida:......" << this->_health << std::endl;
	std::cout << "Energía:..." << this->_energy << std::endl;
	std::cout << "Ataque:...." << this->_attack_damage << std::endl;
}
