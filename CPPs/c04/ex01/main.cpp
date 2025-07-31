#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animal[10];
	int i = 0;
	while (i < 10)
	{
		if (i%2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		i++;
	}

	animal[0]->getType();
	animal[1]->getType();
	animal[4]->makeSound();
	animal[7]->makeSound();
	i--;
	while (i >= 0)
	{
		delete(animal[i]);
		i--;
	}
	return 0;
}