#include "DiamondTrap.hpp"

// Construtor padrão
DiamondTrap::DiamondTrap() : _value(0) {
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

// Construtor de cópia
DiamondTrap::DiamondTrap(const DiamondTrap& other) {
    std::cout << "DiamondTrap copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap destructor called" << std::endl;
}
