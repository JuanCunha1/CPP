#include "ScavTrap.hpp"

// default constructor
ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

// copy constructor
ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other._name) {
    std::cout << "ScavTrap copy constructor called" << std::endl;
    *this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
    std::cout << "ScavTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
    }
    return *this;
}

// Destructor
ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap destructor called" << std::endl;
}

void	ScavTrap::attack(const std::string &target) {
	if (_hitPoints <= 0)
    {
    	std::cout << "ScavTrap " << _name << " is dead" << std::endl;
    }
    else if (_energyPoints > 0) {
    	std::cout << "Evil ScavTrap " << _name << " go for broke " << target << " causing him " << _attackDamage << " attack damage" << std::endl;
        _energyPoints --;
	}
	else
		std::cout << "ScavTrap " << _name << " doesn't have enough energy points !" << std::endl;
}

void ScavTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0)
	{
		std::cout << "ScavTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	if (_hitPoints <= amount)
		_hitPoints = 0;
    else
    	_hitPoints -= amount;
    std::cout << "ScavTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void ScavTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
    {
    	std::cout << "ScavTrap " << _name << " is dead" << std::endl;
     	return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "ScavTrap " << _name << " doesn't have enough energy points !" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "ScavTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
    _hitPoints += amount;
}

void	ScavTrap::guardGate() const {
 	if (_hitPoints <= 0)
    {
        std::cout << "ScavTrap " << _name
                  << " is dead" << std::endl;
        return;
    }
	std::cout << "Evil ScavTrap " << _name << " enter in protected mode !" << std::endl;
}
