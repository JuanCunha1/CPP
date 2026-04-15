#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include <iostream>

class DiamondTrap {
public:
    // Orthodox Canonical Form
    DiamondTrap();
    DiamondTrap(const DiamondTrap& other);
    DiamondTrap& operator=(const DiamondTrap& other);
    ~DiamondTrap();

private:
    int _value;
};

#endif // DIAMONDTRAP_HPP
