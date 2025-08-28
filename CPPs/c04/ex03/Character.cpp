#include "Alchemy.hpp"

//Character -----------------------------
Character::Character(std::string name)
{
	std::cout << GREEN "Constructor name called" NC << std::endl;
	this->name = name;

}

Character::Character(Character const &other)
{
	std::cout << GREEN "Constructor copy called" NC << std::endl;
	this->name = other.name;
	for (size_t i = 0; inventory[i] && i <= MAX_INV; i++)
	{
		delete this->inventory[i];
	}
	for (size_t i = 0; inventory[i] && i <= MAX_INV; i++)
	{
		if (other.inventory[i] != 0)
		{
			this->inventory[i] = other.inventory[i]->clone();
		}
	}
}

Character::~Character(void)
{
	std::cout << RED "Character destructor called\n   GAME OVER" NC << std::endl;
	for (size_t i = 0; this->inventory[i] && i <= MAX_INV; i++)
	{
		delete this->inventory[i];
	}
	for (size_t i = 0; floor[i] && i <= MAX_FLR; i++)
	{
		delete floor[i];
	}
}

// OPERATORS--------------------------------------------------------

Character& Character::operator=(Character const& other)
{
	if (this != &other)
	{
		this->name = other.name;
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
std::string const &Character::getName() const
{
	return (this->name);
}

void Character::equip(AMateria* m)
{
	int i;

	for (i = 0;inventory[i] && i <= MAX_INV; i++)
		;
	if (i == MAX_INV + 1)
		std::cout << "Inventario lleno\n";
	else
		inventory[i] = m;
}

void Character::unequip(int idx)
{
	if (!this->inventory[idx])
		std::cout << "Index incorrecto\n";
	else
	{
		int i;
		for (i = 0; floor[i] && i <= MAX_FLR; i++)
			;
		floor[i] = inventory[idx]->clone();
		std::cout << "Magia nº" << idx << " desequipado\n";
		delete inventory[idx];
		inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target)
{
	if (!this->inventory[idx])
		std::cout << "Magia agotada. " << target.getName() << " se ha reido de tí\n";
	else
		inventory[idx]->use(target);
}

