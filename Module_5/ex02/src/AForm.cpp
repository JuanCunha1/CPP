#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"),
	  _isSigned(false),
	  _gradeToSign(150),
	  _gradeToExecute(150) {
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _isSigned(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {
}

AForm &AForm::operator=(const AForm &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

// Destructor
AForm::~AForm() {
}

// Getters
std::string AForm::getName() const
{
	return (_name);
}

bool AForm::getIsSigned() const
{
	return (_isSigned);
}

int AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

const char *AForm::FormIsNotSigned::what() const throw() {
	return ("The Form was not signed!");
}

void	AForm::setSigned(bool sig)
{
	_isSigned = sig;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
	if (!this->getIsSigned())
		throw AForm::FormIsNotSigned();
	if (this->getGradeToExecute() < executor.getGrade())
		throw AForm::GradeTooLowException();

	executer();
}

std::ostream &operator<<(std::ostream &out, const AForm &Form)
{
	out << "Form \"" << Form.getName() << "\""
		<< ", signed: " << (Form.getIsSigned() ? "yes" : "no")
		<< ", grade required to sign: " << Form.getGradeToSign()
		<< ", grade required to execute: " << Form.getGradeToExecute();
	return (out);
}
