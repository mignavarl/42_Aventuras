#include "ShrubberyCreationForm.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << GREEN "ShrubberyCreationForm default constructor called" NC << std::endl;
	this->_target = "_no_name";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << GREEN "ShrubberyCreationForm default constructor called" NC << std::endl;
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const& other) : AForm("Shrubbery Creation", 145, 137)
{
	std::cout << GREEN "ShrubberyCreationForm copy constructor called" NC << std::endl;
	this->_is_signed = other._is_signed;
	this->_target = other._target;
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
	this->_target = other._target;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (executor.get_grade() <= this->_execute_grade)
	{
		std::string bush = 
		"                                   &&                \n" 
		"                                   &&&&&            \n" 
		"                        &  &&& &    &&&& &           \n" 
		"                   &  & &&&&&&&&&& &&/&&&            \n" 
		"                    &&&&&&&&&&&&&&&&|&                \n" 
		"                      &&|&&&&&&&&&&\\|& &             \n" 
		"                      &&&&&&&&&&&&&&\\|&              \n" 
		"                      &&&/|&&&&&&& &&|/&&&           \n" 
		"                       /~&&&&&&&&  //~& &            \n" 
		"                       & /&|&&&&  &\\|  &             \n" 
		"               & &&  &&&&&//&~&  &/|/|\\              \n" 
		"      &         &&&&&\\&&&&&&&/&\\  |/|/               \n" 
		"      &          & &&&&&&&&&&|\\_\\__\\|__              \n" 
		"  &  && &&&&         &&&&  \\_|//~   /~_              \n" 
		" & && &_&&       \\_\\|  & \\/~/\\/~/  /~_//             \n" 
		"  &  &&&  \\__|\\| \\__\\_    /~|//___/~\\/ /&& &&        \n" 
		"     &  &    \\  \\     \\_\\| \\/~\\/~|/~   /  &&&&  & &  \n" 
		"                         \\_  /~|/~~/    &&_/_&&&&    \n" 
		"                             \\/~ /_&/__& &&&&&&&& &  \n" 
		"                              //~      &&&&&_&/&&    \n" 
		"               :___________./~~~\\.___________:       \n" 
		"                \\                           /        \n" 
		"                 \\_________________________/         \n" 
		"                 (_)                     (_)         \n";
		std::ofstream file;
		std::string name = this->_target + "_shrubbery";
		file.open(name.c_str());
		file << bush;
		file.close();
		std::cout << GREEN "🌱 Arbusto para " << this->_target << " podado con éxito 🌱\n" NC;
	}
	else
		throw (GradeTooLowException());
}
