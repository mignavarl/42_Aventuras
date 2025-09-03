#include "PresidentialPardonForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << GREEN "PresidentialPardonForm default constructor called" NC << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << GREEN "PresidentialPardonForm copy constructor called" NC << std::endl;
	this->_is_signed = other._is_signed;
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << RED "PresidentialPardonForm destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
PresidentialPardonForm& PresidentialPardonForm::operator=(PresidentialPardonForm const& other)
{
	if (this == &other) {
		return *this;
	}
	this->_is_signed = other._is_signed;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
