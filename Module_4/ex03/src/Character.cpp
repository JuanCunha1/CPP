#include "Character.hpp"

// Construtor padrão
Character::Character() : _value(0) {
    std::cout << "Character default constructor called" << std::endl;
}

// Construtor de cópia
Character::Character(const Character& other) {
    std::cout << "Character copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
Character& Character::operator=(const Character& other) {
    std::cout << "Character assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
Character::~Character() {
    std::cout << "Character destructor called" << std::endl;
}
