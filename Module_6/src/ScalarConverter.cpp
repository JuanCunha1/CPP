#include "ScalarConverter.hpp"

// Construtor padrão
ScalarConverter::ScalarConverter() {
//	std::cout << "ScalarConverter default constructor called" << std::endl;
}

// Construtor de cópia
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
//	std::cout << "ScalarConverter copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
//	std::cout << "ScalarConverter assignment operator called" << std::endl;
	if (this != &other) {

	}
	return *this;
}

// Destrutor
ScalarConverter::~ScalarConverter() {
//	std::cout << "ScalarConverter destructor called" << std::endl;
}

void ScalarConverter::convert(const std::string &representation) {
	convertAndPrint(representation);
}

bool ScalarConverter::isChar(const std::string& str) {
	return (str.length() == 1 && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string& str) {
	size_t i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < str.length(); i++) {
		if (!std::isdigit(str[i]))
			return false;
	}
	return true;
}

bool ScalarConverter::isFloat(const std::string& str) {
	size_t i = 0;
	bool hasDecimalPoint = false;
	size_t length = str.length();

	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[length - 1] != 'f')
    	return (false);
	for (; i < length - 1; i++) {
		if (str[i] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return hasDecimalPoint;
}

bool ScalarConverter::isDouble(const std::string& str) {
	size_t i = 0;
	bool hasDecimalPoint = false;
	size_t length = str.length();

	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; i < length; i++) {
		if (str[i] == '.') {
			if (hasDecimalPoint)
				return false;
			hasDecimalPoint = true;
		}
		else if (!std::isdigit(str[i]))
			return false;
	}
	return hasDecimalPoint;
}

void ScalarConverter::convertAndPrint(const std::string& str) {
	if (isChar(str)) {
		if (std::isprint(str[0])) {
			std::cout << "char: '" << str[0] << "'" << std::endl;
		}
		else {
			std::cout << "char: Non displayable" << std::endl;
		}
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
	}
	else if (isInt(str)) {
		std::stringstream ss(str);
		int i = 0;
		ss >> i;
		std::cout << "char: ";
		if (std::isprint( static_cast<char>(i)))
			std::cout << "'" << static_cast<char>(i) << "'";
		else
			std::cout << "Non displayable";
		std::cout << std::endl;
		std::cout << "int: " << i << std::endl;
		std::cout << "float: " << static_cast<float>(i) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(i) << ".0" << std::endl;
	}
	else if (isFloat(str)) {
		std::stringstream ss(str);
		float f = 0;
		ss >> f;
		std::cout << "char: ";
		if (std::isprint( static_cast<char>(f)))
			std::cout << "'" << static_cast<char>(f) << "'";
		else
			std::cout << "Non displayable";
		std::cout << std::endl;
		if (f >= INT_MIN && f <= INT_MAX)
			std::cout << "int: " << static_cast<int>(f) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << f << "f" << std::endl
				  << "double: " << static_cast<double>(f) << std::endl;
	}
	else if (isDouble(str)) {
		std::stringstream ss(str);
		double d = 0;
		ss >> d;
		std::cout << "char: ";
		if (std::isprint( static_cast<char>(d)))
			std::cout << "'" << static_cast<char>(d) << "'";
		else
			std::cout << "Non displayable";
		std::cout << std::endl;
		if (d >= INT_MIN && d <= INT_MAX)
			std::cout << "int: " << static_cast<int>(d) << std::endl;
		else
			std::cout << "int: impossible" << std::endl;
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl
				  << "double: " << d << std::endl;
	}
	else {
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: impossible" << std::endl;
		std::cout << "double: impossible" << std::endl;
	}
}