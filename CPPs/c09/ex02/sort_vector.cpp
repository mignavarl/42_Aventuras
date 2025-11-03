#include "PmergeMe.hpp"

void PmergeMe::make_pairs(std::vector<std::pair<long, long>> &pairs, long &last_odd)
{
	if (this->_vect.size() % 2 != 0)
	{
		last_odd = this->_vect.back();
		this->_vect.pop_back();
	}
	for (size_t i = 0; i < this->_vect.size(); i+=2)
	{
		if (this->_vect[i] > this->_vect[i + 1])
			pairs.push_back(std::pair<long, long>(_vect[i+1], _vect[i]));
		else if (this->_vect[i] < this->_vect[i + 1])
			pairs.push_back(std::pair<long, long>(_vect[i], _vect[i+1]));
	}
}

void PmergeMe::sort_vector(void)
{
	if (this->_vect.size() < 2)
		return;
	
	std::vector<std::pair<long, long>> pair_vec;
	std::vector<long>	result_vec;
	long	last_odd = -1;

	make_pairs(pair_vec, last_odd);
}