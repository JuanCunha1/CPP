#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
    std::cout << "ClapTrap default constructor called" << std::endl;
}
// Construtor padrão
ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
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
    if (this == &other) 
        return *this;
    this->_name = other._name;
    this->_hitPoints = other._hitPoints;
    this->_energyPoints = other._energyPoints;
    this->_attackDamage = other._attackDamage;
    return *this;
}

// Destrutor
ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
    if (_energyPoints > 0) {
		std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
        _energyPoints --;
	}
	else
		std::cout << "ClapTrap " << _name << " doesn't have enough energy points !" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    _hitPoints -= amount;
    std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    
    if (_energyPoints <= 0) 
    {
        std::cout << "ClapTrap " << _name << " doesn't have enough energy points !" << std::endl;
        return;
    }
    _energyPoints--;
    std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
    _hitPoints += amount;
}
