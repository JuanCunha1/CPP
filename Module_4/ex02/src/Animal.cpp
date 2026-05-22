#include "Animal.hpp"

// Construtor padrão
Animal::Animal() {
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
}

// Construtor de cópia
Animal::Animal(const Animal& other) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
Animal& Animal::operator=(const Animal& other) {
std::cout << "Animal assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

// Destrutor
Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}


std::string Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
  std::cout
      << "I am a general animal and I don´t make sounds. Implement me somewhere"
      << std::endl;
}