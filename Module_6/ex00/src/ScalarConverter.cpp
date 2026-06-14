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

bool ScalarConverter::isFloat(const std::string& str)
{
    if (str.empty() || str[str.length() - 1] != 'f')
        return false;

    std::string tmp = str.substr(0, str.length() - 1);
	if (tmp.find('.') == std::string::npos)
		return false;

    char *end;
    std::strtod(tmp.c_str(), &end);

    return (*end == '\0');
}

bool ScalarConverter::isDouble(const std::string& str)
{
	if (str == "inf" || str == "inff")
        return false;
	if (str.empty())
		return false;
	char *end;
	std::strtod(str.c_str(), &end);
	return (end != str.c_str() && *end == '\0');
}

void ScalarConverter::printImpossible() {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void ScalarConverter::printChar(double value) {
	if (value < 0 || value > 127)
    {
        std::cout << "char: impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(value);
    if (std::isprint(static_cast<unsigned char>(c)))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
}

void ScalarConverter::printInt(double value) {
	if (value >= INT_MIN && value <= INT_MAX) {
		std::cout << "int: " << static_cast<int>(value) << std::endl;
	}
	else {
		std::cout << "int: impossible" << std::endl;
	}
}

void ScalarConverter::printFloat(double value) {
	std::cout << "float: " ;
	if(isinf(value)) 
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
		std::cout << static_cast<float>(value);
	if (value == std::floor(value) && !std::isinf(value))
		std::cout << ".0";
	std::cout << "f" << std::endl;
}

void ScalarConverter::printDouble(double value) {
	std::cout << "double: ";
	if (std::isinf(value))
		std::cout << (value > 0 ? "+inf" : "-inf");
	else
		std::cout << value;
	if (value == std::floor(value) && !std::isinf(value))
		std::cout << ".0";
	std::cout << std::endl;
}

void ScalarConverter::printAll(double value) {
	printChar(value);
	printInt(value);
	printFloat(value);	
	printDouble(value);
}

int ScalarConverter::hasDecimalPoint(const std::string& str) {
	return (str.find('.') != std::string::npos);
}

int ScalarConverter::isSpecialValue(const std::string& str) {
	return (str == "nan" || str == "nanf" || str == "+inf" || str == "+inff" || str == "-inf" || str == "-inff");
}

void ScalarConverter::printSpecialValue(const std::string& str) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str == "nan" || str == "nanf") {
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
	}
	else if (str == "+inf" || str == "+inff") {
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
	else if (str == "-inf" || str == "-inff") {
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
}

LiteralType ScalarConverter::getType(const std::string& str) {
	if (isChar(str))
		return CHAR;
	if (isInt(str))
		return INT;
	if (isFloat(str))
		return FLOAT;
	if (isDouble(str))
		return DOUBLE;
	if (isSpecialValue(str))
		return SPECIAL;
	return INVALID;
}

void ScalarConverter::convertAndPrint(const std::string& str) {
	LiteralType type = getType(str);
	switch (type)
	{
		case CHAR:
			printAll(str[0]);
			break;
		case SPECIAL:
			printSpecialValue(str);
			break;
		case INT:
		case FLOAT:
		case DOUBLE:
		{
			double d = std::strtod(str.c_str(), NULL);
			printAll(d);
			break;
		}
		default:
			printImpossible();
	}
}