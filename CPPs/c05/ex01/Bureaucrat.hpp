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

// Bureaucrat declaration --------------------------------------------------------

#ifndef _BUREAUCRAT_HPP
# define _BUREAUCRAT_HPP
# include <iostream>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat(std::string name, int grade);
		Bureaucrat(Bureaucrat const& other);
		~Bureaucrat(void);

		Bureaucrat& operator=(Bureaucrat const& other);
		const std::string get_name(void) const;
		int get_grade(void) const;
		void increment_grade(void);
		void decrement_grade(void);
		void signForm(Form *form);

	class GradeTooHighException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return ("Grado demasiado alto");
			};
	};

	class GradeTooLowException : public std::exception
	{
		public:
			const char*  what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW
			{
				return ("Grado demasiado bajo");
			};
	};
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &bur);

#endif // !_BUREAUCRAT_HPP

