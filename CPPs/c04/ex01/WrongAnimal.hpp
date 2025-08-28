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

// WrongAnimal declaration --------------------------------------------------------

#ifndef _WRONGANIMAL_HPP
# define _WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
	protected:
		std::string type;
public:
	WrongAnimal(void);
	WrongAnimal(WrongAnimal const& other);
	virtual ~WrongAnimal(void);

	WrongAnimal& operator=(WrongAnimal const& other);
	virtual std::string getType(void) const;
	void makeSound(void) const;
};

#endif // !_WRONGANIMAL_HPP

