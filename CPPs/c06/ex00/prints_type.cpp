#include "ScalarConverter.hpp"

void print_char(std::string str)
{
	char c = str[0];
	if (isprint(c))
		std::cout << "char:\t'" << str << "'" << std::endl;
	else
		std::cout << "char:\tNo mostrable" << std::endl;
	
	std::cout << "int:\t" << static_cast<int>(c) << std::endl;
	std::cout << "float:\t" << static_cast<float>(c) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(c) << ".0" << std::endl; 
}

void print_int(std::string str)
{
	long double n = atol(str.c_str());

	if (str.length() < 4 && isprint(n))
		std::cout << "char:\t'" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char:\tNo mostrable" << std::endl;
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int:\timposible" << std::endl;
	else
		std::cout << "int:\t" << static_cast<int>(n) << std::endl;
	std::cout << "float:\t" << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(n) << ".0" << std::endl;
}

void print_float(std::string str)
{
	long double n = atof(str.c_str());

	if (str.length() < 7 && isprint(n))
		std::cout << "char:\t'" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char:\tNo mostrable" << std::endl;
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int:\timposible" << std::endl;
	else
		std::cout << "int:\t" << static_cast<int>(n) << std::endl;
	if (n > FLT_MAX || n < FLT_MIN)
		std::cout << "float:\timposible" << std::endl;
	else
		std::cout << "float:\t" << static_cast<float>(n) << ".0f" << std::endl;
	std::cout << "double:\t" << static_cast<double>(n) << ".0" << std::endl;
}

void print_double(std::string str)
{
		long double n = atof(str.c_str());

	if (str.length() < 6 && isprint(n))
		std::cout << "char:\t'" << static_cast<char>(n) << "'" << std::endl;
	else
		std::cout << "char:\tNo mostrable" << std::endl;
	if (n > INT_MAX || n < INT_MIN)
		std::cout << "int:\timposible" << std::endl;
	else
		std::cout << "int:\t" << static_cast<int>(n) << std::endl;
	if (n > FLT_MAX || n < FLT_MIN)
		std::cout << "float:\timposible" << std::endl;
	else
		std::cout << "float:\t" << static_cast<float>(n) << ".0f" << std::endl;
	if (n > DBL_MAX || n < DBL_MIN)
		std::cout << "double:\timposible" << std::endl;
	else
		std::cout << "double:\t" << static_cast<double>(n) << ".0" << std::endl;
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