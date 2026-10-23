#include "ClapTrap.hpp"

int main ()
{
	ClapTrap clap("Rodolfo");

	clap.attack("Paco");
	clap.takeDamage(9);
	clap.beRepaired(3);
	clap.takeDamage(6);
	clap.beRepaired(4);
	clap.attack("Manolo");
	return(0);
}