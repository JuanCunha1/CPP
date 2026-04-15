#include "FragTrap.hpp"

// Construtor padrão
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(100);
	this->setAttackDamage(30);
    std::cout << "FragTrap default constructor called" << std::endl;
}

// Construtor de cópia
FragTrap::FragTrap(const FragTrap& other) {
    std::cout << "FragTrap copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
    }
    return *this;
}
// Destrutor
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap::highFivesGuys(void) {
    std::cout << "FragTrap " << _name << " is asking for a high five!" << std::endl;
}
