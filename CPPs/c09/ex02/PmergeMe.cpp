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
		if (std::find(_vect.begin(), _vect.end(), num) != _vect.end())
			throw (PMergeException(RED"Eror: número repetido\n\033[0m"));
		this->_vect.push_back(num);
		this->_dequ.push_back(num);
	}
}

std::vector<size_t> jacob_seq(size_t n)
{
	std::vector<size_t> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < n)
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	return seq;
}



void PmergeMe::sort_vector(std::vector<long> &vector)
{
	if (vector.size() <= 1)
		return ;
	
	std::vector<long> small;
	std::vector<long> big;

	for (size_t i = 0; i < vector.size(); i += 2)
	{
		long a = vector[i];
		long b = vector [i + 1];

		if (a < b)
		{
			small.push_back(a);
			big.push_back(b);
		}
		else if (a > b)
		{
			small.push_back(b);
			big.push_back(a);
		}
	}
	if (vector.size() % 2 != 0)
		big.push_back(vector.back());
	sort_vector(big);

	std::vector<size_t> jacob = jacob_seq(small.size());
    std::vector<size_t> order;
    size_t prev = 0;

    for (size_t i = 1; i < jacob.size(); ++i)
    {
        size_t limit = std::min(jacob[i], small.size());
        for (size_t j = limit; j > prev; --j)
            order.push_back(j - 1);
        prev = limit;
        if (limit == small.size())
            break;
    }

	for (size_t i = 0; i < small.size(); i++)
	{
		long val = small[order[i]];
		std::vector<long>::iterator it = std::lower_bound(big.begin(), big.end(), val);

		big.insert(it, val);
	}
	
	vector = big;
}

void PmergeMe::init(std::stringstream &arg)
{
	(void)arg;
	print_num(this->_vect, "Antes: ");
	//Vector
	sort_vector(_vect);
	//List
}
