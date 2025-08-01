#include "Dog.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Dog::Dog(void) : Animal()
{
	std::cout << GREEN "Dog default constructor called" NC << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog(Dog const& other) : Animal()
{
	std::cout << GREEN "Dog copy constructor called" NC << std::endl;
	*this = other;
}

Dog::~Dog(void)
{
	delete(this->brain);
	std::cout << RED "Dog destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Dog& Dog::operator=(Dog const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void Dog::makeSound(void) const
{
	std::cout << this->type << " ladra: \"¡GUAU!\" 🐶\n";
}

std::string Dog::getIdea(int i)
{
	if (!this->brain->getBrainIdea(i).length())
		return ("No Idea");
	return (this->brain->getBrainIdea(i));
}
void Dog::setIdea(std::string idea, int i)
{
	this->brain->setBrainIdea(idea, i);
}
