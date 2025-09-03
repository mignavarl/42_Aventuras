#include "ShrubberyCreationForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(void)
{
	std::cout << GREEN "ShrubberyCreationForm default constructor called" NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other)
{
	std::cout << GREEN "ShrubberyCreationForm copy constructor called" NC << std::endl;
	*this = other;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << RED "ShrubberyCreationForm destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
ShrubberyCreationForm& ShrubberyCreationForm::operator=(ShrubberyCreationForm const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
