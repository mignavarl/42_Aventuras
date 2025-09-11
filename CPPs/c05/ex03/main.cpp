#include "Bureaucrat.hpp"
#include "Forms.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern someRandomIntern;
	AForm* rrf;
	AForm* wrong;
	Bureaucrat Aitor("Aitor", 31);

	rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	rrf->beSigned(&Aitor);
	rrf->execute(Aitor);
	std::cout << "------------------------------------------\n";
	wrong = someRandomIntern.makeForm("Tortilla de patata request", "Tu primo");
	std::cout << "------------------------------------------\n";
	delete (rrf);
}