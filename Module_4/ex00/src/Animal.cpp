#include "Animal.hpp"

// Construtor padrão
Animal::Animal() : _value(0) {
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
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
Animal::~Animal() {
    std::cout << "Animal destructor called" << std::endl;
}
