#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <string>
#include <sstream>
#include <string>


class ScalarConverter {
	private:
		static bool isChar(const std::string& str);
		static bool isInt(const std::string& str);
		static bool isFloat(const std::string& str);
		static bool isDouble(const std::string& str);
		static void convertAndPrint(const std::string& str);
		// Orthodox Canonical Form
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		public:
		static void convert(const std::string &representation);

};

#endif // SCALARCONVERTER_HPP
