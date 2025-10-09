#ifndef _COLORS
# define _COLORS

# define BLACK   "\033[1;30m"
# define RED     "\033[1;31m"
# define GREEN   "\033[1;32m"
# define YELLOW  "\033[1;33m"
# define BLUE    "\033[1;34m"
# define MAGENTA "\033[1;35m"
# define CYAN    "\033[1;36m"
# define WHITE   "\033[1;37m"
# define NC      "\033[0m"

#endif // !_COLORS

// BitcoinExchange declaration --------------------------------------------------------

#ifndef _BITCOINEXCHANGE_HPP
# define _BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <limits.h>

class BitcoinExchange {
private:
	std::map<std::string, float> data;
public:
	BitcoinExchange(void);
	BitcoinExchange(BitcoinExchange const& other);
	~BitcoinExchange(void);

	BitcoinExchange& operator=(BitcoinExchange const& other);
	void extract_data(std::ifstream &data_file);
	void calc_bitcoin(std::ifstream &file);
	bool check_values(float value);
	bool check_date(std::string key);
};

#endif // !_BITCOINEXCHANGE_HPP
