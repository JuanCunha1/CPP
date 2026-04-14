#include "Dog.hpp"

// Construtor padrão
Dog::Dog() : _value(0) {
    std::cout << "Dog default constructor called" << std::endl;
}

// Construtor de cópia
Dog::Dog(const Dog& other) {
    std::cout << "Dog copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
Dog::~Dog() {
    std::cout << "Dog destructor called" << std::endl;
}
