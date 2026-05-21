#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	this->type = "WrongAnimal";
	std::cout << "Wrong Animal default constructor called" << std::endl;
}

// Construtor de cópia
WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Wrong Animal copy constructor called" << std::endl;
	*this = other;
}

// Operador de atribuição
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
std::cout << "Wrong Animal assignment operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

// Destrutor
WrongAnimal::~WrongAnimal() {
	std::cout << "Wrong Animal destructor called" << std::endl;
}


std::string WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const {
  std::cout
      << "I am a general animal and I don´t make sounds. Implement me somewhere"
      << std::endl;
}