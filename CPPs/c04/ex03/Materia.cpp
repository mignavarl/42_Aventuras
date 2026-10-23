#include "Alchemy.hpp"

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
	if (this->_type == "ice")
		std::cout << "Disparas un rayo de hielo a " << target.getName() << " 🥶 ¡Qué frío! 🥶" << std::endl;
	else if (this->_type == "cure")
		std::cout << "Curas las heridas de " << target.getName() << std::endl;
	else
		std::cout << "Gatillazo. " << target.getName() << " se ha reído de ti\n";
}

AMateria* AMateria::clone(void)const
{
	return (0);
}