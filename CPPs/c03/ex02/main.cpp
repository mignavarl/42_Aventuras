#include "FragTrap.hpp"

int main(void)
{
	FragTrap frag("Fragcisco");

	frag.attack("Manolo");
	frag.beRepaired(20);
	frag.highFivesGuys();
	frag.takeDamage(100);
	return (0);
}