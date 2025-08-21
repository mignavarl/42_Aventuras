#include "Ice.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Ice::Ice(void)
{
	std::cout << GREEN "Ice default constructor called" NC << std::endl;
}

Ice::Ice(Ice const& other) :
{
	std::cout << GREEN "Ice copy constructor called" NC << std::endl;
	*this = other;
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

void Ice::use(ICharacter& target)
{
	std::cout << "Disparas un rayo de hielo a " << target.getName() << std::endl;
}