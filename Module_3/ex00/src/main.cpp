#include "ClapTrap.hpp"

int main() {
    std::cout << "--- Test OCF ---" << std::endl;

    ClapTrap a;
    ClapTrap b(a);
    ClapTrap c;

    c = b;

    return 0;
}
