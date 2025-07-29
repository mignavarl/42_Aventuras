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

// Zombie declaration --------------------------------------------------------

#ifndef _ZOMBIE_HPP
# define _ZOMBIE_HPP
# include <string>
# include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		Zombie();
		Zombie(std::string name);
		~Zombie(void);
		void SetName(std::string n);

	void	announce(void);
};

Zombie* zombieHorde(int N, std::string name);

#endif // !_ZOMBIE_HPP

