#include "Cat.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Cat::Cat(void) : Animal()
{
	std::cout << GREEN "Cat default constructor called" NC << std::endl;
	this->type = "Cat";
}

Cat::Cat(Cat const& other) : Animal()
{
	std::cout << GREEN "Cat copy constructor called" NC << std::endl;
	*this = other;
}

Cat::~Cat(void)
{
	std::cout << RED "Cat destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Cat& Cat::operator=(Cat const& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void Cat::makeSound(void) const
{
	std::cout << this->type << " maulla: \"Nya\" 🐱\n";
}