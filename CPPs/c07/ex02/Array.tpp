#include "Array.hpp"
#include <iostream>

//CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
template <typename T>
Array<T>::Array(void)
{
	std::cout << GREEN "Array default constructor called" NC << std::endl;
	this->_array = new T[0];
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << GREEN "Array n constructor called" NC << std::endl;
	this->_array = new T[n];	
}
template <typename T>
Array<T>::Array(Array const& other)
{
	std::cout << GREEN "Array copy constructor called" NC << std::endl;
	for (unsigned int i = 0; other._array[i]; i++)
	{
		this->_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << RED "Array destructor called" NC << std::endl;
	delete[] this->_array;
}

// OPERATORS--------------------------------------------------------------------
template <typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
	if (this == &other) {
		return *this;
	}
	for (unsigned int i = 0; other._array[i]; i++)
	{
		this->_array[i] = other._array[i];
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
template <typename T>
unsigned int Array<T>::size(void)
{
	unsigned int i = 0;

	for (; i < static_cast< unsigned int>(this->_array[i]); i++)
		;
	return (i);
}

template <typename T>
int& Array<T>::operator[](int index)
{
	if (index >= static_cast<int>(this->size())) {
		throw ("Index no en rango");
		exit(0);
	}
	return _array[index];
}

template <typename T>
int& Array<T>::operator[](int index) const
{
	if (index >= this->size()) {
		throw ("Index no en rango");
		exit(0);
	}
	return _array[index];
}
