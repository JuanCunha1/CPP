#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
	AForm("Default", 25, 5), _target("Default") {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
	AForm(target, 25, 5), _target(target) {
}


// Constructor de cópia
PresidentialPardonForm::PresidentialPardonForm(
	const PresidentialPardonForm& other)  : AForm(other.getName(),
		other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {
	this->setSigned(other.getIsSigned());
}

// Operador de atribuição
PresidentialPardonForm& PresidentialPardonForm::operator=(
	const PresidentialPardonForm& other) {
	if (this == &other)
		return *this;
	this->_target = other._target;
	this->setSigned(other.getIsSigned());
	return *this;
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::executer() const {
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
