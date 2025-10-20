#include "easyfind.hpp"
#include <vector>


template <typename T>
void easyfind(T array, int find)
{
	for (size_t i = 0; array[i]; i++)
	{
		if (array[i] == find)
		{
			std::cout << GREEN << find << " encontrado en " << i + 1 << "º posición" NC << std::endl;
			return;
		}
	}
	throw (NumberNotFoundException());
}

int main(void)
{
	int array[] = {1,2,6,12,42,74,9,12,58};
	// std::vector<int> array;
	// for (int i=1; i<=5; i++)
	// 	array.push_back(i);

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
		easyfind(array, 3);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return 0;
}