#ifndef _COLORS
# define _COLORS

# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
# define NC      "\033[0m"

#endif // !_COLORS

// PmergeMe declaration --------------------------------------------------------

#ifndef _PMERGEME_HPP
# define _PMERGEME_HPP

# include <string>
# include <vector>
# include <list>
# include <cstdlib>
# include <sstream>
# include <iostream>
# include <algorithm>
# include <climits>


template <typename T>
void print_num(T const &num, std::string text)
{
	typename T::const_iterator it;
	
	it = num.begin();
	std::cout << text;
	for (size_t i = 0; i < 6 && it != num.end(); i++)
	{
		std::cout << *it << " ";
		it++;
		if (i == 5)
		{
			std::cout << "[...]" << std::endl;
			return ;
		}
	}
	std::cout << std::endl;
}

class PmergeMe 
{
	private:
		std::vector<long> _vect;
		std::list<long> _list;
	public:
		PmergeMe(void);
		PmergeMe(PmergeMe const& other);
		~PmergeMe(void);

		PmergeMe& operator=(PmergeMe const& other);

		void parse(std::stringstream &arg);
		void init(std::stringstream &arg);
		//VECTOR
		void sort_vector();
		void PmergeMe::make_pairs(std::vector<std::pair<long, long>> &pairs, long &last_odd);

	class PMergeException : public std::exception
	{
		private:
			const char *_msg;
		public:
			PMergeException(const char *msg): _msg(msg){};
			const char*  what() const throw()
			{
				return (_msg);
			};
	};
};

#endif // !_PMERGEME_HPP

