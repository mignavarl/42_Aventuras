#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat("Miguel", 151);
		
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}