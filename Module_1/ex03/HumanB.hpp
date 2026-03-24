#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include <string>
# include "Weapon.hpp"

class HumanB {
private:
	Weapon		*_weapon;
	std::string	_name;

public:
	HumanB(std::string TypeName);

	void	setWeapon(Weapon &TypeClub);
	void	attack();
};

#endif