#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include <exception>
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class AForm;
class PresidentialPardonForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;

class Intern {
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm *makeForm(const std::string &formName,const std::string &targetForm);
		AForm *makeShrubberyCreationForm(const std::string &target);
		AForm *makePresidentialPardonForm(const std::string &target);
		AForm *makeRobotomyRequestForm(const std::string &target);

		class FormNotFound : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#endif // INTERN_HPP
