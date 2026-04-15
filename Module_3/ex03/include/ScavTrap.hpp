#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
private:

public:
	// Orthodox Canonical Form
	ScavTrap(std::string name);
	ScavTrap(const ScavTrap& other);
	ScavTrap& operator=(const ScavTrap& other);
	~ScavTrap();
	void	attack(const std::string &target);
	void	guardGate() const;

};

#endif // SCAVTRAP_HPP
