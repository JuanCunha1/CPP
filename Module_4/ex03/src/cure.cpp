#include "cure.hpp"

// Construtor padrão
Cure::Cure() : _value(0) {
    std::cout << "Cure default constructor called" << std::endl;
}

// Construtor de cópia
Cure::Cure(const Cure& other) {
    std::cout << "Cure copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
Cure& Cure::operator=(const Cure& other) {
    std::cout << "Cure assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
Cure::~Cure() {
    std::cout << "Cure destructor called" << std::endl;
}
