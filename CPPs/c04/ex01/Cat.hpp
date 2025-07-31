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

// Cat declaration --------------------------------------------------------

#ifndef _CAT_HPP
# define _CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal {
private:
	Brain *brain;
public:
	Cat(void);
	Cat(Cat const& other);
	~Cat(void);

	Cat& operator=(Cat const& other);
	void makeSound(void) const;
};

#endif // !_CAT_HPP

