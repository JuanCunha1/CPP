#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <climits>
#include <cfloat>
#include <cmath>
#include <string>
#include <sstream>
#include <string>
#include <iomanip>

enum LiteralType
{
    CHAR,
    INT,
    FLOAT,
    DOUBLE,
    SPECIAL,
    INVALID
};

class ScalarConverter {
	private:
		static bool			isChar(const std::string& str);
		static bool			isInt(const std::string& str);
		static bool			isFloat(const std::string& str);
		static bool			isDouble(const std::string& str);
		static void			convertAndPrint(const std::string& str);
		static void			printImpossible();
		static void			printChar(double value);
		static void			printInt(double value);
		static void			printFloat(double value);
		static void			printDouble(double value);
		static void			printAll(double value);
		static int			hasDecimalPoint(const std::string& str);
		static int			isSpecialValue(const std::string& str);
		static void			printSpecialValue(const std::string& str);
		static LiteralType	getType(const std::string& str);

		// Orthodox Canonical Form
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();

		public:
		static void	convert(const std::string &representation);

};

#endif // SCALARCONVERTER_HPP
