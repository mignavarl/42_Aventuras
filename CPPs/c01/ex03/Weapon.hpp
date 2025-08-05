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

// Weapon declaration --------------------------------------------------------

#ifndef _WEAPON_HPP
# define _WEAPON_HPP

#include <string>
#include <iostream>

class Weapon {
private:
	std::string type;
public:
	Weapon();
	Weapon(std::string type);
	~Weapon(void);

	const std::string &getType();
	void setType(std::string type);
};

#endif // !_WEAPON_HPP

