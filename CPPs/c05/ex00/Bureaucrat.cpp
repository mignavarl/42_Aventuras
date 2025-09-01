#include "Bureaucrat.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade)
{
	std::cout << GREEN "Bureaucrat name constructor called" NC << std::endl;
	if (grade < 1)
		throw (GradeTooHighException());
	if (grade > 150)
		throw (GradeTooLowException());
}

Bureaucrat::Bureaucrat(Bureaucrat const& other) : _name(other._name)
{
	std::cout << GREEN "Bureaucrat copy constructor called" NC << std::endl;
	this->_grade = other._grade;
}

Bureaucrat::~Bureaucrat(void)
{
	std::cout << RED "Bureaucrat destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Bureaucrat& Bureaucrat::operator=(Bureaucrat const& other)
{
	if (this != &other)
		this->_grade = other._grade;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
std::string Bureaucrat::get_name(void)
{
	return (this->_name);
}

int Bureaucrat::get_grade(void)
{
	return (this->_grade);
}

void Bureaucrat::increment_grade(void)
{
	if (this->_grade == 1)
		std::cout << "Imposible ascender más\n";
	else
		this->_grade++;
}

void Bureaucrat::decrement_grade(void)
{
	if (this->_grade == 150)
		std::cout << "Imposible descender más\n";
	else
		this->_grade--;
}

std::ostream &operator<<(std::ostream &o, Bureaucrat &bur)
{
	o << bur.get_name() << ", burócrata de grado " << bur.get_grade();
	return (o);
}