#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
	//std::cout << "BitcoinExchange default constructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {
	//std::cout << "BitcoinExchange copy constructor called" << std::endl;
	(void)other;
}

BitcoinExchange::BitcoinExchange(std::ifstream & file) {
	//std::cout << "BitcoinExchange file constructor called" << std::endl;
	try
	{
		parseDatabase();
		parseInputFile(file);
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: "<< e.what() << '\n';
	}
}
// Operador de atribuição
BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
	//std::cout << "BitcoinExchange assignment operator called" << std::endl;
	(void)other;
	return *this;
}

void BitcoinExchange::parseDatabase() {
	
	std::ifstream data("data.csv");
	if (!data.is_open())
		throw noDatabaseFile();
	std::string line;
	while (std::getline(data, line)) {
		if (line.length() < 14)
			continue;
		if (line.find(",") == std::string::npos)
			continue;
		std::string datePart = line.substr(0, line.find(","));
		std::string amountPartStr = line.substr(line.find(",") + 1);
		if (datePart.empty() || amountPartStr.empty())
			continue;
		if(!isValidDate(datePart))
			continue;
		char* pEnd;
		float amount = std::strtof(amountPartStr.c_str(), &pEnd);
		if (*pEnd != '\0')
			continue;
		_list[datePart] = amount;
	}
	data.close();
}

bool BitcoinExchange::isLeapYear(int year) const
{
	return ((year % 4 == 0 && year % 100 != 0) ||
			(year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string& date) const
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
	switch (month)
	{
		case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			if (day > 31)
				return false;
			break;
		case 4: case 6: case 9: case 11:
			if (day > 30)
				return false;
			break;
		case 2:
			if (isLeapYear(year))
			{
				if (day > 29)
					return false;
			}
			else
			{
				if (day > 28)
					return false;
			}
			break;
		default:
			return false;
	}
	
	return true;
}

float BitcoinExchange::findValue(const std::string& date)
{
    if (_list.empty())
        throw std::runtime_error("database is empty");

    std::map<std::string, float>::iterator it = _list.lower_bound(date);

    if (it != _list.end() && it->first == date)
        return it->second;

    if (it == _list.begin())
        throw std::runtime_error("no earlier date available");

    --it;
    return it->second;
}
void BitcoinExchange::parseInputFile(std::ifstream & file) {
	
	if (!file.is_open())
		throw std::runtime_error("failed to open input file");
	std::string line;
	try
	{
		if (!std::getline(file, line))
	    	throw wrongHeader();
		if (line != "date | value")
			throw wrongHeader();
	}
	catch(const std::exception& e)
	{
		std::cout << "Error: "<< e.what() << '\n';
	}
	while(std::getline(file, line)) {
		try
		{
			float amount = 0;
			if (line.length() < 14)
				throw std::runtime_error("bad input => " + line);
			if (line.find(" | ") == std::string::npos)
				throw invalidFormat();
			std::string datePart = line.substr(0, line.find(" | "));
			std::string amountPartStr = line.substr(line.find(" | ") + 3);
			if (datePart.empty() || amountPartStr.empty())
		        throw invalidFormat();
			if(!isValidDate(datePart))
				throw invalidDate();
			if (!amountPartStr.empty()) {
				char* pEnd;
				amount = std::strtof(amountPartStr.c_str(), &pEnd);
				if (*pEnd != '\0')
					throw invalidAmount();
				if (amount < 0)
					throw amountNotPositive();
				if (amount > 1000)
					throw amountLimitExceeded();
			}
			float value = findValue(datePart);
			
			std::cout << datePart << " => " << amountPartStr << " = "
                << value * amount << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << "Error: "<< e.what() << '\n';
		}
	}
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
 	return "date format is invalid.";
}

const char *BitcoinExchange::invalidFormat::what() const throw() {
	return "invalid format missing \" | \".";
}

const char *BitcoinExchange::wrongHeader::what() const throw() {
	return "wrong header on the file.";
}

const char *BitcoinExchange::nothingToRead::what() const throw() {
	return "nothing to read on the file.";
}

const char *BitcoinExchange::invalidAmount::what() const throw() {
	return "invalid amount format.";
}