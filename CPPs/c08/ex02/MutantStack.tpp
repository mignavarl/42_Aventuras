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

std::ostream &operator<<(std::ostream &o, const MutantStack<int> &ms)
{
	o << ms << std::endl;
	return (o);
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
template <typename T>
size_t	MutantStack<T>::size(void)
{
	size_t i = 0;
	for (; i < this->_stack[i]; i++)
		;
	return (i);
}

template <typename T>
bool	MutantStack<T>::empty(void)
{
	if (this->size() == 0)
		return (true);
	return (false);
}

template <typename T>
MutantStack<int> &MutantStack<T>::top(void)
{
	size_t i = this->size() + 1;

	MutantStack<int> r = &this->_stack[i];
	return (r);
}

template <typename T>
void	MutantStack<T>::push(int n)
{
	size_t i = this->size();

	this->_stack[i] = n;
}

template <typename T>
void	MutantStack<T>::pop(void)
{
	size_t i = this->size() + 1;

	this->_stack[i] = NULL;
}

template <typename T>
MutantStack<int> MutantStack<T>::begin(void)
{

}

template <typename T>
MutantStack<int> MutantStack<T>::end(void)
{

}
