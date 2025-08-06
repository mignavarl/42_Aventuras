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
	int i;

	i = 0;
	if (this == &other)
		return *this;
	while (i < 100)
	{
		if (other.ideas[i].length() > 0)
			this->setBrainIdea(other.ideas[i], i);
		i++;
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

std::string Brain::getBrainIdea(int i)
{
	return (this->ideas[i]);
}
void Brain::setBrainIdea(std::string idea, int i)
{
	this->ideas[i] = idea;
}