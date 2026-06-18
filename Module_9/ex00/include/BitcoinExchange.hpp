#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <algorithm>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <time.h>
#include <unistd.h>
#include <iomanip>
#include <limits>
#include <cmath>
#include <cstdlib>

class BitcoinExchange {
	private:
		std::map<std::string, float> _list;

		BitcoinExchange(void);

		template <typename T> std::string NumberToString(T Number) {
			std::ostringstream ss;
			ss << Number;
			return ss.str();
		}
		int parseInputFile(std::ifstream & file) const;

		bool isLeapYear(int year);
		bool isValidDate(const std::string& date);

		int		_getInputSize(std::ifstream & file) const;
		void	_parseData(std::ifstream & file);
		void	_parseInput(std::ifstream & file);
		bool	_checkDate(std::string line);
		bool	_checkPositive(std::string line);
		bool	_checkTooLarge(std::string line);
		void	_output(std::ifstream & file);
		void	_nearestDate(std::string & key);
		
	public:
		// Orthodox Canonical Form
		
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		explicit BitcoinExchange(const char *file);

		
};

#endif // BITCOINEXCHANGE_HPP
