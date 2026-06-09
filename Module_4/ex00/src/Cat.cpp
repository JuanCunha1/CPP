#include "Cat.hpp"

// Construtor padrão
Cat::Cat() : Animal() {
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}

// Construtor de cópia
Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
}

// Operador de atribuição
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->_type = other._type;
	return *this;
}

// Destrutor
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}
