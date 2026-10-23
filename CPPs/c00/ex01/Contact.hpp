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

// Contact declaration --------------------------------------------------------

#ifndef _CONTACT_HPP
# define _CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	secret;
public:
	bool		check_stat(Contact *person);
	void		put_first(std::string com, Contact *person);
	void		put_last(std::string com, Contact *person);
	void		put_nick(std::string com, Contact *person);
	void		put_phone(std::string com, Contact *person);
	void 		put_secret(std::string com, Contact *person);
	std::string	get_first(Contact *person);
	std::string	get_last(Contact *person);
	std::string	get_nick(Contact *person);
	std::string	get_phone(Contact *person);
	std::string	get_secret(Contact *person);


	Contact(/* args */);
	~Contact();
};

#endif // !_CONTACT_HPP

