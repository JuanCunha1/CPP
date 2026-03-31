#include "Zombie.hpp"

Zombie::Zombie(const std::string inputname) {
	name = inputname;
}

Zombie::~Zombie(void) {
	std::cout << name << " died" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
