#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

class DiamondTrap : public ScavTrap, public FragTrap {
public:
    // Orthodox Canonical Form
    DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

private:
    
};

#endif // DIAMONDTRAP_HPP
