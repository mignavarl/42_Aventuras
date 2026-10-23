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

// HumanB declaration --------------------------------------------------------

#ifndef _HUMANB_HPP
# define _HUMANB_HPP
# include "Weapon.hpp"

class HumanB {
	private:
		std::string	_name;
		Weapon 		*_weapon;
	public:
		HumanB(void);
		HumanB(std::string);
		~HumanB(void);
		void	attack() const;
		void	setWeapon(Weapon &weapon);
};

#endif // !_HUMANB_HPP

