#include "ScavTrap.hpp"
int main()
{
    {
        std::cout << "===== BASIC TEST =====" << std::endl;

        ScavTrap scav("SC4V-TP");

        scav.attack("target");
        scav.takeDamage(30);
        scav.beRepaired(20);
        scav.guardGate();
    }

    std::cout << std::endl;

    {
        std::cout << "===== ENERGY TEST =====" << std::endl;

        ScavTrap scav("EnergyBot");

        for (int i = 0; i < 51; i++)
            scav.attack("enemy");
    }

    std::cout << std::endl;

    {
        std::cout << "===== DEATH TEST =====" << std::endl;

        ScavTrap scav("DeadBot");

        scav.takeDamage(200);

        scav.attack("enemy");
        scav.beRepaired(10);
        scav.guardGate();
    }

    std::cout << std::endl;

    {
        std::cout << "===== COPY CONSTRUCTOR TEST =====" << std::endl;

        ScavTrap a("Original");
        ScavTrap b(a);

        b.attack("enemy");
    }

    std::cout << std::endl;

    {
        std::cout << "===== ASSIGNMENT OPERATOR TEST =====" << std::endl;

        ScavTrap a("Alpha");
        ScavTrap b("Beta");

        b = a;

        b.attack("enemy");
    }

    std::cout << std::endl;

    {
        std::cout << "===== POLYMORPHISM TEST =====" << std::endl;

        ClapTrap* bot = new ScavTrap("Guardian");

        bot->attack("target");

        delete bot;
    }

    return 0;
}
