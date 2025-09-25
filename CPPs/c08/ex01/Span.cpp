#include "Span.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Span::Span(void)
{
	std::cout << GREEN "Span default constructor called" NC << std::endl;
	this->_max = 0;
	this->_array.reserve(0);
}
Span::Span(unsigned int N)
{
	std::cout << GREEN "Span N constructor called" NC << std::endl;
	this->_max = N;
	this->_array.reserve(N);
}

Span::Span(Span const& other)
{
	std::cout << GREEN "Span copy constructor called" NC << std::endl;
	this->_array = other._array;
	this->_max = other._max;
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
	this->_array = other._array;
	this->_max = other._max;
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void Span::addNumber(int num)
{
	if (this->_array.size() == this->_max)
	{
		throw (SpanFullException());
		return ;
	}
	this->_array.push_back(num);
}

int Span::shortestSpan(void)
{
	if (this->_array.size() < 2)
		throw(SpanEmptyException());
	
	int first;
	int second;
	int res;
	int final_res;

	std::vector<int> copy(this->_array);
	std::sort(copy.begin(), copy.end());
	final_res = copy.at(1) - copy.at(0);
	//std::cout << " final_res = " << final_res << std::endl;
	for (size_t i = 0; i < this->_array.size() - 1; i++)
	{
		first = copy.at(i);
		second = copy.at(i + 1);
		res = second - first;
		if (res < final_res)
		{
			final_res = res;
			//std::cout << i << " -- final_res(" << second << " - " << first << ")= " << final_res << std::endl;
		}
	}
	return (final_res);
}

int Span::longestSpan(void)
{
	if (this->_array.size() < 2)
		throw(SpanEmptyException());

	int small;
	int big;
	
	std::vector<int> copy(this->_array);
	std::sort(copy.rbegin(), copy.rend());
	big = *copy.begin();
	std::sort(copy.begin(), copy.end());
	small = *copy.begin();
	return (big - small);
}