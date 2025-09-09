#include "ShrubberyCreationForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << GREEN "ShrubberyCreationForm default constructor called" NC << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << GREEN "ShrubberyCreationForm copy constructor called" NC << std::endl;
	this->_is_signed = other._is_signed;
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
	this->_is_signed = other._is_signed;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.get_grade() <= this->_execute_grade)
		std::cout << GREEN << 
		"                                   &&                \n" <<
		"                                   &&&&&            \n" <<
		"                        &  &&& &    &&&& &           \n" <<
		"                   &  & &&&&&&&&&& &&/&&&            \n" <<
		"                    &&&&&&&&&&&&&&&&|&                \n" <<
		"                      &&|&&&&&&&&&&\\|& &             \n" <<
		"                      &&&&&&&&&&&&&&\\|&              \n" <<
		"                      &&&/|&&&&&&& &&|/&&&           \n" <<
		"                       /~&&&&&&&&  //~& &            \n" <<
		"                       & /&|&&&&  &\\|  &             \n" <<
		"               & &&  &&&&&//&~&  &/|/|\\              \n" <<
		"      &         &&&&&\\&&&&&&&/&\\  |/|/               \n" <<
		"      &          & &&&&&&&&&&|\\_\\__\\|__              \n" <<
		"  &  && &&&&         &&&&  \\_|//~   /~_              \n" <<
		" & && &_&&       \\_\\|  & \\/~/\\/~/  /~_//             \n" <<
		"  &  &&&  \\__|\\| \\__\\_    /~|//___/~\\/ /&& &&        \n" <<
		"     &  &    \\  \\     \\_\\| \\/~\\/~|/~   /  &&&&  & &  \n" <<
		"                         \\_  /~|/~~/    &&_/_&&&&    \n" <<
		"                             \\/~ /_&/__& &&&&&&&& &  \n" <<
		"                              //~      &&&&&_&/&&    \n" << NC << MAGENTA <<
		"               :___________./~~~\\.___________:       \n" <<
		"                \\                           /        \n" <<
		"                 \\_________________________/         \n" <<
		"                 (_)                     (_)         \n" << NC;
	else
		throw (GradeTooLowException());
}
