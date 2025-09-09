#include "RobotomyRequestForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Robotomy Request", 72, 45)
{
	std::cout << GREEN "RobotomyRequestForm default constructor called" NC << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const& other) : AForm("Robotomy Request", 72, 45)
{
	std::cout << GREEN "RobotomyRequestForm copy constructor called" NC << std::endl;
	this->_is_signed = other._is_signed;
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
	this->_is_signed = other._is_signed;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (executor.get_grade() <= this->_execute_grade)
	{
		srand(time(0));
		int r = rand() % 151;
		std::cout << YELLOW << "BZZZZZZ......\n";
		sleep(1);
		std::cout << "BZZZZZZZZZZZZZ......\n";
		sleep(1);
		std::cout << "BZZZZZZZZZZZZZZZZZZZZ......\n" << NC;
		sleep(1);
		if ((r % 2) == 0)
			std::cout << GREEN << "🤖 La Robotomia se ha completado con éxito 🤖\n" << NC;
		else
			std::cout << RED << "Oh oh.... El taladro se ha roto 🪦\n" << NC;
		
	}
	else
		throw (GradeTooLowException());
}