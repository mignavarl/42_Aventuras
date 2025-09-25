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

// Span declaration --------------------------------------------------------

#ifndef _SPAN_HPP
# define _SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>

class Span 
{
	private:
		std::vector<int> _array;
		unsigned int _max;
	public:
		Span(void);
		Span(unsigned int N);
		Span(Span const& other);
		~Span(void);

		Span& operator=(Span const& other);
		void addNumber(int num);
		int shortestSpan(void);
		int longestSpan(void);

	class SpanFullException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return (RED"Span lleno\033[0m");
			};
	};
	class SpanEmptyException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return (RED"Span vacío o con un número\033[0m");
			};
	};
};

#endif // !_SPAN_HPP

