#include "PresidentialPardonForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << GREEN "PresidentialPardonForm default constructor called" NC << std::endl;
	this->_target = "no_name";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << GREEN "PresidentialPardonForm target constructor called" NC << std::endl;
	this->_target = target;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const& other) : AForm("Presidential Pardon", 25, 5)
{
	std::cout << GREEN "PresidentialPardonForm copy constructor called" NC << std::endl;
	this->_is_signed = other._is_signed;
	this->_target = other._target;
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
	this->_target = other._target;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (executor.get_grade() <= this->_execute_grade)
		std::cout << BLUE << this->_target << " ha sido perdonado por Zaphod Beeblebrox 🎉\n" << NC;
	else
		throw (GradeTooLowException());
}