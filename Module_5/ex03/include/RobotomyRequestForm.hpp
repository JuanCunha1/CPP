#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <cstdlib>
#include <ctime>
#include <exception>

class RobotomyRequestForm : public AForm{
	private:
		std::string _target;

	public:
		// Orthodox Canonical Form
		RobotomyRequestForm(void);
		RobotomyRequestForm(const std::string &target);
		explicit RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		~RobotomyRequestForm(void);

		void executer(void) const;
};

#endif // ROBOTOMYREQUESTFORM_HPP
