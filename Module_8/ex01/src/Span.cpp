#include "Span.hpp"

// Constructor padrão
Span::Span() : _N() {
	//std::cout << "Span default constructor called" << std::endl;
}

// Constructor de cópia
Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {
	//std::cout << "Span copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
Span& Span::operator=(const Span& other) {
	//std::cout << "Span assignment operator called" << std::endl;
	if (this != &other) {
		_N = other._N;
		_numbers = other._numbers;
	}
	return *this;
}

// Destructor
Span::~Span() {
	//std::cout << "Span destructor called" << std::endl;
}

Span::Span(unsigned int N) : _N(N) {
	//std::cout << "Span parameterized constructor called" << std::endl;
}

void Span::addNumber(int number) {
	if (_numbers.size() >= _N) {
		throw maxCapacityException();
	}
	_numbers.push_back(number);
}

int Span::shortestSpan() const {
	if (_numbers.size() < 2) {
		throw noSpanFound();
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	int shortest = sortedNumbers.back() - sortedNumbers.front();
	for (size_t i = 1; i < sortedNumbers.size(); ++i) {
		int span = sortedNumbers[i] - sortedNumbers[i - 1];
		if (span < shortest) {
			shortest = span;
		}
	}
	return shortest;
}

int Span::longestSpan() const {
	if (_numbers.size() < 2) {
		throw noSpanFound();
	}
	std::vector<int> sortedNumbers = _numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());
	return sortedNumbers.back() - sortedNumbers.front();
}

const char *Span::maxCapacityException::what() const throw() {
	return "Exceeded size of vector.";
}

const char *Span::noSpanFound ::what() const throw() {
	return "No Span was found.";
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
	if(_N -_numbers.size() < static_cast<unsigned int>(std::distance(begin, end))) {
		throw maxCapacityException();
	}
	_numbers.insert(_numbers.end(), begin, end);
}