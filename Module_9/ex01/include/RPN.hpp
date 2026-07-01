#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <climits>

class RPN {
	private:
		bool calculate(char op, int a, int b, int& result);
	public:
		// Orthodox Canonical Form
		RPN(void);
		RPN(const RPN& other);
		RPN& operator=(const RPN& other);
		~RPN();
		void evaluate(const std::string& expression);

		class InvalidException : public std::exception {
			const char *what() const throw();
		};
};

#endif // RPN_HPP
