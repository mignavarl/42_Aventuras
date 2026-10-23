#include "ScalarConverter.hpp"

bool type_char(std::string str)
{
	if (str.length() > 1)
		return false;
	if (isalpha(str[0]))
			return true;
	return false;
}

bool type_int(std::string str)
{
	size_t i = 0;
	if (str[0] == '+' || str[0] == '-')
		i++;
	for (; str[i]; i++)
	{
		if (!isalnum(str[i]) || isalpha(str[i]))
			return false;
	}
	return true;
}

bool type_double(std::string str)
{
	bool dot_flag = false;

	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == '.' && !dot_flag)
			dot_flag = true;
		else if (str[i] == '.' && dot_flag)
			return false;
		else if (!isalnum(str[i]))
			return false;
	}
	return true;
}

bool type_float(std::string str)
{
	int last = str.length();
	if (str[last - 1] != 'f')
		return false;
	bool dot_flag = false;
	for (size_t i = 0; str[i]; i++)
	{
		if (str[i] == '.' && !dot_flag)
			dot_flag = true;
		else if (str[i] == '.' && dot_flag)
			return false;
		else if (!isalnum(str[i]))
			return false;
	}
	return true;
}

e_type find_type(std::string str)
{
	if (str == "nan" || str == "nanf" || str == "+inf" || str == "-inf" || str == "+inff" || str == "-inff")
		return PSEUDO;
	size_t dot = str.find('.');
	if (dot == std::string::npos)
	{
		if (type_char(str))
			return CHAR;
		if (type_int(str))
			return INT;
	}
	size_t ef = str.find('f');
	if (dot != std::string::npos && ef == std::string::npos)
	{
		if (type_double(str))
			return DOUBLE;
	}
	if (dot != std::string::npos && ef != std::string::npos)
	{
		if (type_float(str))
			return FLOAT;
	}
	return NO_TYPE;
}