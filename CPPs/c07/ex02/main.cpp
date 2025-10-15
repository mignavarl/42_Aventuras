#include "Array.hpp"

#define MAX_VAL 750
int main(void)
{
    Array<int> numbers(MAX_VAL);

    srand(time(NULL));

    for (int i = 0; i < MAX_VAL; i++)
    {
		const int value = rand();
        numbers[i] = value;
    }
    
	Array<int> tmp = numbers;
    Array<int> test(tmp);

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (numbers[i] != tmp[i] || numbers[i] != test[i] )
        {
            std::cerr << RED "Guardado valores diferentes" NC << std::endl;
            return 1;
        }
    }

    try
    {
		numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
		std::cerr << RED << e.what() << NC << std::endl;
    }

    try
    {
		tmp[55] = 55;
    }
    catch(const std::exception& e)
    {
		std::cerr << e.what() << '\n';
    }

	std::cout << "Numbers array[55] = " << numbers[55] << std::endl;
	std::cout << "Tmp     array[55] = " << tmp[55] << std::endl;
	std::cout << "Test    array[55] = " << test[55] << std::endl;

    for (int i = 0; i < MAX_VAL; i++)
    {
		numbers[i] = rand();
    }
    return 0;
}