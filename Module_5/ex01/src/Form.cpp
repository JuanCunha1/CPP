#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form()
	: _name("Default"),
	  _isSigned(false),
	  _gradeToSign(150),
	  _gradeToExecute(150) {
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute)
	: _name(name),
	  _isSigned(false),
	  _gradeToSign(gradeToSign),
	  _gradeToExecute(gradeToExecute) {
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &other)
	: _name(other._name),
	  _isSigned(other._isSigned),
	  _gradeToSign(other._gradeToSign),
	  _gradeToExecute(other._gradeToExecute) {
}

Form &Form::operator=(const Form &other) {
	if (this != &other)
		this->_isSigned = other._isSigned;
	return (*this);
}

// Destructor
Form::~Form() {
}

// Getters
std::string Form::getName() const
{
	return (_name);
}

bool Form::getIsSigned() const
{
	return (_isSigned);
}

int Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

// Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return ("Form grade too high!");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Form grade too low!");
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
	out << "Form \"" << form.getName() << "\""
		<< ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade required to sign: " << form.getGradeToSign()
		<< ", grade required to execute: " << form.getGradeToExecute();
	return (out);
}
