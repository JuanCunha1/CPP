#include "Dog.hpp"

// Construtor padrão
Dog::Dog() : Animal() {
	this->type = "Dog";
	this->DogBrain = new Brain();
	std::cout << "Dog default constructor called" << std::endl;
}

// Construtor de cópia
Dog::Dog(const Dog& other) : Animal(other) {
	std::cout << "Dog copy constructor called" << std::endl;
	this->type = other.type;
	delete this->DogBrain;
	this->DogBrain = new Brain(*other.DogBrain);
}

// Operador de atribuição
Dog& Dog::operator=(const Dog& other) {
	std::cout << "Dog assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	delete this->DogBrain;
	this->DogBrain = new Brain(*other.DogBrain);
	return *this;
}

// Destrutor
Dog::~Dog() {
	delete this->DogBrain;
	std::cout << "Dog destructor called" << std::endl;
}

void Dog::makeSound() const {
	std::cout << "Woof!" << std::endl;
}
