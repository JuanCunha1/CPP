#include "ShrubberyCreationForm.hpp"

// Constructor padrão
ShrubberyCreationForm::ShrubberyCreationForm() :
	AForm("Default", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const std::string &target)  : AForm(target, 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(
	const ShrubberyCreationForm& other) : AForm(other.getName(),
		other.getGradeToSign(), other.getGradeToExecute()), _target(other._target) {
	this->setSigned(other.getIsSigned());
}

// Operador de atribuição
ShrubberyCreationForm& ShrubberyCreationForm::operator=(
	const ShrubberyCreationForm& other) {
	if (this == &other)
		return *this;
	this->_target = other._target;
	this->setSigned(other.getIsSigned());
	return *this;
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {

}

void ShrubberyCreationForm::executer() const {
	std::ofstream outputFile((this->_target + "_shrubbery").c_str());
	if (!outputFile.is_open())
	{
		std::cerr << "Error: could not create shrubbery file"
			<< std::endl;
		return;
	}

	outputFile << "       *\n";
	outputFile << "      /|\\\n";
	outputFile << "     /*|O\\\n";
	outputFile << "    /*/|\\\\\\\n";
	outputFile << "   /X/O|*\\\\\\\n";
	outputFile << "  /*/X/|\\\\X\\\\\n";
	outputFile << " /O/*/X|*\\\\O\\\\\n";
	outputFile << "/X/O/*/|\\\\X\\O\\\\\n";
	outputFile << "      |X|\n";
	outputFile << "      |X|\n";

	outputFile.close();
}
