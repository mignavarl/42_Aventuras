#include "PmergeMe.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
PmergeMe::PmergeMe(void)
{
	//std::cout << GREEN "PmergeMe default constructor called" NC << std::endl;
}

PmergeMe::PmergeMe(PmergeMe const& other)
{
	//std::cout << GREEN "PmergeMe copy constructor called" NC << std::endl;
	*this = other;
}

PmergeMe::~PmergeMe(void)
{
	//std::cout << RED "PmergeMe destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
PmergeMe& PmergeMe::operator=(PmergeMe const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
