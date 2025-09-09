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

// Intern declaration --------------------------------------------------------

#ifndef _INTERN_HPP
# define _INTERN_HPP

#include <iostream>
#include "Forms.hpp"

class Intern 
{
	public:
		Intern(void);
		Intern(Intern const& other);
		~Intern(void);

		Intern& operator=(Intern const& other);
		AForm *makeForm(std::string form_name, std::string target);
};

#endif // !_INTERN_HPP

