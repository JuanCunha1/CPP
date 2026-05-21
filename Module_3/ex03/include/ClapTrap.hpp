#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {
public:
    explicit ClapTrap(std::string name);
    ClapTrap(const ClapTrap& other);
    ClapTrap& operator=(const ClapTrap& other);
    virtual ~ClapTrap(void);

    virtual void	attack(const std::string& target);
    virtual void	takeDamage(unsigned int amount);
    virtual void	beRepaired(unsigned int amount);
protected:
	std::string		_name;
    unsigned int	_hitPoints;
    unsigned int	_energyPoints;
    unsigned int	_attackDamage;
};

#endif // CLAPTRAP_HPP
