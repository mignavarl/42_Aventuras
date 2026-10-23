#include "Array.hpp"
#include <iostream>

//CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
template <typename T>
Array<T>::Array(void)
{
	std::cout << GREEN "Array default constructor called" NC << std::endl;
	this->_array = NULL;
	this->_size = 0;
}

template <typename T>
Array<T>::Array(unsigned int n)
{
	std::cout << GREEN "Array size constructor called" NC << std::endl;
	this->_array = new T[n];	
	this->_size = n;
}
template <typename T>
Array<T>::Array(Array const& other)
{
	std::cout << GREEN "Array copy constructor called" NC << std::endl;
	this->_array = new T[other._size];
	for (unsigned int i = 0; i < other._size; i++)
	{
		this->_array[i] = other._array[i];
	}
	this->_size = other._size;
}

template <typename T>
Array<T>::~Array(void)
{
	std::cout << RED "Array destructor called" NC << std::endl;
	if (this->_size != 0)
		delete[] _array;
}

// OPERATORS--------------------------------------------------------------------
template <typename T>
Array<T>& Array<T>::operator=(Array const& other)
{
	std::cout << "i" << std::endl;
	if (this == &other) {
		return *this;
	}
	delete[] this->_array;
	this->_array = new T[other._size];
	this->_size = other._size;
	for (unsigned int i = 0; i < this->_size; i++)
	{
		this->_array[i] = other._array[i];
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
template <typename T>
unsigned int Array<T>::size(void)
{
	return (this->_size);
}

template <typename T>
int& Array<T>::operator[](int index)
{
	if (index > static_cast<int>(this->size()) || index < 0)
		throw (IndexIncorrectException());
	return _array[index];
}

template <typename T>
int& Array<T>::operator[](int index) const
{
	if (index > static_cast<int>(this->size()) || index < 0)
		throw (IndexIncorrectException());
	return _array[index];
}
