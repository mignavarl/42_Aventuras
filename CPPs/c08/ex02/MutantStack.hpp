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

// MutantStack declaration --------------------------------------------------------

#ifndef _MUTANTSTACK_HPP
# define _MUTANTSTACK_HPP

# include <iostream>
# include <stack>

template <typename T>
class MutantStack
{
	private:
		T *_stack;
	public:
		MutantStack(void);
		MutantStack(MutantStack const& other);
		~MutantStack(void);
	
		MutantStack& operator=(MutantStack const& other);

		size_t	size(void);
		bool	empty(void);
		MutantStack<int> &top(void);
		void	push(int n);
		void	pop(void);
		MutantStack<int> begin(void);
		MutantStack<int> end(void);
};
std::ostream &operator<<(std::ostream &o, const MutantStack<int> &ms);
# include "MutantStack.tpp"

#endif // !_MUTANTSTACK_HPP
