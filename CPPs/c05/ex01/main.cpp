#include "Bureaucrat.hpp"

int main(void)
{

	Bureaucrat paco("Paco", 50);
	Bureaucrat aitor = Bureaucrat("Aitor", 31);

	Form formA("Form A", 70, 30);
	Form formB("Form B", 30, 10);

	paco.signForm(&formA);
	paco.signForm(&formB);
	aitor.signForm(&formB);
	aitor.increment_grade();
	aitor.signForm(&formB);
}