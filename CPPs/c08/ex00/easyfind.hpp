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

// ------------------------------------------

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

class NumberNotFoundException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return (RED"Número no encontrado\033[0m");
			};
	};

#endif