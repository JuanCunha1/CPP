#include "HumanB.hpp"

HumanB::HumanB(std::string TypeName) : _name(TypeName) {
}

void	HumanB::attack() {
	std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}

void	HumanB::setWeapon(Weapon TypeClub){
	_weapon = TypeClub;
}
