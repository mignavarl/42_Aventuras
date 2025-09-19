#include "Serializer.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Serializer::Serializer(void)
{
	std::cout << GREEN "Serializer default constructor called" NC << std::endl;
}

Serializer::Serializer(Serializer const& other)
{
	std::cout << GREEN "Serializer copy constructor called" NC << std::endl;
	*this = other;
}

Serializer::~Serializer(void)
{
	std::cout << RED "Serializer destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Serializer& Serializer::operator=(Serializer const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
uintptr_t Serializer::serialize(Data* ptr)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
	return (raw);
}

Data* Serializer::deserialize(uintptr_t raw)
{
	Data* ptr = reinterpret_cast<Data *>(raw);
	return (ptr);
}