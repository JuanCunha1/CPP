#include "RPN.hpp"

// Constructor padrão
RPN::RPN() {

}

// Constructor de cópia
RPN::RPN(const RPN& other) {
	
	*this = other;
}

// Operador de atribuição
RPN& RPN::operator=(const RPN& other) {
	if (this != &other) {
		
	}
	return *this;
}

// Destructor
RPN::~RPN() {
}

void RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;
	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (token[0] == '+' || token[0] == '-' || token[0] == '*' || token[0]
		 == '/') {
			if (stack.size() < 2) {
				std::cerr << "Error" << std::endl;
				return;
			}
			int b = stack.top();
			stack.pop();
			int a = stack.top();
			stack.pop();
			int result;
			switch (token[0]) {
				case '+': result = a + b; break;
				case '-': result = a - b; break;
				case '*': result = a * b; break;
				case '/':
					if (b == 0) {
						std::cerr << "Error" << std::endl;
						return;
					}
					result = a / b;
					break;
			}
			stack.push(result);
		}
	}
	if (stack.size() != 1) {
		std::cerr << "Error" << std::endl;
		return;
	}
	std::cout << stack.top() << std::endl;
}