#include "AMateria.hpp"

// Construtor padrão
AMateria::AMateria() : _value(0) {
    std::cout << "AMateria default constructor called" << std::endl;
}

// Construtor de cópia
AMateria::AMateria(const AMateria& other) {
    std::cout << "AMateria copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
AMateria& AMateria::operator=(const AMateria& other) {
    std::cout << "AMateria assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
AMateria::~AMateria() {
    std::cout << "AMateria destructor called" << std::endl;
}
