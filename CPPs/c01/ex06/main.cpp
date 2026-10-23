#include "Harl.hpp"

int main(int ac, char **av)
{
	std::string level;
	Harl harl;

	if (ac != 2)
		return (0);
	level = av[1];
	harl.complain(level);
}