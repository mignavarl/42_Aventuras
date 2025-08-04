#include "Harl.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Harl::Harl(void)
{
	std::cout << "Harl savaje ha aparecido\n";
}

Harl::~Harl(void)
{
	std::cout << "Harl salvaje ha huido\n";
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void Harl::debug(void)
{
	std::cout << GREEN << "Me encanta tener bacon extra para mi hamburguesa 7XL con doble queso, triple pepinillo y kétchup especial. ¡De verdad!\n" << NC;
}
void Harl::info(void)
{
	std::cout << MAGENTA << "No puedo creer que añadir más bacon cueste más dinero.\n¡No le pusiste suficiente bacon a mi hamburguesa! Si lo hubieras hecho, ¡no pediría más!\n" << NC;
}
void Harl::warning(void)
{
	std::cout << BLUE << "Creo que merezco un poco de bacon extra gratis.\nLlevo viniendo años, mientras que tú empezaste a trabajar aquí el mes pasado.\n" << NC;
}
void Harl::error(void)
{
	std::cout << YELLOW << "🍋¡ESTO ES INACEPTABLE!🍋 Quiero hablar con el gerente ahora.\n" << NC;
}

void Harl::complain(std::string level)
{
	std::string	lvl[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void	(Harl::*f[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	int		i = 0;
	
	while (i < 4)
	{
		if (lvl[i] == level)
		{
			(this->*f[i])();
			return ;
		}
		i++;
	}
	if (i == 4)
		std::cout << RED << level << " : not found\n" << NC;
}