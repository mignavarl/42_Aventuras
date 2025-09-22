#include "Array.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
template <typename T>
Array<T>::Array(void)
{
	std::cout << GREEN "Array default constructor called" NC << std::endl;
	this->_array = new T;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << GREEN "Array n constructor called" NC << std::endl;
	for (size_t i = 0; i < n; i++)
	{
		this->_array[i] = new T;
	}	
}

template <typename T>
Array<T>::Array(Array const& other)
{
	std::cout << GREEN "Array copy constructor called" NC << std::endl;
	*this = other;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << RED "Array destructor called" NC << std::endl;
	for (size_t i = 0; this->_array[i]; i++)
	{
		delete this->_array[i];
	}
	
}

// OPERATORS--------------------------------------------------------------------
template <typename T>
Array& Array<T>::operator=(Array const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
