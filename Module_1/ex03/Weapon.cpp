#include "Weapon.hpp"

Weapon::Weapon(const std::string &type) {
	_type = type;
}

void	Weapon::setType(const std::string &type) {
	_type = type;
}

std::string	Weapon::getType(void) {
	return (_type);
}