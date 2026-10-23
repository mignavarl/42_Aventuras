#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat paco("Paco", 50);
		paco.increment_grade();
		std::cout << paco << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------\n";
	try
	{
		Bureaucrat paca("Paca", 0);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << "---------------------\n";
	try
	{
		Bureaucrat regildo("Regildo", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "---------------------\n";
	try
	{
		Bureaucrat aitor("Aitor", 150);
		aitor.decrement_grade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}