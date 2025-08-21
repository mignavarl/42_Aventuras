#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap dia("Kriptonio");

	dia.attack("Clark");
	std::cout << std::endl;
	dia.beRepaired(20);
	std::cout << std::endl;
	dia.whoAmI();
	std::cout << std::endl;
	return 0;
}