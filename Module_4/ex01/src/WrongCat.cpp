#include "WrongCat.hpp"

// Construtor padrão
WrongCat::WrongCat() : WrongAnimal() {
	this->type = "WrongCat";
	std::cout << "WrongCat  default constructor called" << std::endl;
}

// Construtor de cópia
WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other){
	std::cout << "WrongCat copy constructor called" << std::endl;
	this->type = other.type;
}

// Operador de atribuição
WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if (this == &other) 
		return *this;
	this->type = other.type;
	return *this;
}

// Destrutor
WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called" << std::endl;
}

void WrongCat::makeSound() const {
	std::cout << "WrongCat says: Meow!" << std::endl;
}