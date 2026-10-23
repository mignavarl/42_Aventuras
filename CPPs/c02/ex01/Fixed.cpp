#include "Fixed.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Fixed::Fixed(void)
{
	std::cout << GREEN "Fixed default constructor called" NC << std::endl;
	this->value = 0;
}

Fixed::Fixed(const int nbr)
{
	std::cout << GREEN "Fixed int constructor called" NC << std::endl;
	this->value = nbr << this->bits;
}

Fixed::Fixed(const float nbr)
{
	std::cout << GREEN "Fixed float constructor called" NC << std::endl;
	this->value = roundf(nbr * (1 << this->bits));
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
	if (this != &other) 
		this->value = other.getRawBits();
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

float	Fixed::toFloat(void) const
{
	return ((float)this->value / (float)(1 << this->bits));
}

int		Fixed::toInt(void) const
{
	return (this->value >> this->bits);
}

std::ostream &operator<<(std::ostream &nbr, Fixed const &fixed)
{
	nbr << fixed.toFloat();
	return (nbr);
}
