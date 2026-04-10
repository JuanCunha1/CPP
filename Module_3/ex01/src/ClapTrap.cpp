#include "ClapTrap.hpp"

// Construtor padrão
ClapTrap::ClapTrap() : _value(0) {
    std::cout << "ClapTrap default constructor called" << std::endl;
}

// Construtor de cópia
ClapTrap::ClapTrap(const ClapTrap& other) {
    std::cout << "ClapTrap copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    std::cout << "ClapTrap assignment operator called" << std::endl;
    if (this != &other) {
        this->_value = other._value;
    }
    return *this;
}

// Destrutor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}
