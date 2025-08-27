#include "Alchemy.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Cure::Cure(void) : AMateria("cure")
{
	std::cout << GREEN "Cure default constructor called" NC << std::endl;
	this->_type = "cure";
}

Cure::Cure(Cure const& other) : AMateria("cure")
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

AMateria* Cure::clone(void) const
{
	Cure *aux = new Cure(*this); 
	return (aux);
}