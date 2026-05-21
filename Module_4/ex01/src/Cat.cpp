#include "Cat.hpp"

// Construtor padrão
Cat::Cat() : Animal() {
	this->type = "Cat";
	_brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}

// Construtor de cópia
Cat::Cat(const Cat& other) : Animal(other){
	std::cout << "Cat copy constructor called" << std::endl;
	delete this->_brain;
	_brain = new Brain(*other._brain);
}

// Operador de atribuição
Cat& Cat::operator=(const Cat& other) {
	std::cout << "Cat assignment operator called" << std::endl;
	if (this == &other) 
		return *this;
	delete this->_brain;
	this->type = other.type;
	_brain = new Brain(*other._brain);
	return *this;
}

// Destrutor
Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
	delete this->_brain;
}

void Cat::makeSound() const {
	std::cout << "Meow!" << std::endl;
}