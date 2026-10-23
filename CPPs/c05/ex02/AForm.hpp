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

// Form declaration --------------------------------------------------------

#ifndef _AFORM_HPP
# define _AFORM_HPP

#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	protected:
		std::string const _name;
		bool _is_signed;
		int const _sign_grade;
		int	const _execute_grade;
	public:
		AForm(std::string name, int sign_grade, int execute_grade);
		AForm(AForm const& other);
		virtual ~AForm(void);

		virtual const std::string get_name(void) const;
		virtual int get_sign_grade(void) const;
		virtual int	get_execute_grade(void) const;
		virtual void beSigned(Bureaucrat *bur);
		virtual void execute(Bureaucrat const & executor) const = 0;

		AForm& operator=(AForm const& other);
		
	class GradeTooHighException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return ("Grado de formulario demasiado bajo");
			};
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return ("Grado de formulario demasiado alto");
			};
	};
};
std::ostream &operator<<(std::ostream &o, const AForm &bur);


#endif // !_FORM_HPP

