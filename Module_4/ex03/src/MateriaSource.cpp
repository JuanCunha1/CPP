#include "MateriaSource.hpp"

// Construtor padrão
MateriaSource::MateriaSource() : _value(0) {
    std::cout << "MateriaSource default constructor called" << std::endl;
}

// Construtor de cópia
MateriaSource::MateriaSource(const MateriaSource& other) {
    std::cout << "MateriaSource copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
MateriaSource& MateriaSource::operator=(const MateriaSource& other) {
    std::cout << "MateriaSource assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
MateriaSource::~MateriaSource() {
    std::cout << "MateriaSource destructor called" << std::endl;
}
