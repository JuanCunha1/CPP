#include "FragTrap.hpp"

// Construtor padrão
FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	this->_attackDamage = 30;
    std::cout << "FragTrap constructor called" << std::endl;
}

// Construtor de cópia
FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other){
    std::cout << "FragTrap copy constructor called" << std::endl;
}

// Operador de atribuição
FragTrap& FragTrap::operator=(const FragTrap& other) {
    std::cout << "FragTrap assignment operator called" << std::endl;
    if (this != &other) {
        _name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
    }
    return *this;
}
// Destructor
FragTrap::~FragTrap() {
    std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void) {
 	if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name
                  << " is dead" << std::endl;
        return;
    }
    std::cout << "FragTrap " << _name << " is asking for a high five!" << std::endl;
}

void FragTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "FragTrap " << _name
                  << " is dead" << std::endl;
        return;
    }

    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name
                  << " doesn't have enough energy points!"
                  << std::endl;
        return;
    }

    _energyPoints--;

    std::cout << "FragTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!"
              << std::endl;
}

void FragTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0)
	{
		std::cout << "FragTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	if (_hitPoints <= amount)
		_hitPoints = 0;
    else
    	_hitPoints -= amount;
    std::cout << "FragTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void FragTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
    {
    	std::cout << "FragTrap " << _name << " is dead" << std::endl;
     	return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "FragTrap " << _name << " doesn't have enough energy points !" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "FragTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
    _hitPoints += amount;
}
