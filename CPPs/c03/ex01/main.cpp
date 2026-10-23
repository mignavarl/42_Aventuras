#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap scav("Rodolfo");
	scav.attack("Manolo");
	scav.beRepaired(20);
	scav.guardGate();
	scav.takeDamage(100);

	return 0;
}