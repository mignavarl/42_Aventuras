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

// RPN declaration --------------------------------------------------------

#ifndef _RPN_HPP
# define _RPN_HPP

# include <iostream>
# include <stack>
# include <cstdlib>
# include <stdio.h>

class RPN {
private:
	std::stack<char> pile;
public:
	RPN(void);
	RPN(RPN const& other);
	~RPN(void);

	RPN& operator=(RPN const& other);
	void put_stack(std::string arg);
	void reverse_polish_notation(void);
	bool calcule(std::stack<int> *buff, char token);
};

#endif // !_RPN_HPP

