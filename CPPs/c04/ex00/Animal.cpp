#include "Animal.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Animal::Animal(void)
{
	std::cout << GREEN "Animal default constructor called" NC << std::endl;
}

Animal::Animal(Animal const& other)
{
	std::cout << GREEN "Animal copy constructor called" NC << std::endl;
	*this = other;
}

Animal::~Animal(void)
{
	std::cout << RED "Animal destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Animal& Animal::operator=(Animal const& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << "Absoluto silencio\n";
}