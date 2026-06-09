#include "test.hpp"

// Constructor padrão
Test::Test() : _value(0) {
    std::cout << "Test default constructor called" << std::endl;
}

// Constructor de cópia
Test::Test(const Test& other) {
    std::cout << "Test copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
Test& Test::operator=(const Test& other) {
    std::cout << "Test assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destructor
Test::~Test() {
    std::cout << "Test destructor called" << std::endl;
}
