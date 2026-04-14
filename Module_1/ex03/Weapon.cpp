#include "Weapon.hpp"

Weapon::Weapon() {
}

Weapon::Weapon(const std::string &type) {
	_type = type;
}

void	Weapon::setType(const std::string &type) {
	_type = type;
}

std::string	Weapon::getType(void) const {
	return (_type);
}
