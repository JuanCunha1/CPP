#include "Zombie.hpp"

Zombie::~Zombie(void) {
    std::cout << name << " died" << std::endl;
}

void	Zombie::announce(void) {
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::SetName(std::string InputName) {
	name = InputName;
}
