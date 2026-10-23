#include "Ice.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Ice::Ice(void) : AMateria("ice")
{
	std::cout << GREEN "Ice default constructor called" NC << std::endl;
	this->_type = "ice";
}

Ice::Ice(Ice const& other) : AMateria("ice")
{
	std::cout << GREEN "Ice copy constructor called" NC << std::endl;
	this->_type = other._type;
}

Ice::~Ice(void)
{
	std::cout << RED "Ice destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Ice& Ice::operator=(Ice const& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

AMateria* Ice::clone(void) const
{
	Ice *aux = new Ice(*this); 
	return (aux);
}
