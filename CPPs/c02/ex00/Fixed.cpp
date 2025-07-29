#include "Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Fixed::Fixed(void)
{
	std::cout << GREEN "Fixed default constructor called" NC << std::endl;
	this->value = 0;
}

Fixed::Fixed(Fixed const& other)
{
	std::cout << GREEN "Fixed copy constructor called" NC << std::endl;
	this->value = other.value;
}

Fixed::~Fixed(void)
{
	std::cout << RED "Fixed destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Fixed& Fixed::operator=(Fixed const& other)
{
	if (this == &other) {
		return *this;
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
int Fixed::getRawBits(void) const
{
	return (this->value);
}
void Fixed::setRawBits(int const raw)
{
	this->value = raw;
}