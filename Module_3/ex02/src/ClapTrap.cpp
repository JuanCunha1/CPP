#include "ClapTrap.hpp"

ClapTrap::ClapTrap() {
	std::cout << "ClapTrap default constructor called" << std::endl;
}
// Construtor padrão

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {
	std::cout << "ClapTrap " << _name << " constructor called" << std::endl;
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
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	return *this;
}

// Destrutor
ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target) {
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _attackDamage << " points of damage!" << std::endl;
	_energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	_hitPoints += amount;
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
}
std::string ClapTrap::getName() const {
	return _name;
}

void ClapTrap::setName(const std::string& name) {
	_name = name;
}

int ClapTrap::getHitPoints() const {
	return _hitPoints;
}

void ClapTrap::setHitPoints(int hitPoints) {
	if(hitPoints <= 0)
		hitPoints = 1;
	_hitPoints = hitPoints;
}

int ClapTrap::getEnergyPoints() const {
	return _energyPoints;
}

void ClapTrap::setEnergyPoints(int energyPoints) {
	if (energyPoints < 0)
		energyPoints = 0;
	_energyPoints = energyPoints;
}

int ClapTrap::getAttackDamage() const {
	return _attackDamage;
}

void ClapTrap::setAttackDamage(int attackDamage) {
	if (attackDamage < 0)
		attackDamage = 0;
	_attackDamage = attackDamage;
}


