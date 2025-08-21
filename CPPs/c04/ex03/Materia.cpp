#include "Materia.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor called" << NC << std::endl;
}

AMateria::AMateria(std::string const & type)
{
	std::cout << GREEN << "AMateira type constructor called" << NC << std::endl;
	this->_type = type;
}

AMateria::AMateria(AMateria const& other)
{
	std::cout << GREEN "AMateria copy constructor called" NC << std::endl;
	this->_type = other._type;
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
AMateria& AMateria::operator=(AMateria const& other)
{
	if (this != &other)
		this->_type = other._type;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
std::string const &AMateria::getType() const
{
	return (this->_type);
}

void AMateria::use(ICharacter& target)
{
	std::cout << "Gatillazo. " << target.getName() << " se ha reído de ti\n";
}