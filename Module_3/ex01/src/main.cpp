#include "ClapTrap.hpp"

int main() {
    std::cout << "--- Test Orthodox Canonical Form ---" << std::endl;

    ClapTrap a;
    ClapTrap b(a);
    ClapTrap c;

    c = b;

    return 0;
}
