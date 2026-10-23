#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal *cat = new Cat();
	Animal *dog = new Dog();
	//Animal *a = new Animal();

	std::cout << "--------------------------------------------------\n";
	std::cout << "Type Animal 0: " << dog->getType() << std::endl;
	std::cout << "Type Animal 1: " << cat->getType() << std::endl;
	dog->makeSound();
	cat->makeSound();
	std::cout << "Idea 20 = " << dog->getIdea(20) << std::endl;
	dog->setIdea("Patata", 20);
	std::cout << "Idea 20 = " << dog->getIdea(20) << std::endl;
	std::cout << "Idea 20 = " << cat->getIdea(20) << std::endl;
	std::cout << "--------------------------------------------------\n";
	delete(dog);
	delete(cat);
	return 0;
}