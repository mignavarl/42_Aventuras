#include "Span.hpp"

int main(void)//TODO:final ex01
{
	Span sp = Span(5);
	try
	{
		sp.addNumber(6);
		sp.addNumber(5);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(42);
		// srand(time(0));
		// for (size_t i = 0; i < 10000; i++)
		// {
		// 	int r = rand() % 10000;
		// 	sp.addNumber(r);
		// }
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}