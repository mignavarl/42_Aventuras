#include "BitcoinExchange.hpp"

// CONSTRUCTORS AND DESTRUCTORS-------------------------------------------------
BitcoinExchange::BitcoinExchange(void)
{
	//std::cout << GREEN "BitcoinExchange default constructor called" NC << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other)
{
	//std::cout << GREEN "BitcoinExchange copy constructor called" NC << std::endl;
	*this = other;
}

BitcoinExchange::~BitcoinExchange(void)
{
	//std::cout << RED "BitcoinExchange destructor called" NC << std::endl;
}

// OPERATORS--------------------------------------------------------------------
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other)
{
	if (this == &other) {
		return *this;
	}
	// DO THINGS
	return *this;
}

// METHODS AND MEMBER FUNCTIONS-------------------------------------------------
void BitcoinExchange::extract_data(std::ifstream &data_file)
{
	std::string	line;
	std::string	key;
	std::string s_value;
	const char * ch_val;

	std::getline(data_file, line);
	for (size_t i = 0; std::getline(data_file, line); i++)
	{

		key.insert(0, line, 0, line.find(','));
		s_value.insert(0, line, (line.find(',') + 1), line.size());
		ch_val = s_value.c_str();
		this->data.insert(std::pair<std::string, float>(key, atof(ch_val)));
		key.clear();
		s_value.clear();
	}
}

bool BitcoinExchange::check_values(float value)
{
	if (value < 0)
	{
		std::cout << RED "Error: número negativo ➖" NC << std::endl;
		return (false);
	}
	else if (value >= (float)INT_MAX)
	{
		std::cout << RED "Error: número mu' largo" NC << std::endl;
		return (false);
	}
	return (true);
}

bool BitcoinExchange::check_date(std::string key)
{
	std::string save;
	int year;
	int month;
	int day;
	int dash = 0;

	for (size_t i = 0; key[i]; i++)
	{
		if ((isalnum(key[i]) && key[i] == '-') || (!isalnum(key[i]) && key[i] != '-'))
		{
			std::cout << RED "Error: fecha mal => " << key << NC << std::endl;
			return (false);
		}
		if (key[i] == '-')
		{
			dash++;
			if (dash > 2)
			{
				std::cout << RED "Error: fecha mal => " << key << NC << std::endl;
				return (false);
			}
		}
	}
	//std::cout << "----------------------------\n";
	save = key.substr(0, (key.find_first_of('-')));
	year = atoi(save.c_str());
	//std::cout << "year string = " << save << "/ int = " << year << std::endl;
	save = key.substr(key.find_first_of('-') + 1, key.rfind('-'));
	month = atoi(save.c_str());
	//std::cout << "month string = " << save << "/ int = " << month << std::endl;
	save =  key.substr(key.rfind('-') + 1, key.length());
	day = atoi(save.c_str());
	//std::cout << "day string = " << save << "/ int = " << day << std::endl;
	if (year > 2025 || year < 2000 || month < 1 || month > 12 || day < 0 || day > 31)
	{
		std::cout << RED "Error: fecha mal => " << key << NC << std::endl;
		return (false);
	}
	return (true);
}

void BitcoinExchange::calc_bitcoin(std::ifstream &file)
{
	std::string line;
	std::string key;
	std::string s_value;
	float		value;
	float		res;
	std::map<std::string, float>::iterator pos;

	for (; std::getline(file, line);)
	{
		key.insert(0, line, 0, (line.find('|') - 1));
		s_value.insert(0, line, (line.find('|') + 1), line.size());
		value = atof(s_value.c_str());
		//std::cout << "---------------------------------\n";
		//std::cout << "key = " << key << "\nvalue = " << s_value << "\nfloat = " << value << std::endl;
		if (check_values(value) && check_date(key))
		{
			pos = this->data.lower_bound(key);
			if (pos->first != key)
				pos--;
			res = value * pos->second;
			//std::cout << value << " * " << pos->second << " = " << res << std::endl;
			std::cout << key << " => " << s_value << " = " << res << std::endl;
		}
		key.clear();
		s_value.clear();
	}
}