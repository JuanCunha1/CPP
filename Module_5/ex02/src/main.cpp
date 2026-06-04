#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
/*
int main()
{
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
*/

int main()
{
    Intern intern;
    Bureaucrat boss("Boss", 1);
    Bureaucrat worker("Worker", 50);
    Bureaucrat low("Low", 150);

    AForm *form;

    std::cout << "\n===== Shrubbery Creation =====\n";
    try
    {
        form = intern.makeForm("ShrubberyCreation", "home");

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Robotomy Request =====\n";
    try
    {
        form = intern.makeForm("RobotomyRequest", "Bender");

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Presidential Pardon =====\n";
    try
    {
        form = intern.makeForm("PresidentialPardon", "Arthur Dent");

        boss.signForm(*form);
        boss.executeForm(*form);

        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Unknown Form =====\n";
    try
    {
        form = intern.makeForm("CoffeeRequest", "student");
        delete form;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Execute Unsigned Form =====\n";
    try
    {
        form = intern.makeForm("ShrubberyCreation", "garden");

        worker.executeForm(*form);

        delete form;
    }
    catch (std::exception &e)
    {
        delete form;
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Sign Grade Too Low =====\n";
    try
    {
        form = intern.makeForm("PresidentialPardon", "Marvin");

        low.signForm(*form);

        delete form;
    }
    catch (std::exception &e)
    {
        delete form;
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===== Execute Grade Too Low =====\n";
    try
    {
        form = intern.makeForm("PresidentialPardon", "Ford Prefect");

        boss.signForm(*form);
        worker.executeForm(*form);

        delete form;
    }
    catch (std::exception &e)
    {
        delete form;
        std::cout << e.what() << std::endl;
    }

    return (0);
}
