#include "Form.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Form::Form(std::string name, int sign_grade, int execute_grade) : _name(name), _sign_grade(sign_grade), _execute_grade(execute_grade)
{
	std::cout << GREEN "Form default constructor called" NC << std::endl;
	_is_signed = false;
}

Form::Form(Form const& other) : _name(other._name), _sign_grade(other._sign_grade), _execute_grade(other._execute_grade)
{
	std::cout << GREEN "Form copy constructor called" NC << std::endl;
	_is_signed = other._is_signed;
}

Form::~Form(void)
{
	std::cout << RED "Form destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Form& Form::operator=(Form const& other)
{
	if (this == &other) {
		return *this;
	}
	this->_is_signed = other._is_signed;
	return *this;
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
	o << "Formulario " << form.get_name() << ":\n\t- Grado para firmar: " << form.get_sign_grade() << "\n\t- Grado para ejecutar: " << form.get_execute_grade() << std::endl;
 	return (o);
}
// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

const std::string Form::get_name(void) const
{
	return (this->_name);
}

int Form::get_sign_grade(void) const
{
	return (this->_sign_grade);
}

int Form::get_execute_grade(void) const
{
	return (this->_execute_grade);
}

void Form::beSigned(Bureaucrat *bur)
{
	if (this->_sign_grade >= bur->get_grade())
		this->_is_signed = true;
	else
		throw (GradeTooLowException());
}