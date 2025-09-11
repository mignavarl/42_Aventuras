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
	if (this == &other)
		return *this;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
AForm *makeShrubbery(std::string target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *makeRobotomy(std::string target)
{
	return (new RobotomyRequestForm(target));
}

AForm *makePardon(std::string target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeForm(std::string form_name, std::string target)
{
	std::string classes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(*forms[3])(std::string target) = {&makeShrubbery, &makeRobotomy, &makePardon};

	for (size_t i = 0; i < 3; i++)
	{
		if (form_name == classes[i])
		{
			std::cout << "Becario creó " << classes[i] << std::endl;
			return (forms[i](target));
		}
	}
	std::cout << RED "Formulario Incorrecto\n" "Los disponibles son:\n\t- shrubbery creation\n\t- robotomy request\n\t- presidential pardon\n" NC;
	return (NULL);
}