#include "ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->setHitPoints(100);
	this->setEnergyPoints(50);
	this->setAttackDamage(20);
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other.getName()) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

// Operador de atribuição
ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other.getName();
		_hitPoints = other.getHitPoints();
		_energyPoints = other.getEnergyPoints();
		_attackDamage = other.getAttackDamage();
    }
    return *this;
}

// Destrutor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	std::cout << "Evil ScavTrap " << _name << " go for broke " << target << " causing him " << _attackDamage << " attack damage" << std::endl;
}

void	ScavTrap::guardGate() const {
	std::cout << "Evil ScavTrap " << _name << " enter in protected mode !" << std::endl;
}