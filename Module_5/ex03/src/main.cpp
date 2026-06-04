#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Intern someRandomIntern;
	Bureaucrat boss("Boss", 1);

	AForm *form;
	try
	{
		std::cout << "\n=== Shrubbery Creation Form ===\n";
		form = someRandomIntern.makeForm("ShrubberyCreation", "home");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}

		std::cout << "\n=== Robotomy Request Form ===\n";
		form = someRandomIntern.makeForm("RobotomyRequest", "Bender");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}

		std::cout << "\n=== Presidential Pardon Form ===\n";
		form = someRandomIntern.makeForm("PresidentialPardon", "Arthur Dent");
		if (form)
		{
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}
	try
	{
		std::cout << "\n=== Invalid Form ===\n";
		form = someRandomIntern.makeForm("coffee request", "student");
		if (form)
			delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << "\n";
	}

	try {
		Bureaucrat low("LowRank", 150);

		AForm *form = someRandomIntern.makeForm("PresidentialPardon", "Marvin");
		if (form)
		{
			low.signForm(*form);
			low.executeForm(*form);

			delete form;
		}
	}
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << "\n";
	}
	return (0);
}
