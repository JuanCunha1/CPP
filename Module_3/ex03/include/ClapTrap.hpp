#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include <iostream>

class ClapTrap {

protected:
	std::string _name;
	int			_hitPoints;
	int			_energyPoints;
	int			_attackDamage;

public:
	// Orthodox Canonical Form
	ClapTrap();
	ClapTrap(std::string name);
	ClapTrap(const ClapTrap& other);
	ClapTrap& operator=(const ClapTrap& other);
	~ClapTrap();

	void		attack(const std::string& target);
	void		takeDamage(unsigned int amount);
	void		beRepaired(unsigned int amount);

	std::string	getName() const;
	void		setName(const std::string& name);

	int			getHitPoints() const;
	void		setHitPoints(int hitPoints);

	int			getEnergyPoints() const;
	void		setEnergyPoints(int energyPoints);

	int			getAttackDamage() const;
	void		setAttackDamage(int attackDamage);


};

#endif // CLAPTRAP_HPP
