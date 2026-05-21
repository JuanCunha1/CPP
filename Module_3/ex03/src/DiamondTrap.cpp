#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(const std::string Name)
    : ClapTrap(Name), FragTrap(Name), ScavTrap(Name) {
  this->_name = Name;
  this->ClapTrap::_name = Name + "_clap_name";
  this->_hitPoints = 100;
  this->_energyPoints = 50;
  this->_attackDamage = 30;
  std::cout << "DiamondTrap Default constructor called\n";
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other._name), FragTrap(other._name), ScavTrap(other._name) {
  this->_name = other._name;
  std::cout << "DiamondTrap Copy constructor called\n";
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
  std::cout << "DiamondTrap Copy assignment operator called\n";
  if (this == &other)
    return *this;
  this->_name = other._name;
  this->ClapTrap::_name = other.ClapTrap::_name;
  this->_hitPoints = other._hitPoints;
  this->_energyPoints = other._energyPoints;
  this->_attackDamage = other._attackDamage;
  return *this;
}

DiamondTrap::~DiamondTrap() {
  std::cout << "DiamondTrap Destructor called\n";
}

void DiamondTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0)
    {
        std::cout << "DiamondTrap " << _name
                  << " is dead" << std::endl;
        return;
    }

    if (_energyPoints <= 0)
    {
        std::cout << "DiamondTrap " << _name
                  << " doesn't have enough energy points!"
                  << std::endl;
        return;
    }

    _energyPoints--;

    std::cout << "DiamondTrap " << _name
              << " attacks " << target
              << ", causing " << _attackDamage
              << " points of damage!"
              << std::endl;
}

void DiamondTrap::takeDamage(unsigned int amount) {
	if (_hitPoints == 0)
	{
		std::cout << "DiamondTrap " << _name << " is already dead" << std::endl;
		return ;
	}
	if (_hitPoints <= amount)
		_hitPoints = 0;
    else
    	_hitPoints -= amount;
    std::cout << "DiamondTrap " << _name << " takes " << amount << " points of damage!" << std::endl;
}

void DiamondTrap::beRepaired(unsigned int amount) {
	if (_hitPoints <= 0)
    {
    	std::cout << "DiamondTrap " << _name << " is dead" << std::endl;
     	return ;
    }
    if (_energyPoints <= 0)
    {
        std::cout << "DiamondTrap " << _name << " doesn't have enough energy points !" << std::endl;
        return ;
    }
    _energyPoints--;
    std::cout << "DiamondTrap " << _name << " is repaired for " << amount << " hit points!" << std::endl;
    _hitPoints += amount;
}

void DiamondTrap::whoAmI() {
	if (_hitPoints <= 0)
    {
        std::cout << "DiamondTrap " << _name
                  << " is dead" << std::endl;
        return;
    }
	std::cout << "WhoAmI?\n I am a DiamondTrap Named " << DiamondTrap::_name
	    << " and my parent ClapTrap name is " << ClapTrap::_name
	    << std::endl;
}
