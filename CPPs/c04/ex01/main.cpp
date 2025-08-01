#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *animal[10];
	int i = 0;
	while (i <= 10)
	{
		std::cout << MAGENTA << "---- Creando Animal Nº" << i << " ----\n" NC;
		if (i%2 == 0)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
		i++;
	}
	std::cout << "--------------------------------------------------\n";
	std::cout << "Type Animal 0: " << animal[0]->getType() << std::endl;
	std::cout << "Type Animal 1: " << animal[1]->getType() << std::endl;
	animal[4]->makeSound();
	animal[7]->makeSound();
	std::cout << "Idea 20 = " << animal[0]->getIdea(20) << std::endl;
	animal[0]->setIdea("Patata", 20);
	std::cout << "Idea 20 = " << animal[0]->getIdea(20) << std::endl;
	std::cout << "Idea 20 = " << animal[1]->getIdea(20) << std::endl;
	std::cout << "--------------------------------------------------\n";
	while (i-- > 0)
	{
		std::cout << MAGENTA << "---- Borrando Animal Nº" << i << " ----\n" NC;
		delete(animal[i]);
	}
	return 0;
}