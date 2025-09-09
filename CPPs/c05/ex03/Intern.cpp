#include "Intern.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Intern::Intern(void)
{
	std::cout << GREEN "Intern default constructor called" NC << std::endl;
}

Intern::Intern(Intern const& other)
{
	std::cout << GREEN "Intern copy constructor called" NC << std::endl;
	*this = other;
}

Intern::~Intern(void)
{
	std::cout << RED "Intern destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Intern& Intern::operator=(Intern const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
AForm *Intern::makeForm(std::string form_name, std::string target)
{
	if (form_name == "shrubbery creation")
	{
		AForm *form = new ShrubberyCreationForm();
		return (form);
	}
	else if (form_name == "robotomy request")
	{
		;
	}
	else if (form_name == "presidential pardon")
	{
		;
	}
	else
	{
		std::cout << RED "Formulario Incorrecto\n" "Los disponibles son:\n\t- shrubbery creation\n\t- robotomy request\n\t- presidential pardon\n";
		return (NULL);
	}
}