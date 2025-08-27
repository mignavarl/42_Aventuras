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

// MateriaSource declaration --------------------------------------------------------

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "Materia.hpp"

#define MAX_SRC 3
class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

class MateriaSource : public IMateriaSource
{
	private:
		AMateria *list[MAX_SRC];
	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const& other);
		~MateriaSource(void);

		MateriaSource& operator=(MateriaSource const& other);
		void learnMateria(AMateria* m);
		AMateria* createMateria(std::string const & type);
};

#endif // !_MATERIASOURCE_HPP

