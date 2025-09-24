#include "Span.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Span::Span(void)
{
	std::cout << GREEN "Span default constructor called" NC << std::endl;
	this->_size = 0;
	this->_max = 0;
}
Span::Span(unsigned int N)
{
	std::cout << GREEN "Span N constructor called" NC << std::endl;
	this->_size = 0;
	this->_max = N;
}


Span::Span(Span const& other)
{
	std::cout << GREEN "Span copy constructor called" NC << std::endl;
	*this = other;
}

Span::~Span(void)
{
	std::cout << RED "Span destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
Span& Span::operator=(Span const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void Span::addNumber(int num)
{
	if (this->_size == this->_max)
	{
		throw (SpanFullException());
		return ;
	}
	this->_array[this->_size] = num;
	this->_size++;
}

int Span::shortestSpan(void)
{
	if (this->_size < 2)
	{
		throw(SpanEmptyException());
		return (-1);
	}
	
	int min;
	int max;
}

int Span::longestSpan(void)
{
	if (this->_size < 2)
	{
		throw(SpanEmptyException());
		return (-1);
	}

	int small = this->_array[0];
	int big = this->_array[0];
	
	for (unsigned int i = 0; i < this->_max; i++)
	{
		if (this->_array[i] < small)
			small = this->_array[i];
		if (this->_array[i] > big)
			big = this->_array[i];
	}
	return (big - small);
}