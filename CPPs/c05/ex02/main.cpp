#include "Bureaucrat.hpp"
#include "Forms.hpp"

int main(void)
{
	Bureaucrat Paco("Paco", 50);
	Bureaucrat Aitor = Bureaucrat("Aitor", 31);
	Bureaucrat Alicia("Alicia", 6); 

	AForm *bery = new ShrubberyCreationForm("casa");
	AForm *robo = new RobotomyRequestForm("Inés");
	AForm *pres = new PresidentialPardonForm("Tu tía de Granada");

	Paco.signForm(bery);
	Paco.executeForm(*bery);
	std::cout << "----------------------------------\n";
	Aitor.signForm(robo);
	Aitor.executeForm(*robo);
	std::cout << "----------------------------------\n";
	Alicia.signForm(pres);
	Alicia.executeForm(*pres);
	Alicia.increment_grade();
	Alicia.executeForm(*pres);
	delete(bery);
	delete(robo);
	delete(pres);
}