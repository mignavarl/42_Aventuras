#include "RPN.hpp"

bool check_arg(char *av)
{
	for (size_t i = 0; av[i]; i++)
	{
		if (!isdigit(av[i]) && av[i] != '+' && av[i] != '-' &&
			 av[i] != '*' && av[i] != '/' && av[i] != ' ')
		{
			std::cout << RED "Error: Carácteres raros encontrados\n" NC;
			return (false);
		}
	}
	bool space = true;
	for (size_t i = 0; av[i]; i++)
	{
		if (av[i] == ' ' && space == false)
			space = true;
		else if (av[i] != ' ' && space == true)
			space = false;
		else
		{
			std::cout << RED "Error: Dos carácteres seguidos\n" NC;
			return (false);
		}
	}
	return (true);
}

int main(int ac, char **av)
{
	RPN stack;
	if (ac != 2)
	{
		std::cout << RED "Error: Argumentos mal\n" NC;
		return (1); 
	}
	std::string arg = av[1];
	if (!check_arg(av[1]))
		return (1);
	stack.put_stack(arg);
	stack.reverse_polish_notation();
}