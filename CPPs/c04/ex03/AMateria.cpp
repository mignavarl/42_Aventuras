#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor" << NC << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << GREEN << "AMateira type constructor" << NC << std::endl;
	this->_type = type;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor" << NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
AMateria& AMateria::operator=(AMateria const& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
