#include "WrongCat.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
WrongCat::WrongCat(void) : WrongAnimal()
{
	std::cout << GREEN "WrongCat default constructor called" NC << std::endl;
	this->type = "W̵̟̼̱̽̉̉ṟ̶̖̽ò̶͚n̸̙̒̆͝g̴͎̃C̶̛͖a̵̲̹̾̈́̒t̶̪̦͂̚";
}

WrongCat::WrongCat(WrongCat const& other) : WrongAnimal()
{
	std::cout << GREEN "WrongCat copy constructor called" NC << std::endl;
	*this = other;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED "WrongCat destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
WrongCat& WrongCat::operator=(WrongCat const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void WrongCat::makeSound(void) const
{
	std::cout << this->type << " maulla: \"N̴̛͕͍̊͗̈́̈̂ỳ̶͇̤͖͍̹̖ą̴̓͌̾̂̔̀͠\" 🐱\n";
}