#include "ice.hpp"

// Construtor padrão
Ice::Ice() : _value(0) {
    std::cout << "Ice default constructor called" << std::endl;
}

// Construtor de cópia
Ice::Ice(const Ice& other) {
    std::cout << "Ice copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
Ice& Ice::operator=(const Ice& other) {
    std::cout << "Ice assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
Ice::~Ice() {
    std::cout << "Ice destructor called" << std::endl;
}
