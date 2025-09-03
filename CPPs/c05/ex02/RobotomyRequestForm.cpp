#include "RobotomyRequestForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(void)
{
	std::cout << GREEN "RobotomyRequestForm default constructor called" NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other)
{
	std::cout << GREEN "RobotomyRequestForm copy constructor called" NC << std::endl;
	*this = other;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << RED "RobotomyRequestForm destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
RobotomyRequestForm& RobotomyRequestForm::operator=(RobotomyRequestForm const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
