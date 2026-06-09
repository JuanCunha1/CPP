#include "Dog.hpp"

// Construtor padrão
Dog::Dog() : Animal() {
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

// Construtor de cópia
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = other._type;
}

// Operador de atribuição
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

// Destrutor
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
