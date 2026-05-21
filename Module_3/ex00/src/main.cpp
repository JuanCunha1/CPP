#include "ClapTrap.hpp"

int main() {
    {
	    ClapTrap a("A");
	    ClapTrap b("B");
	    a.attack("B");
	    a.takeDamage(5);
	    a.beRepaired(5);
	    for (int i = 0; i < 11; i++)
	            a.attack("enemy");
    }
    {
    	ClapTrap a("A");
	    a.takeDamage(100);   // kill it
	    a.attack("enemy");   // should not work
	    a.beRepaired(10);    // should not work
    }
    {
		ClapTrap a("A");
		ClapTrap b(a);
    }
    {
   		ClapTrap a("A");
        ClapTrap b("B");

        b = a;
    }
    {
        ClapTrap a("A");
        ClapTrap b("B");

        a.attack("B");
        b.takeDamage(0); // or your attack damage

        b.beRepaired(3);
        b.attack("A");
    }
    {
	    ClapTrap a("A");

	    for (int i = 0; i < 5; i++) {
	        a.attack("enemy");
	        a.beRepaired(1);
	    }
    }
    return 0;
}
