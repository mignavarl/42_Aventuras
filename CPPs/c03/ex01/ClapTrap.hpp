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

// ClapTrap declaration --------------------------------------------------------

#ifndef _CLAPTRAP_HPP
# define _CLAPTRAP_HPP
# include <iostream>

class ClapTrap {
protected:
	std::string _name;
	int	_health;
	int	_energy;
	int _attack_damage;
public:
	ClapTrap(void);
	ClapTrap(std::string name);
	ClapTrap(ClapTrap const& other);
	~ClapTrap(void);
	ClapTrap& operator=(ClapTrap const& other);

	void attack(const std::string& target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif // !_CLAPTRAP_HPP

