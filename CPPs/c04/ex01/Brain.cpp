#include "Brain.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Brain::Brain(void)
{
	std::cout << GREEN "Brain default constructor called" NC << std::endl;
}

Brain::Brain(Brain const& other)
{
	std::cout << GREEN "Brain copy constructor called" NC << std::endl;
	*this = other;
}

Brain::~Brain(void)
{
	std::cout << RED "Brain destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Brain& Brain::operator=(Brain const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

std::string Brain::getIdea(int i)
{
	if (!this->ideas[i].length())
		return (NULL);
	return (this->ideas[i]);
}
void Brain::setIdea(std::string idea, int i)
{
	this->ideas[i] = idea;
}