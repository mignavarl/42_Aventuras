#include "ClapTrap.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
ClapTrap::ClapTrap(void)
{
	std::cout << GREEN "ClapTrap default constructor called" NC << std::endl;
	this->_name = "no_name";
	this->_health = 10;
	this->_energy = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
	std::cout << GREEN "ClapTrap name constructor called" NC << std::endl;
	this->_name = name;
	this->_health = 10;
	this->_energy = 10;
	this->_attack_damage = 0;
}

ClapTrap::ClapTrap(ClapTrap const& other)
{
	std::cout << GREEN "ClapTrap copy constructor called" NC << std::endl;
	this->_name = other._name;
	this->_health = other._health;
	this->_energy = other._energy;
	this->_attack_damage = other._attack_damage;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << RED "ClapTrap destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
ClapTrap& ClapTrap::operator=(ClapTrap const& other)
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
void ClapTrap::attack(const std::string& target)
{
	if (this->_health <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " está muerto. No puede atacar\n";
		return;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " no tiene energía para atacar\n";
		return;
	}
	std::cout << "ClapTrap " << this->_name << " ataca a " << target << ", causando " << this->_attack_damage << " puntos de daño\n";
	this->_energy--;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_health <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " está muerto. No hace falta rematarle\n";
		return;
	}
	std::cout << "ClapTrap " << this->_name << " ha sufrido " << amount << " de daño\n";
	this->_health -= amount;
	if (this->_health <= 0)
		std::cout << "ClapTrap " << this->_name << " ha muerto\n";
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_health <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " está muerto. No puede repararse\n";
		return;
	}
	if (this->_energy == 0)
	{
		std::cout << "ClapTrap " << this->_name << " no tiene energía para repararse\n";
		return;
	}
	std::cout << "ClapTrap " << this->_name << " se ha reparado " << amount << " de vida\n";
	this->_health += amount;
	this->_energy--;
}

std::string ClapTrap::getClap_name(void)
{
	return (this->_name);
}
