#include "Span.hpp"

int main(void)
{
	std::cout << GREEN "------------ TEST ADDNUMBER ----------------\n" NC;
	Span sp1 = Span(5);
	try
	{
		sp1.addNumber(6);
		sp1.addNumber(5);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.addNumber(42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp1.shortestSpan() << std::endl;
		std::cout << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//---------------------------------------------------------------------------------------------------------------------
	std::cout << GREEN "------------ TEST RANDOM NUMBERS ----------------\n" NC;
	Span sp2 = Span(10000);
	try
	{
		srand(time(0));
		for (size_t i = 0; i < 10000; i++)
		{
				int r = rand() % 500000;
				sp2.addNumber(r);
		}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp2.shortestSpan() << std::endl;
		std::cout << sp2.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	//---------------------------------------------------------------------------------------------------------------------
	std::cout << GREEN "------------ TEST RANGE ITERATORS ----------------\n" NC;
	Span sp3 = Span(5);
	try
	{
		sp3.addNumber(1, 100);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << sp3.shortestSpan() << std::endl;
		std::cout << sp3.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}