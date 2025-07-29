#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dia("Kriptonio");

	dia.getDiam_stats();
	std::cout << std::endl;
	dia.attack("Clark");
	std::cout << std::endl;
	dia.beRepaired(20);
	std::cout << std::endl;
	dia.whoAmI();
	std::cout << std::endl;
	dia.getDiam_stats();
}