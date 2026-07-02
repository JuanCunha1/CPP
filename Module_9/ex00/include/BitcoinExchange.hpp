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
		void parseInputFile(std::ifstream & file);

		bool isLeapYear(int year) const;
		bool isValidDate(const std::string& date) const;

		void	parseDatabase();
		float	findValue(const std::string &date);
		
	public:
		// Orthodox Canonical Form
		
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		explicit BitcoinExchange(std::ifstream & file);

		class noDatabaseFile : public std::exception {
			const char *what() const throw();
		};

		class amountLimitExceeded : public std::exception {
			const char *what() const throw();
		};

		class amountNotPositive : public std::exception {
			const char *what() const throw();
		};

		class invalidDate : public std::exception {
			const char *what() const throw();
		};

		class invalidFormat : public std::exception {
			const char *what() const throw();
		};

		class wrongHeader : public std::exception {
			const char *what() const throw();
		};

		class nothingToRead : public std::exception {
			const char *what() const throw();
		};

		class invalidAmount : public std::exception {
			const char *what() const throw();
		};
};

#endif // BITCOINEXCHANGE_HPP
