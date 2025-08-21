#include "Cure.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Cure::Cure(void)
{
	std::cout << GREEN "Cure default constructor called" NC << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const& other)
{
	std::cout << GREEN "Cure copy constructor called" NC << std::endl;
	this->_type = other._type;
}

Cure::~Cure(void)
{
	std::cout << RED "Cure destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Cure& Cure::operator=(Cure const& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void Cure::use(ICharacter& target)
{
	std::cout << "Disparas un rayo de hielo a " << target.getName() << std::endl;
}