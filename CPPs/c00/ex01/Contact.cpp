#include "Contact.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
Contact::Contact(/* args */)
{
}

Contact::~Contact()
{
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

bool Contact::check_stat(Contact *person)
{
	if (!person->get_first(person).length())
		return (false);
	if (!person->get_last(person).length())
		return (false);
	if (!person->get_nick(person).length())
		return (false);
	if (!person->get_phone(person).length())
		return (false);
	if (!person->get_secret(person).length())
		return (false);
	return (true);
}

void	Contact::put_first(std::string com, Contact *person)
{
	person->first_name = com;
}
void	Contact::put_last(std::string com, Contact *person)
{
	person->last_name = com;
}
void	Contact::put_nick(std::string com, Contact *person)
{
	person->nickname = com;
}
void	Contact::put_phone(std::string com, Contact *person)
{
	person->phone_number = com;
}

void	Contact::put_secret(std::string com, Contact *person)
{
	person->secret = com;
}
std::string	Contact::get_first(Contact *person)
{
	return(person->first_name);
}
std::string	Contact::get_last(Contact *person)
{
	return(person->last_name);
}
std::string	Contact::get_nick(Contact *person)
{
	return (person->nickname);
}
std::string	Contact::get_phone(Contact *person)
{
	return(person->phone_number);
}

std::string Contact::get_secret(Contact *person)
{
	return (person->secret);
}