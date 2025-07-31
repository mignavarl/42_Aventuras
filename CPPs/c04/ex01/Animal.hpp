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

// Animal declaration --------------------------------------------------------

#ifndef _ANIMAL_HPP
# define _ANIMAL_HPP

# include <iostream>

class Animal {
	protected:
		std::string type;
	public:
		Animal(void);
		Animal(Animal const& other);
		virtual ~Animal(void);

		Animal& operator=(Animal const& other);
		virtual std::string  getType(void) const;
		virtual void makeSound(void) const;
};

#endif // !_ANIMAL_HPP

