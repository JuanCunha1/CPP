#include "PmergeMe.hpp"

// Constructor padrão
PmergeMe::PmergeMe() {
	//std::cout << "PmergeMe default constructor called" << std::endl;
}

// Constructor de cópia
PmergeMe::PmergeMe(const PmergeMe& other) {
	//std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	//std::cout << "PmergeMe assignment operator called" << std::endl;
	if (this != &other) {
		
	}
	return *this;
}

// Destructor
PmergeMe::~PmergeMe() {
	//std::cout << "PmergeMe destructor called" << std::endl;
}

PmergeMe::PmergeMe(int size, std::string *input) {
	
}