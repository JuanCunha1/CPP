#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));
    std::cout << "\n===== Bureaucrat Exceptions =====\n";
    try
    {
        Bureaucrat a("TooHigh", 0);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    try
    {
        Bureaucrat b("TooLow", 151);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);
    Bureaucrat intern("Intern", 150);

    std::cout << "\n===== Execute Unsigned Form =====\n";
    try
    {
        ShrubberyCreationForm shrub("garden");
        worker.executeForm(shrub);
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Sign Grade Too Low =====\n";
    {
        PresidentialPardonForm pardon("Arthur Dent");
        intern.signForm(pardon);
    }

    std::cout << "\n===== Execute Grade Too Low =====\n";
    {
        PresidentialPardonForm pardon("Arthur Dent");

        boss.signForm(pardon);
        worker.executeForm(pardon);
    }

    std::cout << "\n===== Successful Shrubbery =====\n";
    {
        ShrubberyCreationForm shrub("home");

        worker.signForm(shrub);
        worker.executeForm(shrub);
    }

    std::cout << "\n===== Successful Robotomy =====\n";
    {
        RobotomyRequestForm robot("Bender");

        boss.signForm(robot);
        for (int i = 0; i < 10; i++)
            boss.executeForm(robot);
    }

    std::cout << "\n===== Successful Presidential Pardon =====\n";
    {
        PresidentialPardonForm pardon("Marvin");

        boss.signForm(pardon);
        boss.executeForm(pardon);
    }

    return 0;
}
