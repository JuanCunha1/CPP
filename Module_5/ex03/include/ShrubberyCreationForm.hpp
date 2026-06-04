#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <exception>

class AForm;

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		// Orthodox Canonical Form
		ShrubberyCreationForm(void);
		ShrubberyCreationForm(const std::string &target);
		explicit ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm(void);

		void executer(void) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
