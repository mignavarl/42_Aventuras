#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
	BitcoinExchange bit;
	if (ac != 2)
	{
		std::cerr << RED "Error: archivo no encontrado\n" NC; 
		return (1);
	}
	std::ifstream file;
	std::ifstream data_file;
	file.open(av[1]);
	data_file.open("./data.csv");
	if (!file.is_open() || !data_file.is_open())
	{
		std::cerr << RED "Error: archivo corrupto\n" NC;
		return (1);
	}
	bit.extract_data(data_file);
	bit.calc_bitcoin(file);
}