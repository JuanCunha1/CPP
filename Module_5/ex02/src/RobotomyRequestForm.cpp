#include "RobotomyRequestForm.hpp"

// Constructor padrão
RobotomyRequestForm::RobotomyRequestForm() :
	AForm("Default", 72, 45), _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) :
	AForm(target, 145, 137), _target(target) {
}

// Constructor de cópia
RobotomyRequestForm::RobotomyRequestForm(
	const RobotomyRequestForm& other)  : AForm(other.getName(),
		other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {
	this->setSigned(other.getIsSigned());
}

// Operador de atribuição
RobotomyRequestForm& RobotomyRequestForm::operator=(
	const RobotomyRequestForm& other) {
	if (this == &other)
		return *this;
	this->_target = other._target;
	this->setSigned(other.getIsSigned());
	return *this;
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::executer() const {
	std::cout << _target << " started to drill" << std::endl;
	std::cout << "BZZZZZZT... DRRRRRRR...\n";

	if (rand() % 2)
	    std::cout << _target << " has been robotomized successfully\n";
	else
		std::cout << _target << " failed to robotomize!\n";
}
