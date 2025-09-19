#include "ScalarConverter.hpp"
#include <iostream>

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
ScalarConverter::ScalarConverter(void)
{
	std::cout << GREEN "ScalarConverter default constructor called" NC << std::endl;
}

ScalarConverter::ScalarConverter(ScalarConverter const& other)
{
	std::cout << GREEN "ScalarConverter copy constructor called" NC << std::endl;
	*this = other;
}

ScalarConverter::~ScalarConverter(void)
{
	std::cout << RED "ScalarConverter destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
ScalarConverter& ScalarConverter::operator=(ScalarConverter const& other)
{
	if (this == &other) {
		return *this;
	}
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------

void ScalarConverter::convert(std::string str)
{
	e_type type = find_type(str);
	switch (type)
	{
	case CHAR:
		print_char(str);
		break;
	case INT:
		print_int(str);
		break;
	case FLOAT:
		print_float(str);
		break;
	case DOUBLE:
		print_double(str);
		break;
	case PSEUDO:
		print_pseudo(str);
		break;
	case NO_TYPE:
		std::cout << RED "No Char\nNo Int\nNo Float\nNo Double\nTipo indefinido\n" NC;
		break;
	}
}