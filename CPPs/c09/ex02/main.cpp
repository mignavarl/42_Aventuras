#include "PmergeMe.hpp"

int main(int ac, char **av)
{
	if (ac == 1)
	{
		std::cout << RED "Pon argumentos\n" NC;
		return (1);
	}
	
	try
	{
		PmergeMe	algo;
		std::stringstream arg;

		for (size_t i = 1; av[i]; i++)
			arg <<  av[i] << " ";
		algo.parse(arg);
		algo.init(arg);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
}