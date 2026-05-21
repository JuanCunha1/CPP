#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << "\n========== CLAPTRAP TEST ==========\n" << std::endl;

    {
        ClapTrap a("Clappy");

        a.attack("enemy");
        a.takeDamage(5);
        a.beRepaired(3);

        for (int i = 0; i < 10; i++)
            a.attack("target");

        a.attack("last target");
    }

    std::cout << "\n========== SCAVTRAP TEST ==========\n" << std::endl;

    {
        ScavTrap scav("Guardian");

        scav.attack("intruder");
        scav.takeDamage(40);
        scav.beRepaired(20);
        scav.guardGate();

        for (int i = 0; i < 51; i++)
            scav.attack("enemy");
    }

    std::cout << "\n========== FRAGTRAP TEST ==========\n" << std::endl;

    {
        FragTrap frag("Fraggy");

        frag.attack("boss");
        frag.takeDamage(50);
        frag.beRepaired(25);
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
        ScavTrap a("Alpha");
        ScavTrap b("Beta");

        b = a;

        b.attack("assigned target");
    }

    std::cout << "\n========== POLYMORPHISM TEST ==========\n" << std::endl;

    {
        ClapTrap* bot1 = new ScavTrap("ScavPoly");
        ClapTrap* bot2 = new FragTrap("FragPoly");

        bot1->attack("enemy");
        bot2->attack("enemy");

        delete bot1;
        delete bot2;
    }

    std::cout << "\n========== DEATH TEST ==========\n" << std::endl;

    {
        FragTrap dead("DeadFrag");

        dead.takeDamage(200);

        dead.attack("enemy");
        dead.beRepaired(10);
        dead.highFivesGuys();
    }

    return 0;
}
