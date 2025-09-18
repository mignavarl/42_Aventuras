#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << RED "Número de argumentos incorrecto\n" NC;
		return 1;
	}
	std::string av;
	for (size_t i = 0; argv[1][i]; i++)
	{
		av = av + argv[1][i];
	}
	ScalarConverter::convert(av);
}