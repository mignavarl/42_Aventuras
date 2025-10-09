#include "MutantStack.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
template <typename T>
MutantStack<T>::MutantStack(void)
{
	std::cout << GREEN "MutantStack default constructor called" NC << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const& other)
{
	std::cout << GREEN "MutantStack copy constructor called" NC << std::endl;
	*this = other;
}

template <typename T>
MutantStack<T>::~MutantStack(void)
{
	std::cout << RED "MutantStack destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
template <typename T>
MutantStack<T>& MutantStack<T>::operator=(MutantStack const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
