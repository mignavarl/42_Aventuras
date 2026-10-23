#include "easyfind.hpp"

int main(void)
{
	std::vector<int> array;
	srand(time(0));
	for (size_t i = 0; i < 10; i++)
	{
		int r = rand() % 40;
		array.push_back(r);
	}

	int n = array.at(4);
	array.push_back(50);

	try
	{
		easyfind(array, 42);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(array, n);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		easyfind(array, 50);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}