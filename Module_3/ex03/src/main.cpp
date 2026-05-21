#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main()
{
	std::cout << "\n========== BASIC DIAMONDTRAP TEST ==========\n" << std::endl;

    {
        DiamondTrap diamond("Diamond");

        diamond.attack("enemy");
        diamond.takeDamage(30);
        diamond.beRepaired(20);

        diamond.whoAmI();
    }

    std::cout << "\n========== ENERGY TEST ==========\n" << std::endl;

    {
        DiamondTrap diamond("EnergyDiamond");

        for (int i = 0; i < 51; i++)
            diamond.attack("target");
    }

    std::cout << "\n========== DEATH TEST ==========\n" << std::endl;

    {
        DiamondTrap diamond("DeadDiamond");

        diamond.takeDamage(200);

        diamond.attack("enemy");
        diamond.beRepaired(10);
        diamond.whoAmI();
    }

    std::cout << "\n========== COPY CONSTRUCTOR TEST ==========\n" << std::endl;

    {
        DiamondTrap original("Original");
        DiamondTrap copy(original);

        copy.attack("copy target");
        copy.whoAmI();
    }

    std::cout << "\n========== ASSIGNMENT OPERATOR TEST ==========\n" << std::endl;

    {
        DiamondTrap a("Alpha");
        DiamondTrap b("Beta");

        b = a;

        b.attack("assigned target");
        b.whoAmI();
    }

    std::cout << "\n========== POLYMORPHISM TEST ==========\n" << std::endl;

    {
        ClapTrap* bot = new DiamondTrap("PolyDiamond");

        bot->attack("enemy");

        delete bot;
    }

    return 0;
}
