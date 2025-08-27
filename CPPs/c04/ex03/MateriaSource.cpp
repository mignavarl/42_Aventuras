#include "Alchemy.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
MateriaSource::MateriaSource(void)
{
	std::cout << GREEN "MateriaSource default constructor called" NC << std::endl;
}

MateriaSource::MateriaSource(MateriaSource const& other)
{
	std::cout << GREEN "MateriaSource copy constructor called" NC << std::endl;
	*this = other;
}

MateriaSource::~MateriaSource(void)
{
	std::cout << RED "MateriaSource destructor called" NC << std::endl;
	for (size_t i = 0; list[i] && i <= MAX_SRC; i++)
		delete list[i];	
}

// OPERATORS--------------------------------------------------------------------
MateriaSource& MateriaSource::operator=(MateriaSource const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void	MateriaSource::learnMateria(AMateria* m)
{
	int i;
	for (i = 0; list[i] && i <= MAX_SRC; i++)
		;
	if (i == MAX_SRC + 1)
		std::cout << "Magia al completo\n";
	else
	{
		AMateria* copy(m);
		this->list[i] = copy;
	}
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
	int i = 0;
	for (;list[i] && i <= MAX_SRC; i++)
		;
	if (i == 0)
		return (0);
	if (i == MAX_SRC)
	{
		std::cout << "Lista de creación llena\n";
		return (0);
	}
	i--;
	if (type == "ice")
	{
		AMateria *ice = new Ice();
		return (ice);
	}
	else if (type == "cure")
	{
		AMateria *cure = new Cure();
		return(cure);
	}
	else
	{
		std::cout << "Magia no encontrada\n";
		return (0);
	}
}
