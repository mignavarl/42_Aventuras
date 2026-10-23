#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	book;
	std::string	command;
	int			cont;

	std::cout << "📒 Bienvenido a su agenda telefónica 📒\n";
	sleep(1);
	std::cout << "Cargando... ⏳\n";
	sleep(3);
	cont = 1;
	while (1)
	{
		std::cout << GREEN << "Introduzca comando (ADD, SEARCH, EXIT):" << NC << std::endl;
		std::getline(std::cin, command);
		if (command == "EXIT" || command == "exit" || std::cin.eof())
		{
			std::cout << "Saliendo... 👋" << std::endl;
			break;
		}
		else if (command == "ADD" || command == "add")
		{
			if (book.add_person(book.getContact(cont)))
				cont++;
		}
		else if (command == "SEARCH" || command == "search")
			book.search_people(book);
		else if (command.length())
			std::cout << RED << "❌ Comando no válido ❌" << NC << std::endl;
		if (cont == MAX_CONTACTS)
		{
			cont = 1;
			std::cout << "🔔 Final de la agenda 🔔\n\nSi añade un nuevo contacto se\neliminarán los más antiguos" << std::endl;
		}
		command = "\0";
	}
	return (0);
}
