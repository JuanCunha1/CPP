#include "Zombie.hpp"

int main(void) {
	Zombie *horde = zombieHorde(HORDE_NUMBER, "Hordee");
	for (int i = 0; i < HORDE_NUMBER; i++)
		horde[i].announce();
	delete[] horde;
	return (0);
}
