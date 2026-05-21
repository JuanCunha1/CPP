#include "Dog.hpp"

// Construtor padrão
Dog::Dog() : Animal() {
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	_brain = Brain();
}

// Construtor de cópia
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	_brain = other._brain;

}

// Operador de atribuição
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	_brain = other._brain;
	return *this;
}

// Destrutor
Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
	delete &_brain;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
