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
			throw (PMergeException(RED"Error: número muy alto\033[0m"));
		if (num < 0)
			throw (PMergeException(RED"Eror: número negativo\033[0m"));
		if (std::find(_vect.begin(), _vect.end(), num) != _vect.end())
			throw (PMergeException(RED"Eror: número repetido\033[0m"));
		this->_vect.push_back(num);
		this->_dequ.push_back(num);
	}
}

// JACOB --------------------------------------------------------------------------
std::vector<size_t> jacob_seq_vec(size_t n)
{
	std::vector<size_t> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < n)
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	return seq;
}

std::deque<size_t> jacob_seq_deq(size_t n)
{
	std::deque<size_t> seq;
	seq.push_back(0);
	seq.push_back(1);
	while (seq.back() < n)
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);
	return seq;
}

// SORTS --------------------------------------------------------------------------
void PmergeMe::sort_deque(std::deque<long> &deque)
{
	if (deque.size() <= 1)
		return ;

	std::deque<long> small;
	std::deque<long> big;

	for (size_t i = 0; i < deque.size() - 1; i+=2)
	{
		long a = deque[i];
		long b = deque[i + 1];

		if (a < b)
		{
			small.push_back(a);
			big.push_back(b);
		}
		else
		{
			small.push_back(b);
			big.push_back(a);
		}
	}
	if (deque.size() % 2 != 0)
		big.push_back(deque.back());
	sort_deque(big);

	std::deque<size_t> jacob = jacob_seq_deq(small.size());
	std::deque<size_t> order;
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
		std::deque<long>::iterator it = std::lower_bound(big.begin(), big.end(), val);
		big.insert(it, val);
	}
	
	deque = big;
}

void PmergeMe::sort_vector(std::vector<long> &vector)
{
	if (vector.size() <= 1)
		return ;
	
	std::vector<long> small;
	std::vector<long> big;

	for (size_t i = 0; i < vector.size() - 1; i += 2)
	{
		long a = vector[i];
		long b = vector [i + 1];

		if (a < b)
		{
			small.push_back(a);
			big.push_back(b);
		}
		else
		{
			small.push_back(b);
			big.push_back(a);
		}
	}
	if (vector.size() % 2 != 0)
		big.push_back(vector.back());
	sort_vector(big);

	std::vector<size_t> jacob = jacob_seq_vec(small.size());
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

void PmergeMe::init(void)
{
	double time;
	clock_t init;
	clock_t	end;
	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;
	print_num(_vect, "Vector Antes: ");
	std::cout << MAGENTA"------------------------------------------------------------" << NC << std::endl;
	print_num(_dequ, "Deque  Antes: ");
	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;
	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;

	//Vector
	init = clock();
	sort_vector(_vect);
	end = clock();
	time = 1000 * static_cast<double>(end - init)/ CLOCKS_PER_SEC;
	std::cout << std::endl << CYAN << "Tiempo en ordenar un vector de " << _vect.size() << " : " << time << NC << std::endl;
 	
	//Deque
	init = clock();
	sort_deque(_dequ);
	end = clock();
	time = 1000 * static_cast<double>(end - init)/ CLOCKS_PER_SEC;
	std::cout << CYAN << "Tiempo en ordenar una lista de " << _vect.size() << " : " << time << NC << std::endl << std::endl;

	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;
	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;
	print_num(_vect, "Vector Después: ");
	std::cout << MAGENTA"------------------------------------------------------------" << NC << std::endl;
	print_num(_dequ, "Deque  Después: ");
	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;
	std::cout << YELLOW"------------------------------------------------------------" << NC << std::endl;
}
