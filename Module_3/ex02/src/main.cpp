#include "FragTrap.hpp"

int main()
{
    std::cout << "\n========== FRAGTRAP BASIC TEST ==========\n" << std::endl;

    {
        FragTrap frag("Fraggy");

        frag.attack("enemy");
        frag.takeDamage(30);
        frag.beRepaired(20);
        frag.highFivesGuys();
    }

    std::cout << "\n========== ENERGY TEST ==========\n" << std::endl;

    {
        FragTrap frag("EnergyFrag");

        for (int i = 0; i < 101; i++)
            frag.attack("target");
    }

    std::cout << "\n========== DEATH TEST ==========\n" << std::endl;

    {
        FragTrap frag("DeadFrag");

        frag.takeDamage(200);

        frag.attack("enemy");
        frag.beRepaired(10);
        frag.highFivesGuys();
    }

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    {
        FragTrap original("Original");
        FragTrap copy(original);

        copy.attack("copy target");
    }

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    {
        FragTrap a("Alpha");
        FragTrap b("Beta");

        b = a;

        b.attack("assigned target");
    }

    return 0;
}
