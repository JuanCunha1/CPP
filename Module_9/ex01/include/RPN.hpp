#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>

class RPN {
public:
	// Orthodox Canonical Form
	RPN(void);
	RPN(const RPN& other);
	RPN& operator=(const RPN& other);
	~RPN();
	void evaluate(const std::string& expression);
};

#endif // RPN_HPP
