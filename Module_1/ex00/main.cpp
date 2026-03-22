#include "Zombie.hpp"

int main(void) {
    Zombie *Zombie1 = newZombie("Zombienn");
    Zombie1->announce();
    randomChump("me mario");
    delete Zombie1;
	return (0);
}