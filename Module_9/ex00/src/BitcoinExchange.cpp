#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	//std::cout << "BitcoinExchange copy constructor called" << std::endl;
	(void)other;
}

BitcoinExchange::BitcoinExchange(const char *file) {
	//std::cout << "BitcoinExchange file constructor called" << std::endl;
	std::ifstream data(file);
	parseInputFile(data);
}
// Operador de atribuição
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	//std::cout << "BitcoinExchange assignment operator called" << std::endl;
	(void)other;
	return *this;
}

bool BitcoinExchange::isLeapYear(int year)
{
	return ((year % 4 == 0 && year % 100 != 0) ||
			(year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
	if (date.length() != 10)
		return false;
	if (date[4] != '-' || date[7] != '-')
		return false;
	for (size_t i = 0; i < date.length(); i++)
	{
		if (i == 4 || i == 7)
			continue;
		if (!std::isdigit(date[i]))
			return false;
	}
	int year = std::atoi(date.substr(0, 4).c_str());
	int month = std::atoi(date.substr(5, 2).c_str());
	int day = std::atoi(date.substr(8, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	if (day < 1)
		return false;
	int daysInMonth[] =
	{
		31, // Jan
		28, // Feb
		31, // Mar
		30, // Apr
		31, // May
		30, // Jun
		31, // Jul
		31, // Aug
		30, // Sep
		31, // Oct
		30, // Nov
		31  // Dec
	};
	if (isLeapYear(year))
		daysInMonth[1] = 29;
	if (day > daysInMonth[month - 1])
		return false;
	return true;
}

int BitcoinExchange::parseInputFile(std::ifstream & file) const {
	
	if (!file.is_open())
		return 1;
	std::string line;
	std::getline(file, line);
	while(std::getline(file, line)) {
		this->_input[i] = 0;
		if (this->_checkPositive(line) == false)
			this->_input[i] = 1;
		if (this->_checkDate(line) == false && line.length() < 11)
			this->_input[i] = 2;
		if (this->_checkTooLarge(line) == false)
			this->_input[i] = 3;
		i++;
	}
	file.close();
	return 0;
}
// Destructor
BitcoinExchange::~BitcoinExchange() {
	//std::cout << "BitcoinExchange destructor called" << std::endl;
}

const char *BitcoinExchange::noDatabaseFile::what() const throw() {
	return "The data.csv file doesn't exists.";
}

const char *BitcoinExchange::amountLimitExceeded::what() const throw() {
	return "too large a number.";
}

const char *BitcoinExchange::amountNotPositive::what() const throw() {
	return "not a positive number.";
}

const char *BitcoinExchange::invalidDate::what() const throw() {
 	return "Date format is invalid.";
}

const char *BitcoinExchange::invalidFormat::what() const throw() {
 	return "Invalid format missing \" | \".";
}

const char *BitcoinExchange::wrongHeader::what() const throw() {
 	return "Wrong header on the file.";
}

const char *BitcoinExchange::nothingToRead::what() const throw() {
 	return "Nothing to read on the file.";
}