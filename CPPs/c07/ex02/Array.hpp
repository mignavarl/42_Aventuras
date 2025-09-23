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

// Array declaration --------------------------------------------------------

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
class Array 
{
	private:
		T *_array;
	public:
		Array(void);
		Array(unsigned int n);
		Array(Array const& other);
		~Array(void);
		
		Array& operator=(Array const& other);
		unsigned int size(void);
		int& operator[](int index);
		int& operator[](int index) const;
};
#include "Array.tpp"


#endif // !_ARRAY_HPP
