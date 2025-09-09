#include "AForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
AForm::AForm(std::string name, int sign_grade, int execute_grade) : _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	std::cout << GREEN "AForm default constructor called" NC << std::endl;
	_is_signed = false;
}

AForm::AForm(AForm const& other) : _name(other._name), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
	std::cout << GREEN "AForm copy constructor called" NC << std::endl;
	_is_signed = other._is_signed;
}

AForm::~AForm(void)
{
	std::cout << RED "AForm destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
AForm& AForm::operator=(AForm const& other)
{
	if (this == &other) {
		return *this;
	}
	this->_is_signed = other._is_signed;
	return *this;
}

std::ostream &operator<<(std::ostream &o, const AForm &Aform)
{
	o << "Formulario " << Aform.get_name() << ":\n\t- Grado para firmar: " << Aform.get_sign_grade() << "\n\t- Grado para ejecutar: " << Aform.get_execute_grade() << std::endl;
 	return (o);
}
// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

const std::string AForm::get_name(void) const
{
	return (this->_name);
}

int AForm::get_sign_grade(void) const
{
	return (this->_sign_grade);
}

int AForm::get_execute_grade(void) const
{
	return (this->_execute_grade);
}

void AForm::beSigned(Bureaucrat *bur)
{
	if (this->_sign_grade >= bur->get_grade())
		this->_is_signed = true;
	else
		throw (GradeTooLowException());
}

void execute(Bureaucrat const & executor)
{
	(void)executor;
}