#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	const WrongAnimal* w = new WrongAnimal();
	const WrongAnimal* notcat = new WrongCat();
	std::cout << "Type: " << i->getType() << " " << std::endl;
	std::cout << "Type: " << j->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	w->makeSound();
	std::cout << "Type: " << notcat->getType() << std::endl;
	notcat->makeSound();



	delete(i);
	delete(j);
	delete(meta);
	delete(notcat);
	delete(w);
	return 0;
}