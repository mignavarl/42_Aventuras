#include "WrongAnimal.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
WrongAnimal::WrongAnimal(void)
{
	std::cout << GREEN "WrongAnimal default constructor called" NC << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const& other)
{
	std::cout << GREEN "WrongAnimal copy constructor called" NC << std::endl;
	this->type = other.type;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED "WrongAnimal destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
WrongAnimal& WrongAnimal::operator=(WrongAnimal const& other)
{
	if (this != &other)
		this->type = other.type;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

std::string WrongAnimal::getType(void) const
{
	return (this->type);
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "A̸̪̋b̴̬̿s̸̜̽o̷̪̐l̵̹͋ụ̵̏t̶̘̾o̶̳̎ ̸̬̽s̷͎̋i̶̻͑l̵̙̈́ȇ̴̱ñ̵̻c̶̗͊i̸̘͗o̸̖̒\n";
}