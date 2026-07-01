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

bool RPN::calculate(char op, int a, int b, int& result)
{
    long long res;

    switch (op)
    {
        case '+':
            res = static_cast<long long>(a) + b;
            break;
        case '-':
            res = static_cast<long long>(a) - b;
            break;
        case '*':
            res = static_cast<long long>(a) * b;
            break;
        case '/':
            if (b == 0)
                return false;
            res = a / b;
            break;
        default:
            return false;
    }

    if (res > INT_MAX || res < INT_MIN)
        return false;

    result = static_cast<int>(res);
    return true;
}

void RPN::evaluate(const std::string& expression) {
	std::stack<int> stack;
	std::stringstream ss(expression);
	std::string token;
	const std::string operators = "+-*/";
	while (ss >> token)
	{
		if (token.size() == 1 && std::isdigit(token[0]))
			stack.push(token[0] - '0');
		else if (token.size() == 1 &&
				operators.find(token[0]) != std::string::npos) {
			if (stack.size() < 2)
				throw InvalidException();
			int b = stack.top();
            stack.pop();
            int a = stack.top();
            stack.pop();

            int result;
            if (!calculate(token[0], a, b, result))
                throw InvalidException();
			stack.push(result);
		}
		else
			throw InvalidException();
	}
	if (stack.size() != 1) {
		throw InvalidException();
	}
	std::cout << stack.top() << std::endl;
}
const char *RPN::InvalidException::what() const throw() {
	return "Error";
}