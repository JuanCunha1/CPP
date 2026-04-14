#include "Cat.hpp"

// Construtor padrão
Cat::Cat() : _value(0) {
    std::cout << "Cat default constructor called" << std::endl;
}

// Construtor de cópia
Cat::Cat(const Cat& other) {
    std::cout << "Cat copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
Cat::~Cat() {
    std::cout << "Cat destructor called" << std::endl;
}
