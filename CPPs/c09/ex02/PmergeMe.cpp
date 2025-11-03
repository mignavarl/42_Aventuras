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

void PmergeMe::parse(std::stringstream &arg)
{
	long	num;
	
	while (arg >> num)
	{
		if (num > INT_MAX)
			throw (PMergeException(RED"Error: número muy alto\n\033[0m"));
		if (num < 0)
			throw (PMergeException(RED"Eror: número negativo\n\033[0m"));
		this->_vect.push_back(num);
		this->_list.push_back(num);
	}
}


void PmergeMe::init(std::stringstream &arg)
{
	(void)arg;
	print_num(this->_vect, "Antes: ");
	//Vector
	sort_vector();
	//List
}
