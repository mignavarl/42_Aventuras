/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mignavar <mignavar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 16:16:44 by mignavar          #+#    #+#             */
/*   Updated: 2025/08/07 11:42:50 by mignavar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(/* args */)
{
}

PhoneBook::~PhoneBook()
{
}

Contact *PhoneBook::getContact(int cont)
{
	return(&this->people[cont]);
}

bool	check_word(std::string word)
{
	if (!word.length())
		return (false);
	return (true);
}


bool	PhoneBook::add_person(Contact *person)
{
	std::string com;

	std::cout << "Introduce nombre:\n";
	std::getline(std::cin, com);
	person->put_first(com, person);
	std::cout << "Introduce apellidos:\n";
	std::getline(std::cin, com);
	person->put_last(com, person);
	std::cout << "Introduce apodo:\n";
	std::getline(std::cin, com);
	person->put_nick(com, person);
	std::cout << "Introduce número de teléfono:\n";
	std::getline(std::cin, com);
	person->put_phone(com, person);
	std::cout << "Introduce un oscuro secreto:\n";
	std::getline(std::cin, com);
	person->put_secret(com, person);
	if (!person->check_stat(person))
	{
		std::cout << "Se ha detectado un campo vacío\nEl contacto no se ha guardado\n";
		person->put_first("\0", person);
		person->put_last("\0", person);
		person->put_nick("\0", person);
		person->put_phone("\0", person);
		person->put_secret("\0", person);
		return (false);
	}
	std::cout << "Contacto guardado correctamente 👌\n";
	return (true);
}

void	PhoneBook::print_name(std::string name, bool final)
{
	int c;

	c = 0;
	if (name.length() > 10)
	{
		while (c < 9)
		{
			std::cout << name[c];
			c++;
		}
		if (!final)
			std::cout << "." << MAGENTA << "│" << NC;
		else
			std::cout << "." << MAGENTA << "║\n" << NC;
		return;
	}
	if (!final)
		std::cout << std::setw(10) << std::right << name << MAGENTA << ".│" << NC;
	else
		std::cout << std::setw(10) << std::right << name << MAGENTA << "║\n" << NC;
}

void	PhoneBook::search_people(PhoneBook book)
{
	int i;

	i = 1;
	while (i <= MAX_CONTACTS)
	{
		if (i == MAX_CONTACTS || !check_word(book.people[i].get_first(&book.people[i])))
		{
			if (i != 1 || i == MAX_CONTACTS)
				std::cout << MAGENTA << "╚══════════╧══════════╧══════════╧══════════╝\n" << NC;
			else
			{
				std::cout << "No hay contactos guardados\n";
				return;
			}
			break;
		}
		if (i == 1)
			std::cout << MAGENTA << "╔══════════╤══════════╤══════════╤══════════╗\n" << NC;
		std::cout << MAGENTA << "║" << NC << std::setw(10) << std::right << i << MAGENTA << "│" << NC;
		print_name(book.people[i].get_first(&book.people[i]), false);
		print_name(book.people[i].get_last(&book.people[i]), false);
		print_name(book.people[i].get_nick(&book.people[i]), true);
		std::cout << MAGENTA << "╠══════════╪══════════╪══════════╪══════════╣\n" << NC;
		i++;
	}
	std::string line;
	int			c;
	while (1)
	{
		c = 0;
		line = "\0";
		std::cout << "Introduce número del contacto que quieras ver (1 ~ " << i - 1 << "): \n";
		std::getline(std::cin, line);
		c = atoi(line.c_str());
		if (c <= 0 || c >= i || line.length() > 1)
		{
			std::cout << RED << "Número no válido\nVolviendo al inicio\n" << NC;
			sleep(1);
			return;
		}
		else
		{
			if (!book.people[c].get_first(&book.people[c]).length())
				std::cout << RED << "Contacto no encontrado\n\n" << NC;
			else
			{	
				std::cout << "\n"
				          << "Nombre:......" << book.people[c].get_first(&book.people[c])	<< std::endl
				          << "Apellido:...." << book.people[c].get_last(&book.people[c])	<< std::endl
				          << "Apodo:......." << book.people[c].get_nick(&book.people[c])	<< std::endl
				          << "Teléfono:...." << book.people[c].get_phone(&book.people[c])	<< std::endl
				          << "Secreto:....." << book.people[c].get_secret(&book.people[c])	<< std::endl;
				return;
			}
		}
	}
}