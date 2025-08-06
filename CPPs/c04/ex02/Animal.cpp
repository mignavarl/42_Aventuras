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
}

std::string Animal::getIdea(int i)
{
	(void)i;
	return ("Nada que hacer aquí");
}
void Animal::setIdea(std::string idea, int i)
{
	(void)idea;
	(void)i;
	std::cout << "Nada que hacer aquí\n";
}