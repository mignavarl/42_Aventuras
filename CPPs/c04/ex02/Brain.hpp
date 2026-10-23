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

// Brain declaration --------------------------------------------------------

#ifndef _BRAIN_HPP
# define _BRAIN_HPP

# include <iostream>

class Brain {
private:
	std::string ideas[100];
public:
	Brain(void);
	Brain(Brain const& other);
	~Brain(void);

	Brain& operator=(Brain const& other);
	std::string getBrainIdea(int i);
	void 		setBrainIdea(std::string idea, int i);
};

#endif // !_BRAIN_HPP

