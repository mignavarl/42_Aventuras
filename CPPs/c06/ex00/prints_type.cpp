#include "ScalarConverter.hpp"

void print_char(std::string str)
{
	char c = str[0];
	std::cout << "c = " << c << std::endl;
	if (isprint(c))
		std::cout << "char: '" << str << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl; 
}

void print_int(std::string str)
{
	long n = atol(str.c_str());

	if (str.length() < 4 && isalpha(n))
		std::cout << "char: '" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int: imposible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(n) << std::endl;
	std::cout << "float: " << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(n) << ".0" << std::endl;
}

void print_float(std::string str)
{
	(void)str;
}

void print_double(std::string str)
{
	(void)str;
}

void print_pseudo(std::string str)
{
	if (str == "nan" || str == "nanf")
	{
		std::cout << "char:\timposible\n"
		<< "int:\timposible\n"
		<< "float:\tnanf\n"
		<< "double:\tnan\n"; 
	}
	else if (str == "+inf" || str == "+inff")
	{
		std::cout << "char:\timposible\n"
		<< "int:\timposible\n"
		<< "float:\t+inff\n"
		<< "double:\t+inf\n"; 
	}
	else if (str == "-inf" || str == "-inff")
	{
		std::cout << "char:\timposible\n"
		<< "int:\timposible\n"
		<< "float:\t-inff\n"
		<< "double:\t-inf\n"; 
	}
}

//static_cast<char>