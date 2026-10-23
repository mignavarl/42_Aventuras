#include "Dog.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Dog::Dog(void) : Animal()
{
	std::cout << GREEN "Dog default constructor called" NC << std::endl;
	this->type = "Dog";
}

Dog::Dog(Dog const& other) : Animal()
{
	std::cout << GREEN "Dog copy constructor called" NC << std::endl;
	this->type = other.type;
}

Dog::~Dog(void)
{
	std::cout << RED "Dog destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Dog& Dog::operator=(Dog const& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void Dog::makeSound(void) const
{
	std::cout << this->type << " ladra: \"¡GUAU!\" 🐶\n";
}